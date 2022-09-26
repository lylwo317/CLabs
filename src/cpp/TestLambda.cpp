//
// Created by kevin on 2021/6/14.
//

#include <cstdio>
//有点类似于JavaScript中的闭包、iOS中的Block,本质就是匿名局部类+()操作符重载+自定义到函数指针的隐式转换。从而可以像函数一样使用

//完整结构: [capture list] (params list) mutable exception-> return type { function body }
// capture list:捕获外部变量列表，其实就是匿名局部类的成员变量
// params list:形参列表,不能使用默认参数,不能省略参数名。声明重载的()操作符的函数参数以及static函数参数
// mutable:用来说用是否可以修改捕获的变量
// exception:异常设定
// return type:返回值类型
// function body:函数体

// 有时可以省略部分结构
// [capture list] (params list) -> return type {function body}
// [capture list] (params list) {function body}
// [capture list] {function body}

/**
 * lambda本质就是局部类+()操作符重载+自定义到函数指针的隐式转换
 */
void simplestLambda(){

/*
    auto fun = []
    {
        printf("hello");
    };

    void (*ptr)() = fun;

    fun();
    ptr();
*/

//上面的lambda实际上是生成如下的局部类

    class __lambda_5_14
    {
    public:
        //模拟函数调用
        void operator()() const
        {
            printf("hello");
        }

        //作用：模拟函数指针的赋值行为。
        //定义到void (*)()函数指针的隐式转换。使得__lambda_5_14可以隐式转换成void (*)()函数指针
        //表面上是
        // auto (*ptr)() -> void  = __lambda_5_3;

        //实际上是
        // auto (*ptr)() -> void  = __invoke;
        using retType_5_14 = auto (*)() -> void;

        operator retType_5_14 () const noexcept//定义到void (*)()隐式转换
        {
            return __invoke;
        }

    private:
        //静态成员函数
        static inline void __invoke()
        {
            //类似
            const __lambda_5_14 *ptr;
            ptr->operator()();
            //模拟还是有差别的，其实这里是直接调用operator()，不管this变量
            //汇编如下：
//            ; void __cdecl simplestLambda(void)::$_0::__invoke()
//            simplestLambda(void)::$_0::__invoke(void) proc near
//            ; __unwind {
//                    push    rbp
//                    mov     rbp, rsp
//                    call    simplestLambda(void)::$_0::operator() const(void)
//                    pop     rbp
//                    retn
//                    ; } // starts at 401240
//            simplestLambda(void)::$_0::__invoke(void) endp
        }


    };

    __lambda_5_14 fun = __lambda_5_14{};

    //void (*ptr)() = fun;
    using FuncPtr_10 = void (*)();
    FuncPtr_10 ptr = static_cast<void (*)()>(fun.operator __lambda_5_14::retType_5_14());
    //ptr = __invoke

    //fun();
    //将lambda当做函数来使用，也就是所谓的函数对象
    fun.operator()();
    //ptr();
    ptr();
}

/**
 * 带有捕获的lambda函数是无法赋值给指针变量的
 */
void testLambdaCapture(){
    int a = 10;
    int b = 20;

    //除了a之外，一律都是引用捕获
    auto fun = [&,a](int v1) mutable //修改值捕获的变量，需要mutable，就是提醒程序员这个修改是对外没有作用的。如果一定要修改，那就得显示声明mutable
    {
        int i1 = a;
        int i2 = b;
        a = 50;//修改匿名局部类的成员int a
        b = 34;//修改匿名局部类的成员int& b，也就是修改了外部的int b = 20;变量
        printf("hello");
    };

    // 带有参数捕获的都不可以赋值给函数指针，因为赋值的话。
    // 无法保证函数调用的时候能捕获到，相同变量名的值
    //void (*ptr)() = fun;

    fun(12);
    printf("b = %d", b);
    //ptr();

    /*
      int a = 10;
      int b = 20;

      class __lambda_7_16
      {
        public:
        inline void operator()(int v1)
        {
          int i1 = a;
          int i2 = b;
          a = 50;
          b = 34;
          printf(static_cast<const char *>("hello"));
        }

        private:
        int a;
        int & b;
        public:
        __lambda_7_16(int & _a, int & _b)
        : a{_a}, b{_b}
        {}
    };

    __lambda_7_16 fun = __lambda_7_16(__lambda_7_16{a, b});
    fun.operator()(12);
    printf(static_cast<const char *>("b = %d"), b);
*/
}

int main()
{
    simplestLambda();
    testLambdaCapture();
    return 0;
}
