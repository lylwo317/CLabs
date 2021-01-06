#include <iostream>
using namespace std;

class Person {
public:
	int age;
};

//类的继承方式，默认是private，但是平常开发建议声明成public，这样，不会因为继承的权限搞得懵逼
//如果子类的构造函数会默认调用默认的构造函数
class Student : public Person{
	int m_score;
public:
	Student(int score) {
		m_score = score;
	}
	void say() {
		age;
	}
};

class GoodStudent : public Student {
	int m_shenfen;

public:
	//GoodStudent(int senfen, int score): m_shenfen(senfen),Student(score) {
	//}
	GoodStudent(int senfen, int score): Student(score),m_shenfen(senfen) {
	}

	void talk() {
		age;
	}
};

class AnimalA {
public:
	int age;

};

class DogA : public AnimalA {
	int m_life;
public:
	DogA(int life) {
		//没有调用父类默认构造函数
		//隐式调用Animal()，如果是初始化列表的形式声明，这个默认构造函数也是最先被调用的
		m_life = life;
		cout << "DogA::DogA()" << endl;
		cout << "DogA::age = " << age << endl;
	}
};

class AnimalB {
public:
	int age;
};

class DogB : public AnimalB {
	int m_life;
public:
	DogB(){
		//:AnimalB() {//需要显示AnimalB()才会初始化AnimalB
		//默认没有调用父类默认构造函数
		m_life = 0;
		cout << "DogB::Dog()" << endl;
		cout << "DogB::age = " << age << endl;
	}
};


class AnimalC {
public:
	int age = 5;
};

//由于父类会生成默认构造函数，所以子类也会跟着生成
class DogC : public AnimalC {
public:
	int m_life;

};

//父类有隐式规则导致构造函数生成的，子类也会生成构造函数。
//子类定义了构造函数，如果父类没有隐式定义默认或者显示定义默认构造函数的话，子类是不会初始化父类。但是子类如果显示调用父类默认构造函数，则会初始化父类
//父类无论有没有默认构造函数，子类都显示调用，这样就可以避免父类没有初始化的情况
int main(int argc, char const* argv[])
{

	DogA *dogA = new DogA(20);
	DogB *dogB = new DogB();
	DogC *dogC = new DogC();
	cout << "dogc age " << dogC->age;
	cout << "dogc life " << dogC->m_life;


	delete dogA;
	delete dogB;
	delete dogC;
	return 0;
}
