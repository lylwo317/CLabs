//
// Created by kevin on 2021/6/14.
//
#include <iostream>
#include <memory>
//#define INSIGHTS_USE_TEMPLATE

using namespace std;

class Car;

class Person {
	int m_age = 0;
public:
    shared_ptr<Car> m_car;
	Person() {
		cout << "Person()" << endl;
	}
	Person(int age) :m_age(age) {
		cout << "Person(int)" << endl;
	}
	~Person() {
		cout << "~Person()" << endl;
	}
	void run() {
		cout << "run() - " << m_age << endl;
	}
};


class Car {
public:
    weak_ptr<Person> m_person;//通过弱引用解决循环引用问题
    Car() {
        cout << "Car()" << endl;
    }
    ~Car() {
        cout << "~Car()" << endl;
    }
};

/* First instantiated from: insights.cpp:227 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
    class auto_ptr<Person>
    {

      private:
      Person * _M_ptr;

      public:
      using element_type = Person;
      inline explicit auto_ptr(element_type * __p)
      : _M_ptr{__p}
      {
      }

      inline auto_ptr(auto_ptr<Person> & __a);

      template<typename _Tp1>
      inline auto_ptr(auto_ptr<_Tp1> & __a);

      inline auto_ptr<Person> & operator=(auto_ptr<Person> & __a);

      template<typename _Tp1>
      inline auto_ptr<Person> & operator=(auto_ptr<_Tp1> & __a);
      inline ~auto_ptr() noexcept
      {
        delete this->_M_ptr;
      }

      inline element_type & operator*() const;

      inline element_type * operator->() const;

      inline element_type * get() const;

      inline element_type * release();

      inline void reset(element_type * __p);

      inline auto_ptr(std::auto_ptr_ref<Person> __ref);

      inline auto_ptr<Person> & operator=(std::auto_ptr_ref<Person> __ref);

    };

#endif


/**
 * 不能共享
 */
void testAutoPointer(){
    auto_ptr<Person> p(new Person);
}

void testSharedPointer(){
    shared_ptr<Person> p(new Person);
    // shared_ptr<Person[]> pArray(new Person[3]);
    shared_ptr<Person> p2 = p;//拷贝，引用计数+1
}
void testUniquePointer(){
    unique_ptr<Person> p(new Person);
    unique_ptr<Person[]> pArray(new Person[3]);
    unique_ptr<Person> p2(std::move(p));//转移

}

void testRecycleReference(){
    //通过弱引用解决
    shared_ptr<Person> person(new Person());
    shared_ptr<Car> car(new Car());

    person->m_car = car;
    car->m_person = person;
}

int main()
{
//    testAutoPointer();
//    testSharedPointer();
//    testUniquePointer();
    testRecycleReference();
    return 0;
}