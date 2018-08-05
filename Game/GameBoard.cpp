#include "GameBoard.h"

GameBoard::GameBoard(const std::vector<std::vector<double>> &board) :
	board(board)
{
}

const std::vector<std::vector<double>>& GameBoard::getBoard()
{
	return board;
}

void GameBoard::moveRight()
{
	for (int row = 0; row < board.size(); row++)
	{
		std::vector<bool> combinationSpaces(board[row].size() - 2, false);
		for (int col = board[row].size() - 2; col > -1; col--)
		{
			double value = board[row][col];
			if (value != 0)
			{
				int nextNonzeroColumn = col;
				while (nextNonzeroColumn < board[row].size() - 1 && board[row][++nextNonzeroColumn] == 0)
					;
				if (board[row][nextNonzeroColumn] == 0)
				{
					board[row][col] = 0;
					board[row][nextNonzeroColumn] = value;
				}
				else if (board[row][nextNonzeroColumn] == value && !combinationSpaces[nextNonzeroColumn-2])
				{
					board[row][col] = 0;
					board[row][nextNonzeroColumn] = 2 * value;
					combinationSpaces[nextNonzeroColumn - 2] = true;
				}
				else
				{
					board[row][nextNonzeroColumn - 1] = value;
					if (nextNonzeroColumn != col + 1)
						board[row][col] = 0;
				}
			}
		}
	}
}
