#include "GameBoard.h"

GameBoard::GameBoard(std::vector<std::vector<double>> _board) :
	board(std::move(_board)),
	N(board.size())
{
	if (N == 0)
		throw std::runtime_error("Empty board.");
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
			const auto value = board[row][col];
			const auto _nextNonzeroOrLastColumn = nextNonzeroOrLastColumn(row, col);
			if (board[row][_nextNonzeroOrLastColumn] == 0)
				board[row].back() = value;
			else if (
				board[row][_nextNonzeroOrLastColumn] == value &&
				!hasBeenCombined[_nextNonzeroOrLastColumn])
			{
				board[row][_nextNonzeroOrLastColumn] += value;
				hasBeenCombined[_nextNonzeroOrLastColumn] = true;
			}
			else if (_nextNonzeroOrLastColumn != adjacentCol)
				board[row][_nextNonzeroOrLastColumn - 1] = value;
			else
				continue;
			board[row][col] = 0;
		}
	}
}

void GameBoard::moveLeft()
{
	for (size_t row = 0; row < N; ++row)
	{
		std::vector<bool> hasBeenCombined(N, false);
		for (size_t adjacentCol = 0; adjacentCol < N - 1; ++adjacentCol)
		{
			const auto col = adjacentCol + 1;
			const auto value = board[row][col];
			const auto _previousNonzeroOrFirstColumn = previousNonzeroOrFirstColumn(row, col);
			if (board[row][_previousNonzeroOrFirstColumn] == 0)
				board[row].front() = value;
			else if (
				board[row][_previousNonzeroOrFirstColumn] == value &&
				!hasBeenCombined[_previousNonzeroOrFirstColumn])
			{
				board[row][_previousNonzeroOrFirstColumn] += value;
				hasBeenCombined[_previousNonzeroOrFirstColumn] = true;
			}
			else if (_previousNonzeroOrFirstColumn != adjacentCol)
				board[row][_previousNonzeroOrFirstColumn + 1] = value;
			else
				continue;
			board[row][col] = 0;
		}
	}
}

void GameBoard::moveDown()
{
	for (size_t col = 0; col < N; ++col)
	{
		std::vector<bool> hasBeenCombined(N, false);
		for (size_t adjacentRow = N - 1; adjacentRow > 0; --adjacentRow)
		{
			const auto row = adjacentRow - 1;
			const auto value = board[row][col];
			const auto _nextNonzeroOrLastRow = nextNonzeroOrLastRow(row, col);
			if (board[_nextNonzeroOrLastRow][col] == 0)
				board.back()[col] = value;
			else if (
				board[_nextNonzeroOrLastRow][col] == value &&
				!hasBeenCombined[_nextNonzeroOrLastRow])
			{
				board[_nextNonzeroOrLastRow][col] += value;
				hasBeenCombined[_nextNonzeroOrLastRow] = true;
			}
			else if (_nextNonzeroOrLastRow != adjacentRow)
				board[_nextNonzeroOrLastRow - 1][col] = value;
			else
				continue;
			board[row][col] = 0;
		}
	}
}

void GameBoard::moveUp()
{
	moveAlong(&GameBoard::upwards);
}

void GameBoard::moveAlong(double &(GameBoard::*direction)(size_t range, size_t element))
{
	for (size_t range = 0; range < N; ++range) {
		std::vector<bool> hasBeenCombined(N, false);
		for (size_t adjacentElement = N - 1; adjacentElement > 0; --adjacentElement)
		{
			const auto element = adjacentElement - 1;
			const auto value = (this->*direction)(range, element);
			auto nextNonzeroOrLastElement = element;
			while (nextNonzeroOrLastElement < N - 1 && (this->*direction)(range, ++nextNonzeroOrLastElement) == 0)
				;
			if ((this->*direction)(range, nextNonzeroOrLastElement) == 0)
				(this->*direction)(range, N - 1) = value;
			else if (
				(this->*direction)(range, nextNonzeroOrLastElement) == value &&
				!hasBeenCombined[nextNonzeroOrLastElement])
			{
				(this->*direction)(range, nextNonzeroOrLastElement) += value;
				hasBeenCombined[nextNonzeroOrLastElement] = true;
			}
			else if (nextNonzeroOrLastElement != adjacentElement)
				(this->*direction)(range, nextNonzeroOrLastElement - 1) = value;
			else
				continue;
			(this->*direction)(range, element) = 0;
		}
	}
}

double & GameBoard::toTheRight(size_t range, size_t element)
{
	return board[range][element];
}

double & GameBoard::toTheLeft(size_t range, size_t element)
{
	return board[range][N - 1 - element];
}

double & GameBoard::upwards(size_t range, size_t element)
{
	return board[N - 1 - element][range];
}

double & GameBoard::downwards(size_t range, size_t element)
{
	return board[element][range];
}

size_t GameBoard::nextNonzeroOrLastColumn(size_t row, size_t col)
{
	while (col < N - 1 && board[row][++col] == 0)
		;
	return col;
}

size_t GameBoard::previousNonzeroOrFirstColumn(size_t row, size_t col)
{
	while (col > 0 && board[row][--col] == 0)
		;
	return col;
}

size_t GameBoard::nextNonzeroOrLastRow(size_t row, size_t col)
{
	while (row < N - 1 && board[++row][col] == 0)
		;
	return row;
}

size_t GameBoard::previousNonzeroOrFirstRow(size_t row, size_t col)
{
	while (row > 0 && board[--row][col] == 0)
		;
	return row;
}
