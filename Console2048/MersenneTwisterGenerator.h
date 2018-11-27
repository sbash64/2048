#pragma once

#include <ConsoleGameModel/RandomNumberGenerator.h>
#include <random>

class MersenneTwisterGenerator : public RandomNumberGenerator {
    std::mt19937 rng;
public:
    MersenneTwisterGenerator();
    int randomIntBetween(int low, int hi) override;
};