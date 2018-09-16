#pragma once

#include <string>

class IODevice
{
public:
	virtual ~IODevice() = default;
	virtual void print(std::string) = 0;
	virtual bool rightArrowKeyPressed() = 0;
	virtual bool downArrowKeyPressed() = 0;
	virtual bool leftArrowKeyPressed() = 0;
};