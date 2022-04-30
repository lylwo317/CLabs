//
// Created by kevin on 2022/4/24.
//

//无继承
class Animal{
private:
    int name;
    int age;
    virtual void getAge(){

    }

protected:
    virtual ~Animal() = default;
};

//有继承
class Dog : public Animal{
public:
    int dogType;
    void getAge() override{

    }
};


int main(int argc, char const *argv[])
{
    Dog* dog = new Dog;
    delete dog;
    return 0;
}

