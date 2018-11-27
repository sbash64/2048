#pragma once

#include "Interface.h"
#include <Game/GameBoard.h>
#include <string>

class Formatter {
public:
	INTERFACE_OPERATIONS(Formatter);
	virtual std::string asString(const GameBoard<int> &board) = 0;
};