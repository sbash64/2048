#include "ConsoleIODevice.h"
#include <conio.h>
#include <iostream>

static const auto keyUp = 72;
static const auto keyDown = 80;
static const auto keyLeft = 75;
static const auto keyRight = 77;

void ConsoleIODevice::print(std::string out)
{
	std::cout << out;
}

bool ConsoleIODevice::rightArrowKeyPressed()
{
	return key == keyRight;
}

bool ConsoleIODevice::downArrowKeyPressed()
{
	return key == keyDown;
}

bool ConsoleIODevice::leftArrowKeyPressed()
{
	return key == keyLeft;
}

bool ConsoleIODevice::upArrowKeyPressed()
{
	return key == keyUp;
}

void ConsoleIODevice::getKeyPress()
{
	_getch();
	key = _getch();
}
