#pragma once

#include <string>

class IODevice
{
public:
	virtual ~IODevice() = default;
	virtual void print(std::string) = 0;
	virtual bool rightArrowKeyPressed() = 0;
};