#include "MersenneTwisterGenerator.h"

MersenneTwisterGenerator::MersenneTwisterGenerator() :
	rng(std::random_device{}())
{
}

int MersenneTwisterGenerator::randomIntBetween(int low, int hi)
{
	std::uniform_int_distribution<int> uni(low, hi);
	return uni(rng);
}
