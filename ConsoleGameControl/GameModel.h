#pragma once

#include "Interface.h"
#include <string>

class GameModel {
public:
	INTERFACE_OPERATIONS(GameModel);
	virtual std::string newGame() = 0;
	virtual std::string down() = 0;
	virtual std::string up() = 0;
	virtual std::string left() = 0;
	virtual std::string right() = 0;
};