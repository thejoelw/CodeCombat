#include <iostream>

#include "window.h"

int main()
{
    std::cout << "Starting..." << std::endl;

    Arena arena(1024, 1024);

    Robot *r1 = new Robot();
    r1->x = 5.0;
    r1->y = 8.0;
    r1->v = 0.1;
    r1->rot = 1.0;
    arena.add_robot(r1);

    Window window(arena);
    bool res = window.run();

    std::cout << "Ending..." << std::endl;

    return res;
}
