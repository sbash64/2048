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
	for (int i = 0; i < board.size(); i++)
		for (int j = board[i].size() - 2; j > -1; j--)
		{
			double value = board[i][j];
			if (value != 0)
			{
				int k = j;
				while (k < board[i].size() - 1 && board[i][++k] == 0)
					;
				if (board[i][k] == 0)
					board[i][k] = value;
				else if (board[i][k] == value)
					board[i][k] = 2 * value;
				else
					board[i][k - 1] = value;
				board[i][j] = 0;
			}
		}
}
