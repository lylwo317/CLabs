//
// Created by kevin on 2021/6/14.
//

#include <cstdio>

/**
 * lambda本质就是局部类+()操作符重载+自定义到函数指针的隐式转换
 */
void simplestLambda(){

    auto fun = []
    {
        printf("hello");
    };

    void (*ptr)() = fun;

    fun();
    ptr();

//上面的lambda实际上是生成如下的局部类
/*

    class __lambda_5_14
    {
    public:
        void operator()() const
        {
            printf("hello");
        }

        //定义到void (*)()函数指针的隐式转换。使得__lambda_5_14可以隐式转换成void (*)()函数指针
        //表面上是
        // auto (*ptr)() -> void  = __lambda_5_3;

        //实际上是
        // auto (*ptr)() -> void  = __invoke;
        using retType_5_14 = auto (*)() -> void;

        operator retType_5_14 () const noexcept
        {
            return __invoke;
        }

    private:
        //静态成员函数
        static inline void __invoke()
        {
            printf("hello");
        }


    };

    __lambda_5_14 fun = __lambda_5_14{};

    //void (*ptr)() = fun;
    using FuncPtr_10 = void (*)();
    FuncPtr_10 ptr = static_cast<void (*)()>(fun.operator __lambda_5_14::retType_5_14());

    //fun();
    //将lambda当做函数来使用，也就是所谓的函数对象
    fun.operator()();
    //ptr();
    ptr();
*/
}

int exec(int v1, int v2, int (* func)(int, int)){
    return func(v1, v2);
}

/*
void testAutoLambda(){
    auto fun = []{
        printf("hello");
    };
}
*/

int main()
{
    simplestLambda();
    exec(20, 10, [](int v1, int v2) { return v1 + v2; });
}
