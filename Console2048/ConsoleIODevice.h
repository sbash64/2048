#pragma once

#include <IODevice.h>

class ConsoleIODevice : public IODevice
{
	int key;
public:
	virtual void print(std::string) override;
	virtual bool rightArrowKeyPressed() override;
	virtual bool downArrowKeyPressed() override;
	virtual bool leftArrowKeyPressed() override;
	virtual bool upArrowKeyPressed() override;
	virtual void getKeyPress() override;
};