#ifndef ARENA_H
#define ARENA_H

#include "gl.h"

#include "mapgenerator.h"
#include "cell.h"
#include "robot.h"

#include <iostream>
#include <vector>

class Arena
{
public:
    Arena(MapGenerator &mg);
    ~Arena();

    void add_robot(Robot *robot);

    void tick(double time);

    void render(unsigned int width, unsigned int height) const;

protected:
    unsigned int cells_x;
    unsigned int cells_y;

    Cell *cells;

    WeakSet<Robot*> robots;

private:
    unsigned int cell_i(unsigned int x, unsigned int y) const
    {
        return x + y * cells_x;
    }
};

#endif // ARENA_H
