#include "GameBoardAnalyzer.h"

std::vector<size_t> GameBoardAnalyzer::openCells(const GameBoard &board)
{
	std::vector<size_t> cells;
	for (size_t col = 0; col < board.size(); ++col)
		for (size_t row = 0; row < board.size(); ++row)
			if (board[row][col] == 0)
				cells.push_back(row + col * board.size());
	return cells;
}

bool GameBoardAnalyzer::canMove(const GameBoard &board)
{
	return board[0][0] == 0.0;
}
