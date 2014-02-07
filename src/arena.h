#ifndef ARENA_H
#define ARENA_H

#include "gl.h"

#include <iostream>

class Arena
{
public:
    void tick(double time);

    void render(unsigned int width, unsigned int height);
};

#endif // ARENA_H
