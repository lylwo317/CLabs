#include <iostream>
using namespace std;

class Person {
public:
	int m_age;
	int m_height;

	Person(int age, int height) {
		m_age = age;
		m_height = height;
	}
	/*
	00007FF6C3B31B70  mov         dword ptr [rsp+18h],r8d  
	00007FF6C3B31B75  mov         dword ptr [rsp+10h],edx  
	00007FF6C3B31B79  mov         qword ptr [rsp+8],rcx  
	00007FF6C3B31B7E  push        rdi  
		10: 		m_age = age;
	00007FF6C3B31B7F  mov         rax,qword ptr [rsp+10h]  
	00007FF6C3B31B84  mov         ecx,dword ptr [rsp+18h]  
	00007FF6C3B31B88  mov         dword ptr [rax],ecx  
		11: 		m_height = height;
	00007FF6C3B31B8A  mov         rax,qword ptr [rsp+10h]  
	00007FF6C3B31B8F  mov         ecx,dword ptr [rsp+20h]  
	00007FF6C3B31B93  mov         dword ptr [rax+4],ecx
	*/

	/*
	* 初始化列表就是个语法糖，与上面的写法是一致的。但是成员变量的初始化顺序是 按照成员声明的顺序的！！！
	*/
	//Person(int age, int height) : m_age(age), m_height(height) {
	//}
	/*
	00007FF79E501B70  mov         dword ptr [age],r8d //这里是age参数的值 
	00007FF79E501B75  mov         dword ptr [this],edx  //这里是this参数的值
	00007FF79E501B79  mov         qword ptr [rsp+8],rcx 
	00007FF79E501B7E  push        rdi  

	00007FF79E501B7F  mov         rax,qword ptr [this]  
	00007FF79E501B84  mov         ecx,dword ptr [age]  
	00007FF79E501B88  mov         dword ptr [rax],ecx 

	00007FF79E501B8A  mov         rax,qword ptr [this]  
	00007FF79E501B8F  mov         ecx,dword ptr [height]  
	00007FF79E501B93  mov         dword ptr [rax+4],ecx  
	*/
};

int main(int argc, char const* argv[])
{

	Person p(18,178);
	
	return 0;
}
