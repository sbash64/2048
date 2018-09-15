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

const std::vector<std::vector<double>> &GameBoard::getBoard() noexcept
{
	return board;
}

void GameBoard::moveRight()
{
	moveAlong(&GameBoard::toTheRight);
}

void GameBoard::moveLeft()
{
	moveAlong(&GameBoard::toTheLeft);
}

void GameBoard::moveDown()
{
	moveAlong(&GameBoard::downwards);
}

void GameBoard::moveUp()
{
	moveAlong(&GameBoard::upwards);
}

void GameBoard::moveAlong(
	double &(GameBoard::*direction)(size_t slice, size_t element))
{
	for (size_t slice = 0; slice < N; ++slice) {
		std::vector<bool> hasBeenCombined(N, false);
		for (
			size_t adjacentElement = N - 1; 
			adjacentElement > 0; 
			--adjacentElement)
		{
			const auto element = adjacentElement - 1;
			const auto value = (this->*direction)(slice, element);
			auto nextNonzeroOrLastElement = element;
			while (
				nextNonzeroOrLastElement < N - 1 && 
				(this->*direction)(slice, ++nextNonzeroOrLastElement) == 0)
				;
			if ((this->*direction)(slice, nextNonzeroOrLastElement) == 0)
				(this->*direction)(slice, N - 1) = value;
			else if (
				(this->*direction)(slice, nextNonzeroOrLastElement) == value &&
				!hasBeenCombined[nextNonzeroOrLastElement])
			{
				(this->*direction)(slice, nextNonzeroOrLastElement) += value;
				hasBeenCombined[nextNonzeroOrLastElement] = true;
			}
			else if (nextNonzeroOrLastElement != adjacentElement)
				(this->*direction)(slice, nextNonzeroOrLastElement - 1) = value;
			else
				continue;
			(this->*direction)(slice, element) = 0;
		}
	}
}

double & GameBoard::toTheRight(size_t slice, size_t element)
{
	return board[slice][element];
}

double & GameBoard::toTheLeft(size_t slice, size_t element)
{
	return board[slice][N - 1 - element];
}

double & GameBoard::upwards(size_t slice, size_t element)
{
	return board[N - 1 - element][slice];
}

double & GameBoard::downwards(size_t slice, size_t element)
{
	return board[element][slice];
}

