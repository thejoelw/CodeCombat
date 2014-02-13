#include <iostream>

#include "window.h"

int main()
{
    std::cout << "Starting..." << std::endl;

    MapGenerator mg(123);

    Arena arena(mg);

    Robot *r1 = new Robot();
    r1->x = 8.0;
    r1->y = 25.0;
    r1->v = 0.1;
    r1->rot = 1.0;
    arena.add_robot(r1);

    Window window(arena);
    bool res = window.run();

    std::cout << "Ending..." << std::endl;

    return res;
}
