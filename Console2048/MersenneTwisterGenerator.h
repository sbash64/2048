#pragma once

#include <RandomNumberGenerator.h>
#include <random>

class MersenneTwisterGenerator : public RandomNumberGenerator
{
	std::mt19937 rng;
public:
	MersenneTwisterGenerator();
	virtual int randomIntBetween(int low, int hi) override;
};