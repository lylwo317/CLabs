#include <iostream>
using namespace std;

class Animal {
public:
	virtual void speak() = 0;//类似java的抽象类或者接口
	virtual void run() = 0;
	virtual ~Animal() {

	}
};

class Dog : public Animal {
public:
	Dog() {
		cout << "Dog::Dog()" << endl;
	}
	void speak() {
		cout << "Dog::speak()" << endl;
	}

	void run() {
		cout << "Dog::run()" << endl;
	}
	
};

void liu(Animal* a) {
	a->speak();
	a->run();
}

class Cat : public Animal {
public:
	void speak() {
		cout << "Cat::speak()" << endl;
	}

	void run() {
		cout << "Cat::run()" << endl;
	}
	
};

/*
* 1. 当存在虚函数的时候，由于需要有地方将虚表地址赋值给类的对象，所以编译器会生成默认构造函数。并在默认构造函数中将虚表地址赋值给对象头部的8个字节
* 2. 析构函数必须要设置为虚函数。不然子类继承后，父类指针指向子类对象的时候，就会直接调用父类的析构函数，而不是调用子类的析构函数
* 3. 纯虚函数（virtual = 0），没有实现的函数。含有纯虚函数的类是抽象类，不能实例化
*/
int main(int argc, char const* argv[])
{
	//Animal* a = new Dog();
	//a->speak();
	//a->run();
	liu(new Dog);//直接会在
	liu(new Cat);

	return 0;
}