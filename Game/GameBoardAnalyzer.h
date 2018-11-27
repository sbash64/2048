#pragma once

#include "GameBoard.h"

class GameBoardAnalyzer {
    using size_type = GameBoard<int>::size_type;
public:
    using cellIndices = std::vector<size_type>;
    GAME_API cellIndices openCells(const GameBoard<int> &);
    GAME_API bool canMove(const GameBoard<int> &);
};