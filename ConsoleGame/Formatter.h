#pragma once

#include <GameBoard.h>
#include <string>

class Formatter
{
public:
	virtual ~Formatter() = default;
	virtual std::string asString(const GameBoard &board) = 0;
};