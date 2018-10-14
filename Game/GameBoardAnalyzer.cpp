#include "GameBoardAnalyzer.h"

std::vector<std::size_t> GameBoardAnalyzer::openCells(const GameBoard &board)
{
	std::vector<std::size_t> cells;
	for (std::size_t col = 0; col < board.size(); ++col)
		for (std::size_t row = 0; row < board.size(); ++row)
			if (board[row][col] == 0)
				cells.push_back(row + col * board.size());
	return cells;
}

bool GameBoardAnalyzer::canMove(const GameBoard &board)
{
	for (std::size_t col = 0; col < board.size(); ++col)
		for (std::size_t row = 0; row < board.size(); ++row)
			if (board[row][col] == 0)
				return true;
	return false;
}
