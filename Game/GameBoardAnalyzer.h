#pragma once

#include "GameBoard.h"

class GameBoardAnalyzer
{
public:
	GAME_API std::vector<std::size_t> openCells(const GameBoard &board);
};