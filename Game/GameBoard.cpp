#include "GameBoard.h"

GameBoard::GameBoard(std::vector<std::vector<double>> _board) :
	board(std::move(_board)),
	N(board.size())
{
	for (const auto &row : board)
		if (row.size() != N)
			throw std::runtime_error("Invalid board dimensions.");
}

const std::vector<std::vector<double>> &GameBoard::getBoard()
{
	return board;
}

void GameBoard::moveRight()
{
	for (size_t row = 0; row < N; row++)
	{
		std::vector<bool> hasBeenCombined(N, false);
		const size_t columnBeforeEnd = N - 2;
		for (size_t col = columnBeforeEnd + 1; col > 0; col--)
		{
			const double value = board[row][col-1];
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
			else if (nextNonzeroOrLastColumn != col)
				board[row][nextNonzeroOrLastColumn - 1] = value;
			else
				continue;
			board[row][col-1] = 0;
		}
	}
}

void GameBoard::moveDown()
{
	for (size_t col = 0; col < N; col++)
	{
		std::vector<bool> hasBeenCombined(N, false);
		const size_t rowBeforeEnd = N - 2;
		for (size_t row = rowBeforeEnd + 1; row > 0; row--)
		{
			const double value = board[row-1][col];
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
			else if (nextNonzeroOrLastRow != row)
				board[nextNonzeroOrLastRow - 1][col] = value;
			else
				continue;
			board[row-1][col] = 0;
		}
	}
}

int GameBoard::getNextNonzeroOrLastColumn(size_t row, size_t col)
{
	while (col < N && board[row][++col - 1] == 0)
		;
	return col - 1;
}

int GameBoard::getNextNonzeroOrLastRow(size_t row, size_t col)
{
	while (row < N && board[++row - 1][col] == 0)
		;
	return row - 1;
}
