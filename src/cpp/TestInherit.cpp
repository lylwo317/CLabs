#include <iostream>
using namespace std;

class Person {
public:
	int age;
};

//��ļ̳з�ʽ��Ĭ����private������ƽ����������������public��������������Ϊ�̳е�Ȩ�޸���±�
//�������Ĺ��캯����Ĭ�ϵ���Ĭ�ϵĹ��캯��
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
		//û�е��ø���Ĭ�Ϲ��캯��
		//��ʽ����Animal()������ǳ�ʼ���б����ʽ���������Ĭ�Ϲ��캯��Ҳ�����ȱ����õ�
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
		//:AnimalB() {//��Ҫ��ʾAnimalB()�Ż��ʼ��AnimalB
		//Ĭ��û�е��ø���Ĭ�Ϲ��캯��
		m_life = 0;
		cout << "DogB::Dog()" << endl;
		cout << "DogB::age = " << age << endl;
	}
};


class AnimalC {
public:
	int age = 5;
};

//���ڸ��������Ĭ�Ϲ��캯������������Ҳ���������
class DogC : public AnimalC {
public:
	int m_life;

};

//��������ʽ�����¹��캯�����ɵģ�����Ҳ�����ɹ��캯����
//���ඨ���˹��캯�����������û����ʽ����Ĭ�ϻ�����ʾ����Ĭ�Ϲ��캯���Ļ��������ǲ����ʼ�����ࡣ�������������ʾ���ø���Ĭ�Ϲ��캯��������ʼ������
//����������û��Ĭ�Ϲ��캯�������඼��ʾ���ã������Ϳ��Ա��⸸��û�г�ʼ�������
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
