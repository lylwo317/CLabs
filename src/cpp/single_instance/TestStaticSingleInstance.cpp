class Foo {
public:
    static Foo* getInstance()
    {
        static Foo s_instance;
        return &s_instance;
    }
    int getA()
    {
        return a;
    }

private:
    short a = 10;
    Foo() { }
};

int main(int argc, const char* argv[])
{
    Foo* f = Foo::getInstance();
    int b = f->getA();
    return b;
}