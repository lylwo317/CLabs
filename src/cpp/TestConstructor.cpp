#include <iostream>
#include <cstring>
using namespace std;

/*
没有定义构造函数
*/
class PersonA
{
public:
    int age;
};

/*
没有定义构造函数
*/
class PersonB
{
public:
    int age = 5;
};

/*
有构造函数
*/
class PersonC
{
public:
	int age;
	PersonC() {
		memset(this, 0, sizeof(PersonC));
	}
};

class Car
{
public:
	int color;
	Car() {
		memset(this, 0, sizeof(Car));
	}
};

/*
* 对于自定义类
* 两种方式解决成员变量初始化的问题：
* 1.
直接对成员变量设置初始值，类似PersonB。但是必须每个成员都设置相应的初始值，否则没设置初始值的成员的在某些写法下是不会初始化的，例如局部变量
* 2. 直接定义默认构造函数，类似PersonC。可以先memset，然后再对某些成员设定非0值
*
* 对于原始类型的new的操作
* 必须使用（），否者不会初始化int a = new int()
* 自定义 
*
* 默认构造函数的生成规则（核心是有事情要做）
* 1. 成员变量 = 0。也就是在声明的地方初始化了成员变量，new完之后要再默认构造函数初始化
* 2. 虚函数。也就是说在对象创建的时候，需要把虚表地址放到对象存储区域的头部
* 3. 父类有默认构造函数。
* ...其它情况有待补充
* 
* 为了能在局部变量或者new的时候都能初始化类的成员，必须要自己定义默认构造函数，否则就会出现没有初始化的情况。
* 如果只是需要初始化为0，可以直接在构造函数中调用memset来初始化
*/
int testConstructor()
{
	//没有生成构造函数，不会初始化
	PersonA personA1;
	personA1.age = 0;
	//这个是函数声明
	PersonA personA2();

	//没有生成构造函数，不会初始化
	PersonA* personA3 = new PersonA;
	//初始化为0（使用memset初始化），并没有生成所谓的默认构造函数
	PersonA* personA4 = new PersonA();

	//综合A1和A3可以看到，不加（）就不会初始化

	delete personA3;
	delete personA4;

	//age = 5；导致生成了默认构造函数. 会调用默认构造函数PersonB::PresonB()。
	//其实也能理解。age = 5。这个总是要用地方去做的，new只是分配内存，所以就由生成的构造函数做age = 5
	PersonB personB1;
	/*
	00007FF7EFB85E35  lea         rcx,[rsp+54h]  //将personB1的地址存储到rcx，其实就是将this传到默认构造函数
	00007FF7EFB85E3A  call        00007FF7EFB812DF //调用默认构造函数
	*/
	//这个是函数声明
	PersonB personB2();

	//与B1一样，调用默认构造函数
	//综合A1和B3可以看到，不加（）的时候，如果没有显示或者隐式的触发默认构造函数定义，就不会调用构造函数初始化
	PersonB* personB3 = new PersonB;
	/*
	00007FF6BF2E5E3F  mov         ecx,4
	00007FF6BF2E5E44  call        operator new (07FF6BF2E101Eh)
	00007FF6BF2E5E49  mov         qword ptr [rsp+0A8h],rax
	00007FF6BF2E5E51  cmp         qword ptr [rsp+0A8h],0
	00007FF6BF2E5E5A  je          main+123h (07FF6BF2E5E73h)
	00007FF6BF2E5E5C  mov         rcx,qword ptr [rsp+0A8h]
	00007FF6BF2E5E64  call        07FF6BF2E12DFh //调用默认构造函数
	00007FF6BF2E5E69  mov         qword ptr [rsp+0F8h],rax
	00007FF6BF2E5E71  jmp         main+12Fh (07FF6BF2E5E7Fh)
	00007FF6BF2E5E73  mov         qword ptr [rsp+0F8h],0
	00007FF6BF2E5E7F  mov         rax,qword ptr [rsp+0F8h]
	00007FF6BF2E5E87  mov         qword ptr [personB3],rax
	*/

	//先memset，然后再调用默认构造函数
	PersonB* personB4 = new PersonB();
	/*
	00007FF6B94C5E8C  mov         ecx,4  
	00007FF6B94C5E91  call        operator new (07FF6B94C101Eh)  
	00007FF6B94C5E96  mov         qword ptr [rsp+0B0h],rax  
	00007FF6B94C5E9E  cmp         qword ptr [rsp+0B0h],0  
	00007FF6B94C5EA7  je          main+181h (07FF6B94C5ED1h)  
	00007FF6B94C5EA9  mov         rdi,qword ptr [rsp+0B0h]  
	00007FF6B94C5EB1  xor         eax,eax  
	00007FF6B94C5EB3  mov         ecx,4  
	00007FF6B94C5EB8  rep stos    byte ptr [rdi]  
	00007FF6B94C5EBA  mov         rcx,qword ptr [rsp+0B0h]  
	00007FF6B94C5EC2  call        std::endl<char,std::char_traits<char> > (07FF6B94C12DFh)  
	00007FF6B94C5EC7  mov         qword ptr [rsp+100h],rax  
	00007FF6B94C5ECF  jmp         main+18Dh (07FF6B94C5EDDh)  
	00007FF6B94C5ED1  mov         qword ptr [rsp+100h],0  
	00007FF6B94C5EDD  mov         rax,qword ptr [rsp+100h]  
	00007FF6B94C5EE5  mov         qword ptr [personB4],rax  
	*/


	delete personB3;
	delete personB4;


	//调用构造函数
	PersonC personC1;
	personC1.age = 0;
	//这个是函数声明
	PersonC personC2();

	//调用构造函数
	PersonC* personC3 = new PersonC;
	//调用构造函数，由于用户定义了默认构造函数，所以这里不会memset
	PersonC* personC4 = new PersonC();

	delete personC3;
	delete personC4;



	//没有初始化
    int *p10 = new int;
	/*
	00007FF72E24163D  mov         ecx,4 // ecx = 4;
	00007FF72E241642  call        operator new (07FF72E24101Eh) //调用new函数。 operator new(4)
	00007FF72E241647  mov         qword ptr [rsp+68h],rax //将new函数的返回值rax，存储到地址是[rsp+68h]的内存中，并且占用8个字节。这里[rsp+68h]就是申请到的内存的指针
	00007FF72E24164C  mov         rax,qword ptr [rsp+68h] 
	00007FF72E241651  mov         qword ptr [p10],rax // [rsp+58h], rax p10 = rax
	*/

    //初始化为0（使用memset初始化）
    int *p11 = new int();
	/*
	00007FF72E241656  mov         qword ptr [rsp+70h],4 //4表示的是int的长度
	00007FF72E24165F  mov         rcx,qword ptr [rsp+70h] //传递给new的参数，也就是获取size是4（byte）的堆内存
	00007FF72E241664  call        operator new (07FF72E24101Eh) //调用new函数。 operator new(4)
	00007FF72E241669  mov         qword ptr [rsp+78h],rax //将new函数的返回值rax，存储到地址是[rsp+78h]的内存中，并且占用8个字节。这里[rsp+78h]就是申请到的内存的指针
	00007FF72E24166E  cmp         qword ptr [rsp+78h],0 //cmp(p11,0)
	00007FF72E241674  je          main+0D3h (07FF72E241693h)// 如果 [rsp+78h] == 0（说明申请堆内存失败了），就跳转到07FF72E241693h
	00007FF72E241676  mov         rdi,qword ptr [rsp+78h] //rdi = [rsp+78h];
	00007FF72E24167B  xor         eax,eax // eax = 0
	00007FF72E24167D  mov         rcx,qword ptr [rsp+70h] //rcx = 4;
	00007FF72E241682  rep stos    byte ptr [rdi] //rdi指向的内存（p11指针指向的堆），填充rcx个bytes 在 rdi指向的内存中 用 al。这里就是memset
	00007FF72E241684  mov         rax,qword ptr [rsp+78h] //rax = [rsp+78h];
	00007FF72E241689  mov         qword ptr [rsp+90h],rax //[rsp+90h] = rax
	00007FF72E241691  jmp         main+0DFh (07FF72E24169Fh) //跳转到
	00007FF72E241693  mov         qword ptr [rsp+90h],0 //[rsp+90h] = 0
	00007FF72E24169F  mov         rax,qword ptr [rsp+90h] // rax = [rsp+90h]
	00007FF72E2416A7  mov         qword ptr [p11],rax // [rsp+60h],rax p11 = rax 到这里p11才真正拿到地址，前面都是存在临时变量[rsp+78h]中
	*/

    delete p10;
    delete p11;

	return 0;
}


class A
{
public:
	int age = 0;
	int height = 0;
	A();
	void display();
	~A();

private:

};

A::A()
{
}

void A::display()
{
	cout << "age = " << age << endl;
	cout << "height = " << height << endl;
}

A::~A()
{
}



void testCopyConstructor() {

	A a = A();
	a.age = 100;
	a.height = 23;

	//会调用拷贝构造函数。 利用旧的对象创建新对象的时候才会调用拷贝构造
	A a1 = A(a);
	A a2 = a1;

	//这里只有拷贝
	A a3 = a2;

	a1.display();
	a2.display();
	a3.display();

}


int main(int argc, char const* argv[]) {
	//testConstructor();
	testCopyConstructor();
	return 0;
}
