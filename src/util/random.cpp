#include "random.h"

Random::Random()
    : Random(get_timestamp_seed())
{
}

Random::Random(unsigned int seed)
    : mersenne_twister_engine(seed)
{
}

unsigned int Random::get_timestamp_seed()
{
    return std::chrono::system_clock::now().time_since_epoch().count();
}
