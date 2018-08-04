#include "GameBoard.h"

GameBoard::GameBoard(std::vector<std::vector<double>> board) :
	board(board)
{
}

const std::vector<std::vector<double>>& GameBoard::getBoard()
{
	return board;
}

void GameBoard::moveRight()
{
	for (size_t i = 0; i < board.size(); i++)
	{
		double sum = 0;
		for (size_t j = 0; j < board[i].size()-1; j++)
		{
			sum += board[i][j];
			board[i][j] = 0;
		}
		board[i].back() = sum;
	}
}
