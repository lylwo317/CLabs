#include <iostream>
using namespace std;

class Person
{
public:
    int age;
    Person(){

    }
};

int main(int argc, char const *argv[])
{
    Person person1;//not call Person::Person()
    cout << person1.age << endl;
    Person person2;
    cout << person2.age << endl;

    int *p10 = new int;
    //初始化为0
    int *p11 = new int();

    delete p10;
    delete p11;
}
