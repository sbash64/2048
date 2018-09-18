#pragma once

#include <RandomNumberGenerator.h>

class MersenneTwisterGenerator : public RandomNumberGenerator
{
	virtual int randomIntBetween(int low, int hi) override;
};