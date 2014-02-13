#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <chrono>

class Random : public std::mt19937_64
{
public:
    Random();
    Random(unsigned int seed);

    static unsigned int get_timestamp_seed();
};

#endif // RANDOM_H
