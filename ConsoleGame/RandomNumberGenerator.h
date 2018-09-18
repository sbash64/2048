#pragma once

class RandomNumberGenerator
{
public:
	virtual ~RandomNumberGenerator() = default;
	virtual int randomIntBetween(int low, int hi) = 0;
};