#include <iostream>
using namespace std;

class Animal {
public:
	virtual void speak() = 0;//����java�ĳ�������߽ӿ�
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
* 1. �������麯����ʱ��������Ҫ�еط�������ַ��ֵ����Ķ������Ա�����������Ĭ�Ϲ��캯��������Ĭ�Ϲ��캯���н�����ַ��ֵ������ͷ����8���ֽ�
* 2. ������������Ҫ����Ϊ�麯������Ȼ����̳к󣬸���ָ��ָ����������ʱ�򣬾ͻ�ֱ�ӵ��ø�������������������ǵ����������������
* 3. ���麯����virtual = 0����û��ʵ�ֵĺ��������д��麯�������ǳ����࣬����ʵ����
*/
int main(int argc, char const* argv[])
{
	//Animal* a = new Dog();
	//a->speak();
	//a->run();
	liu(new Dog);//ֱ�ӻ���
	liu(new Cat);

	return 0;
}