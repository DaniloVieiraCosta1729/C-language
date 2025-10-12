#include <iostream> 

extern "C" int mostra(int x)
{
    std::cout << x << std::endl; 

    return 0;
}