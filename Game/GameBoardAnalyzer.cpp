#include "GameBoardAnalyzer.h"

std::vector<size_t> GameBoardAnalyzer::openCells(const GameBoard &board)
{
	std::vector<size_t> cells;
	const auto _board = board.getBoard();
	for (size_t col = 0; col < _board.front().size(); ++col)
		for (size_t row = 0; row < _board.size(); ++row)
			if (_board[row][col] == 0)
				cells.push_back(row + col * _board.size());
	return cells;
}

bool GameBoardAnalyzer::canMove(const GameBoard &board)
{
	return board.getBoard()[0][0] == 0.0;
}
