#ifndef DAMAGE_H
#define DAMAGE_H

template <unsigned int X, unsigned int Y>
struct Damage
{
    struct
    {
        char damaged      : 1;
        char node_damaged : 1;
    } damage [X * Y];
};

#endif // DAMAGE_H
