#include "GameBoard.h"

GameBoard::GameBoard(std::vector<std::vector<double>> board) :
	board(std::move(board)),
	N(this->board.size())
{
	if (N == 0)
		throw InvalidBoard{};
	for (const auto &row : this->board)
		if (row.size() != N)
			throw InvalidBoard{};
}

const std::vector<double>& GameBoard::operator[](std::size_t row) const
{
	return board[row];
}

std::size_t GameBoard::size() const
{
	return N;
}

void GameBoard::slideRight()
{
	slide(&GameBoard::toTheRight);
}

void GameBoard::slideLeft()
{
	slide(&GameBoard::toTheLeft);
}

void GameBoard::slideDown()
{
	slide(&GameBoard::downwards);
}

void GameBoard::slideUp()
{
	slide(&GameBoard::upwards);
}

void GameBoard::setCell(std::size_t row, std::size_t col, double value)
{
	board[row][col] = value;
}

void GameBoard::slide(
	double &(GameBoard::*direction)(std::size_t index, std::size_t cell))
{
	for (std::size_t index = 0; index < N; ++index) {
		std::vector<bool> hasBeenCombined(N, false);
		for (
			std::size_t adjacentCell = N - 1;
			adjacentCell > 0; 
			--adjacentCell)
		{
			const auto cell = adjacentCell - 1;
			const auto value = (this->*direction)(index, cell);
			auto nextNonzeroOrLastCell = findNextNonzeroOrLastCell(
				[&](std::size_t c) { return (this->*direction)(index, c); }, 
				cell);
			if ((this->*direction)(index, nextNonzeroOrLastCell) == 0)
				(this->*direction)(index, N - 1) = value;
			else if (
				(this->*direction)(index, nextNonzeroOrLastCell) == value &&
				!hasBeenCombined[nextNonzeroOrLastCell])
			{
				(this->*direction)(index, nextNonzeroOrLastCell) += value;
				hasBeenCombined[nextNonzeroOrLastCell] = true;
			}
			else if (nextNonzeroOrLastCell != adjacentCell)
				(this->*direction)(index, nextNonzeroOrLastCell - 1) = value;
			else
				continue;
			(this->*direction)(index, cell) = 0;
		}
	}
}

double GameBoard::findNextNonzeroOrLastCell(
	std::function<double(std::size_t cell)> direction, double start)
{
	auto _nextNonzeroOrLastCell = start;
	while (
		_nextNonzeroOrLastCell < N - 1 &&
		direction(++_nextNonzeroOrLastCell) == 0
	)
		;
	return _nextNonzeroOrLastCell;
}

double & GameBoard::toTheRight(std::size_t index, std::size_t cell)
{
	return board[index][cell];
}

double & GameBoard::toTheLeft(std::size_t index, std::size_t cell)
{
	return board[index][N - 1 - cell];
}

double & GameBoard::upwards(std::size_t index, std::size_t cell)
{
	return board[N - 1 - cell][index];
}

double & GameBoard::downwards(std::size_t index, std::size_t cell)
{
	return board[cell][index];
}

