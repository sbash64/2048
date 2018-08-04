#include "stdafx.h"
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
		for (size_t j = 0; j < board[i].size(); j++)
			if (board[i][j] == 2) {
				board[i].back() = 4;
				board[i][j] = 0;
			}
}
