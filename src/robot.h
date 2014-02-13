#ifndef ROBOT_H
#define ROBOT_H

#include "defs.h"

#include "gl.h"

#include "util/direction.h"

#include <iostream>
#include <math.h>

#define DAMAGE_LENGTH (unsigned int)(ROBOT_LENGTH * DAMAGE_RES)
#define DAMAGE_WIDTH  (unsigned int)(ROBOT_WIDTH  * DAMAGE_RES)

#define ROBOT_RAD sqrt(ROBOT_LENGTH * ROBOT_LENGTH + ROBOT_WIDTH * ROBOT_WIDTH)

class Robot
{
public:
    float x;
    float y;

    float v;

    float rot;

    unsigned int cell_ax;
    unsigned int cell_zx;
    unsigned int cell_ay;
    unsigned int cell_zy;

    struct
    {
        char damaged      : 1;
        char node_damaged : 1;
    } damage [DAMAGE_LENGTH * DAMAGE_WIDTH];

    void render();
};

#endif // ROBOT_H
