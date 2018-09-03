#include "GameBoard.h"

GameBoard::GameBoard(const std::vector<std::vector<double>> &board) :
	board(board)
{
	const auto rows = this->board.size();
	for (const auto &row : this->board)
		if (row.size() != rows)
			throw std::runtime_error("Invalid board dimensions.");
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
	for (int col = 0; col < board.front().size(); col++)
	{
		std::vector<bool> hasBeenCombined(board.size(), false);
		const auto rowBeforeEnd = board.size() - 2;
		for (int row = rowBeforeEnd; row > -1; row--)
		{
			const double value = board[row][col];
			const auto nextNonzeroOrLastRow = getNextNonzeroOrLastRow(row, col);
			if (board[nextNonzeroOrLastRow][col] == 0)
				board.back()[col] = value;
			else if (
				board[nextNonzeroOrLastRow][col] == value &&
				!hasBeenCombined[nextNonzeroOrLastRow])
			{
				board[nextNonzeroOrLastRow][col] += value;
				hasBeenCombined[nextNonzeroOrLastRow] = true;
			}
			else if (nextNonzeroOrLastRow != row + 1)
				board[nextNonzeroOrLastRow - 1][col] = value;
			else
				continue;
			board[row][col] = 0;
		}
	}
}

int GameBoard::getNextNonzeroOrLastColumn(int row, int col)
{
	while (col < board[row].size() - 1 && board[row][++col] == 0)
		;
	return col;
}

int GameBoard::getNextNonzeroOrLastRow(int row, int col)
{
	while (row < board.size() - 1 && board[++row][col] == 0)
		;
	return row;
}
