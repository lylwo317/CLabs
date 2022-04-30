//
// Created by kevin on 2022/4/24.
//

//无继承
class Animal{
private:
    int name;
    int age;
};

//有继承
class Dog : public Animal{
public:
    int dogType;
};


int main(int argc, char const *argv[])
{
    Animal animal;
    Dog dog;
}

