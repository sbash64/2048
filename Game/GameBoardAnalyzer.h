#pragma once

#include "GameBoard.h"

class GameBoardAnalyzer
{
public:
	GAME_API std::vector<double> openCells(const GameBoard &board);
};