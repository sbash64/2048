#pragma once

#include "GameBoard.h"

class GameBoardAnalyzer
{
public:
	GAME_API std::vector<size_t> openCells(const GameBoard &board);
};