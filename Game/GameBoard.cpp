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
		const auto columnBeforeEnd = board[row].size() - 2;
		for (int col = columnBeforeEnd; col > -1; col--)
		{
			const double value = board[row][col];
			const auto nextNonzeroOrLastColumn = getNextNonzeroOrLastColumn(row, col);
			if (board[row][nextNonzeroOrLastColumn] == 0)
				board[row].back() = value;
			else if (
				board[row][nextNonzeroOrLastColumn] == value &&
				!hasBeenCombined[nextNonzeroOrLastColumn])
			{
				board[row][nextNonzeroOrLastColumn] += value;
				hasBeenCombined[nextNonzeroOrLastColumn] = true;
			}
			else if (nextNonzeroOrLastColumn != col + 1)
				board[row][nextNonzeroOrLastColumn - 1] = value;
			else
				continue;
			board[row][col] = 0;
		}
	}
}

void GameBoard::moveDown()
{
	moveRight();
}

int GameBoard::getNextNonzeroOrLastColumn(int row, int col)
{
	while (col < board[row].size() - 1 && board[row][++col] == 0)
		;
	return col;
}
