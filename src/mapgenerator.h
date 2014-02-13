#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "cell.h"
#include "util/simplexnoise.h"

class MapGenerator
{
public:
    MapGenerator(unsigned int seed);

    unsigned int get_cells_x() const
    {
        return cells_x;
    }

    unsigned int get_cells_y() const
    {
        return cells_y;
    }

    void make_cells(Cell *cells);

protected:
    unsigned int cells_x;
    unsigned int cells_y;

    Random random;
};

#endif // MAPGENERATOR_H
