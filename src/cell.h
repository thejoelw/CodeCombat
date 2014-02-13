#ifndef CELL_H
#define CELL_H

#include "defs.h"
#include "robot.h"
#include "util/weakset.h"

struct Cell
{
    enum Type {empty, base, rock, steel} type;

    struct
    {
        char damaged      : 1;
        char node_damaged : 1;
    } damage [DAMAGE_RES * DAMAGE_RES];

    WeakSet<Robot*> robots;

    void add_robot(Robot *robot)
    {
        robots.insert(robot);
    }

    void remove_robot(Robot *robot)
    {
        WeakSet<Robot*>::iterator i = robots.begin();
        while (i != robots.end())
        {
            if (*i == robot)
            {
                robots.erase(i);
                break;
            }
            i++;
        }
    }
};

#endif // CELL_H
