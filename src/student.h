#ifndef STUDENT_H
#define STUDENT_H

#include <string>


class Student
{
private:
    std::string name;
    int age = 10;
public:
    explicit Student(std::string _name);
    Student(const Student &other) = default;
    Student(Student &&other) = default;
    virtual ~Student();

    std::string getName() const;

    void setName(std::string name);

    int getAge() const;
    void setAge(int age);

//    bool operator==(const Student &rhs) const;
    bool operator==(const Student &rhs) const;

    bool operator!=(const Student &rhs) const;

    bool operator<(const Student &rhs) const;

    bool operator>(const Student &rhs) const;

    bool operator<=(const Student &rhs) const;

    bool operator>=(const Student &rhs) const;


};

#endif // STUDENT_H
