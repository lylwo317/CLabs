#include "student.h"
#include <iostream>

Student::Student(std::string _name):name(_name)
{
    std::cout << "new String()" << std::endl;
    std::cout << "Student()" << std::endl;
}

Student::~Student()
{
//    if (name != nullptr) {
//        delete name;
//        std::cout << "delete String()" << std::endl;
//    }
    std::cout << "~Student()" << std::endl;
}

std::string Student::getName() const
{
    return name;
}

void Student::setName(std::string name)
{
    Student::name = name;
}

int Student::getAge() const
{
    return age;
}

void Student::setAge(int age)
{
    Student::age = age;
}

bool Student::operator==(const Student &rhs) const
{
    return name == rhs.name &&
           age == rhs.age;
}

bool Student::operator!=(const Student &rhs) const
{
    return !(rhs == *this);
}

bool Student::operator<(const Student &rhs) const
{
    if (name < rhs.name) {
        return true;
    }
    if (rhs.name < name) {
        return false;
    }
    return age < rhs.age;
}

bool Student::operator>(const Student &rhs) const
{
    return rhs < *this;
}

bool Student::operator<=(const Student &rhs) const
{
    return !(rhs < *this);
}

bool Student::operator>=(const Student &rhs) const
{
    return !(*this < rhs);
}

/**
 * 拷贝构造
 * @param other
 */
//Student::Student(const Student &other) {
//    std::cout << "copy constructor()" << std::endl;
//    age = other.age;
//    name = new std::string(*other.name);
//    std::cout << "new String()" << std::endl;
//}

/**
 * 移动构造函数
 * @param other
 */
//Student::Student(Student &&other)
//{
//    std::cout << "move constructor()" << std::endl;
//    age = other.age;
//    name = other.name;
//    other.name = nullptr;
//}
