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
		for (int j = board[i].size()-2; j > -1; j--)
		{
			if (board[i][j] != 0)
			{
				size_t k = j;
				while (k < board[i].size()-1 && board[i][++k] == 0)
					;
				if (board[i][k] == 0)
				{
					double value = board[i][j];
					board[i][j] = 0;
					board[i][k] = value;
				}
				else if (board[i][k] == board[i][j])
				{
					double value = board[i][j];
					board[i][j] = 0;
					board[i][k] = 2 * value;
				}
				else
				{
					double value = board[i][j];
					board[i][j] = 0;
					board[i][k-1] = value;
				}
			}
		}
	}
}
