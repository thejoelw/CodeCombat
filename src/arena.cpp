#include "arena.h"

Arena::Arena(MapGenerator &mg)
    : cells_x(mg.get_cells_x())
    , cells_y(mg.get_cells_y())
    , cells(new Cell[cells_x * cells_y])
{
    mg.make_cells(cells);
}

Arena::~Arena()
{
    delete[] cells;
}

void Arena::add_robot(Robot *robot)
{
    robots.insert(robot);

    robot->cell_ax = (robot->x - ROBOT_RAD) / CELL_SIZE;
    robot->cell_zx = (robot->x + ROBOT_RAD) / CELL_SIZE;
    robot->cell_ay = (robot->y - ROBOT_RAD) / CELL_SIZE;
    robot->cell_zy = (robot->y + ROBOT_RAD) / CELL_SIZE;

    if (robot->cell_ax >= cells_x) {robot->cell_ax = 0;}
    if (robot->cell_zx >= cells_x) {robot->cell_zx = cells_x - 1;}
    if (robot->cell_ay >= cells_y) {robot->cell_ay = 0;}
    if (robot->cell_zy >= cells_y) {robot->cell_zy = cells_y - 1;}

    unsigned int x = robot->cell_ax;
    while (x <= robot->cell_zx)
    {
        unsigned int y = robot->cell_ay;
        while (y <= robot->cell_zy)
        {
            cells[cell_i(x, y)].add_robot(robot);
            y++;
        }
        x++;
    }
}

void Arena::tick(double time)
{
    std::vector<Robot*>::iterator i = robots.begin();
    while (i != robots.end())
    {
        Robot &r = **i;

        r.rot += 0.01;

        float rot_sin = sin(r.rot);
        float rot_cos = cos(r.rot);

        r.x += rot_sin * r.v;
        r.y += rot_cos * r.v;

        // Bounce off walls
        /*
        float mx = size_x - r.rad;
        if (r.x > mx) {r.x = mx * 2.0 - r.x; r.vx = -abs(r.vx);}
        else if (r.x < r.rad) {r.x = r.rad * 2.0 - r.x; r.vx = abs(r.vx);}

        float my = size_y - r.rad;
        if (r.y > my) {r.y = my * 2.0 - r.y; r.vy = -abs(r.vy);}
        else if (r.y < r.rad) {r.y = r.rad * 2.0 - r.y; r.vy = abs(r.vy);}
        */

        // Writing
        unsigned int cell_ax = (r.x - ROBOT_RAD) / CELL_SIZE;
        unsigned int cell_zx = (r.x + ROBOT_RAD) / CELL_SIZE;
        unsigned int cell_ay = (r.y - ROBOT_RAD) / CELL_SIZE;
        unsigned int cell_zy = (r.y + ROBOT_RAD) / CELL_SIZE;

        if (cell_ax >= cells_x) {cell_ax = 0;}
        if (cell_zx >= cells_x) {cell_zx = cells_x - 1;}
        if (cell_ay >= cells_y) {cell_ay = 0;}
        if (cell_zy >= cells_y) {cell_zy = cells_y - 1;}

        /*
        remove_atom_from_col(*i, a.bin_sx, bin_sx, bin_sy, bin_ey);
        remove_atom_from_col(*i, a.bin_ex, bin_ex, bin_sy, bin_ey);
        remove_atom_from_row(*i, a.bin_sy, bin_sy, bin_sx, bin_ex);
        remove_atom_from_row(*i, a.bin_ey, bin_ey, bin_sx, bin_ex);
        */

        while (r.cell_ax < cell_ax)
        {
            unsigned int y = r.cell_ay;
            while (y <= r.cell_zy)
            {
                cells[cell_i(r.cell_ax, y)].remove_robot(&r);
                y++;
            }
            r.cell_ax++;
        }
        while (r.cell_ax > cell_ax)
        {
            unsigned int y = r.cell_ay;
            while (y <= r.cell_zy)
            {
                cells[cell_i(r.cell_ax, y)].add_robot(&r);
                y++;
            }
            r.cell_ax--;
        }

        while (r.cell_zx < cell_zx)
        {
            unsigned int y = r.cell_ay;
            while (y <= r.cell_zy)
            {
                cells[cell_i(r.cell_zx, y)].add_robot(&r);
                y++;
            }
            r.cell_zx++;
        }
        while (r.cell_zx > cell_zx)
        {
            unsigned int y = r.cell_ay;
            while (y <= r.cell_zy)
            {
                cells[cell_i(r.cell_zx, y)].remove_robot(&r);
                y++;
            }
            r.cell_zx--;
        }

        while (r.cell_ay < cell_ay)
        {
            unsigned int x = r.cell_ax;
            while (x <= r.cell_zx)
            {
                cells[cell_i(x, r.cell_ay)].remove_robot(&r);
                x++;
            }
            r.cell_ay++;
        }
        while (r.cell_ay > cell_ay)
        {
            unsigned int x = r.cell_ax;
            while (x <= r.cell_zx)
            {
                cells[cell_i(x, r.cell_ay)].add_robot(&r);
                x++;
            }
            r.cell_ay--;
        }

        while (r.cell_zy < cell_zy)
        {
            unsigned int x = r.cell_ax;
            while (x <= r.cell_zx)
            {
                cells[cell_i(x, r.cell_zy)].add_robot(&r);
                x++;
            }
            r.cell_zy++;
        }
        while (r.cell_zy > cell_zy)
        {
            unsigned int x = r.cell_ax;
            while (x <= r.cell_zx)
            {
                cells[cell_i(x, r.cell_zy)].remove_robot(&r);
                x++;
            }
            r.cell_zy--;
        }

        // Reading
        cell_ax = (r.x - ROBOT_RAD) / CELL_SIZE;
        cell_zx = (r.x + ROBOT_RAD) / CELL_SIZE;
        cell_ay = (r.y - ROBOT_RAD) / CELL_SIZE;
        cell_zy = (r.y + ROBOT_RAD) / CELL_SIZE;

        unsigned int x = cell_ax;
        while (x <= cell_zx)
        {
            unsigned int y = cell_ay;
            while (y <= cell_zy)
            {
                WeakSet<Robot*> &cell_robots = cells[cell_i(x, y)].robots;
                WeakSet<Robot*>::iterator j = cell_robots.begin();
                while (j != cell_robots.end())
                {
                    if (&r != *j)
                    {
                        std::cout << "Collision!" << std::endl;
                    }
                    j++;
                }
                y++;
            }
            x++;
        }

        i++;
    }
}

void Arena::render(unsigned int width, unsigned int height) const
{
    unsigned int x = 0;
    while (x < cells_x)
    {
        unsigned int y = 0;
        while (y < cells_y)
        {
            Cell::Type t = cells[cell_i(x, y)].type;
            if (t == Cell::base || t == Cell::rock || t == Cell::steel)
            {
                glBegin(GL_QUADS);

                switch (t)
                {
                case Cell::base:
                    glColor3ub(0, 255, 255);
                    break;
                case Cell::rock:
                    glColor3ub(128, 64, 64);
                    break;
                case Cell::steel:
                    glColor3ub(64, 64, 64);
                    break;
                }

                glVertex2i(x * CELL_SIZE, y * CELL_SIZE);
                glVertex2i((x + 1) * CELL_SIZE, y * CELL_SIZE);
                glVertex2i((x + 1) * CELL_SIZE, (y + 1) * CELL_SIZE);
                glVertex2i(x * CELL_SIZE, (y + 1) * CELL_SIZE);
                glEnd();
            }

            y++;
        }
        x++;
    }

    WeakSet<Robot*>::const_iterator i = robots.cbegin();
    while (i != robots.cend())
    {
        (*i)->render();
        i++;
    }
}
