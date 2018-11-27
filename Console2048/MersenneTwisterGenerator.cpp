#include "MersenneTwisterGenerator.h"

MersenneTwisterGenerator::MersenneTwisterGenerator() :
    rng{ std::random_device{}() }
{
}

int MersenneTwisterGenerator::randomIntBetween(int low, int hi) {
    return std::uniform_int_distribution<int>{ low, hi }(rng);
}
