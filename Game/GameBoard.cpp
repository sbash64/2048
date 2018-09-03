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
	for (size_t row = 0; row < N; ++row)
	{
		std::vector<bool> hasBeenCombined(N, false);
		for (size_t adjacentCol = N - 1; adjacentCol > 0; --adjacentCol)
		{
			const auto col = adjacentCol - 1;
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
			else if (nextNonzeroOrLastColumn != adjacentCol)
				board[row][nextNonzeroOrLastColumn - 1] = value;
			else
				continue;
			board[row][col] = 0;
		}
	}
}

void GameBoard::moveLeft()
{

}

void GameBoard::moveDown()
{
	for (size_t col = 0; col < N; ++col)
	{
		std::vector<bool> hasBeenCombined(N, false);
		for (size_t adjacentRow = N - 1; adjacentRow > 0; --adjacentRow)
		{
			const auto row = adjacentRow - 1;
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
			else if (nextNonzeroOrLastRow != adjacentRow)
				board[nextNonzeroOrLastRow - 1][col] = value;
			else
				continue;
			board[row][col] = 0;
		}
	}
}

int GameBoard::getNextNonzeroOrLastColumn(size_t row, size_t col)
{
	while (col < N - 1 && board[row][++col] == 0)
		;
	return col;
}

int GameBoard::getNextNonzeroOrLastRow(size_t row, size_t col)
{
	while (row < N - 1 && board[++row][col] == 0)
		;
	return row;
}
