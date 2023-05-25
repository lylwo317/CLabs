#include <cstddef>

class TestThisAddOne
{
private:
    /* data */
    size_t size;
public:
    TestThisAddOne(/* args */);
    void* getBuffer();
    ~TestThisAddOne();
};

void* TestThisAddOne::getBuffer(){
    return this + 1;//偏移一个TestThisAddOne对象的大小
}

TestThisAddOne::TestThisAddOne(/* args */)
{
    
}

TestThisAddOne::~TestThisAddOne()
{
}



int main(int argc, char const *argv[])
{
    /* code */
    TestThisAddOne one;
    void* hello = one.getBuffer();
    return 0;
}
