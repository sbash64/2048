#pragma once

#include "Interface.h"
#include <GameBoard.h>
#include <string>

class Formatter {
public:
	INTERFACE_OPERATIONS(Formatter);
	virtual std::string asString(const GameBoard &board) = 0;
};