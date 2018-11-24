#pragma once

#include "GameBoard.h"

class GameBoardAnalyzer {
	using size_type = GameBoard<int>::size_type;
public:
	GAME_API std::vector<size_type> openCells(const GameBoard<int> &);
	GAME_API bool canMove(const GameBoard<int> &);
};