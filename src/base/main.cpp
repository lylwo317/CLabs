#include "logging.h"
#include <iostream>
#include "logstream.h"
#include <typeinfo>
extern int ab;

int main(int argc, char *argv[])
{
//    kx::Logstream logstream;
//    bool a = true;
//    logstream << a;
    kx::Logging logger;
    logger.stream() << true;
    auto lam = [] (kx::Logging& logger){
        logger.stream() << 123;
        std::cout << "finish" << std::endl;
    };

    auto lam1 = [&] (){
        logger.stream() << 456;
        std::cout << "finish" << std::endl;
    };


//    bool a = 12;
//    std::cout<<"lam1的类型是"<<typeid(a).name()<< std::endl;
    lam1();
    return 0;
}
