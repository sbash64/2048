#pragma once

#include "Interface.h"
#include <string>

class IODevice {
public:
	INTERFACE_OPERATIONS(IODevice);
	virtual void print(std::string) = 0;
	virtual bool rightArrowKeyPressed() = 0;
	virtual bool downArrowKeyPressed() = 0;
	virtual bool leftArrowKeyPressed() = 0;
	virtual bool upArrowKeyPressed() = 0;
	virtual void getKeyPress() = 0;
};