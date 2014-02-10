#include <iostream>

#include "window.h"

int main()
{
    std::cout << "Starting..." << std::endl;


    Arena arena(1024, 1024);
    Window window(arena);
    bool res = window.run();

    std::cout << "Ending..." << std::endl;

    return res;
}
