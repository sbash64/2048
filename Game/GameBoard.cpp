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
		std::vector<bool> hasBeenCombined(board[row].size(), false);
		const auto oneBeforeEnd = board[row].size() - 2;
		for (int col = oneBeforeEnd; col > -1; col--)
		{
			double value = board[row][col];
			if (value != 0)
			{
				const auto nextNonzeroColumn = getNextNonZeroColumn(row, col);
				if (board[row][nextNonzeroColumn] == 0)
				{
					board[row][col] = 0;
					board[row][nextNonzeroColumn] = value;
				}
				else if (board[row][nextNonzeroColumn] == value && !hasBeenCombined[nextNonzeroColumn])
				{
					board[row][col] = 0;
					board[row][nextNonzeroColumn] = 2 * value;
					hasBeenCombined[nextNonzeroColumn] = true;
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

int GameBoard::getNextNonZeroColumn(int row, int col)
{
	int i = col;
	while (i < board[row].size() - 1 && board[row][++i] == 0)
		;
	return i;
}
