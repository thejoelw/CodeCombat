#include "mapgenerator.h"

MapGenerator::MapGenerator(unsigned int seed)
    : random(seed)
{
    cells_x = 32;
    cells_y = 32;
}

void MapGenerator::make_cells(Cell *cells)
{
    SimplexNoise noise1(random);
    SimplexNoise noise2(random);

    unsigned int x = 0;
    while (x < cells_x)
    {
        unsigned int y = 0;
        while (y < cells_y)
        {
            float fx = x * 0.1f;
            float fy = y * 0.1f;

            bool wall;
            wall  = noise1.raw_noise_2d(fx, fy) > 0.0;
            wall &= noise2.raw_noise_2d(fx, fy) > 0.0;

            wall &= x != 1;
            wall &= x != cells_x - 2;
            wall &= y != 1;
            wall &= y != cells_y - 2;

            wall |= x == 0;
            wall |= x == cells_x - 1;
            wall |= y == 0;
            wall |= y == cells_y - 1;

            cells[x + y * cells_x].type = wall ? Cell::steel : Cell::empty;
            y++;
        }
        x++;
    }

    unsigned int base_x = cells_x / 16;
    unsigned int base_y = cells_y / 16;

    cells[base_x + cells_y / 2 * cells_x].type = Cell::base;
    cells[(cells_x - base_x - 1) + cells_y / 2 * cells_x].type = Cell::base;
    cells[cells_x / 2 + base_y * cells_x].type = Cell::base;
    cells[cells_x / 2 + (cells_y - base_y - 1) * cells_x].type = Cell::base;
}
