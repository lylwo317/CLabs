#include "logging.h"
#include <iostream>
#include "logstream.h"

int main(int argc, char *argv[])
{
//    kx::Logstream logstream;
//    bool a = true;
//    logstream << a;
    kx::Logging logger;
    logger.stream() << true;
    [] (kx::Logging& logger){
        logger.stream() << 123;
        std::cout << "finish" << std::endl;
    }(logger);
    return 0;
}
