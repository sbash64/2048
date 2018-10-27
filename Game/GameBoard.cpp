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

void GameBoard::setCell(CellPosition cell, double value)
{
	board[cell.row][cell.col] = value;
}

void GameBoard::slide(
	double &(GameBoard::*traversal)(std::size_t index, std::size_t cell))
{
	for (std::size_t index = 0; index < N; ++index) {
		const auto innerTraversal =
			[=](std::size_t cell) -> decltype(auto) { 
				return (this->*traversal)(index, cell); 
			};
		std::vector<bool> hasBeenCombined(N, false);
		for (
			std::size_t adjacentCell = N - 1;
			adjacentCell > 0; 
			--adjacentCell
		) {
			const auto cell = adjacentCell - 1;
			const auto value = innerTraversal(cell);
			const auto furthestDestination = findNextNonzeroOrLastCell(
				innerTraversal,
				cell);
			const auto furthestDestinationValue = 
				innerTraversal(furthestDestination);
			if (furthestDestinationValue == 0)
				innerTraversal(N - 1) = value;
			else if (
				furthestDestinationValue == value &&
				!hasBeenCombined[furthestDestination]
			) {
				innerTraversal(furthestDestination) += value;
				hasBeenCombined[furthestDestination] = true;
			}
			else if (furthestDestination != adjacentCell)
				innerTraversal(furthestDestination - 1) = value;
			else
				continue;
			innerTraversal(cell) = 0;
		}
	}
}

std::size_t GameBoard::findNextNonzeroOrLastCell(
	std::function<double(std::size_t cell)> traversal, 
	std::size_t start)
{
	auto _nextNonzeroOrLastCell = start;
	while (
		_nextNonzeroOrLastCell < N - 1 &&
		traversal(++_nextNonzeroOrLastCell) == 0
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

