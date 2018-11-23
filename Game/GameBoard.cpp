#include "GameBoard.h"

template <typename T>
GameBoard<T>::GameBoard(std::vector<std::vector<T>> board) :
	board(std::move(board)),
	N(this->board.size())
{
	if (N == 0)
		throw InvalidBoard{};
	for (const auto &row : this->board)
		if (row.size() != N)
			throw InvalidBoard{};
}

template <typename T>
const std::vector<T> &GameBoard<T>::operator[](std::size_t row) const
{
	return board[row];
}

template <typename T>
std::size_t GameBoard<T>::size() const
{
	return N;
}

template <typename T>
void GameBoard<T>::slideRight()
{
	slide(&GameBoard::toTheRight);
}

template <typename T>
void GameBoard<T>::slideLeft()
{
	slide(&GameBoard::toTheLeft);
}

template <typename T>
void GameBoard<T>::slideDown()
{
	slide(&GameBoard::downwards);
}

template <typename T>
void GameBoard<T>::slideUp()
{
	slide(&GameBoard::upwards);
}

template <typename T>
void GameBoard<T>::setCell(CellPosition cell, T value)
{
	board[cell.row][cell.col] = value;
}

template <typename T>
void GameBoard<T>::slide(
	T &(GameBoard::*traversal)(std::size_t index, std::size_t cell))
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

template <typename T>
std::size_t GameBoard<T>::findNextNonzeroOrLastCell(
	std::function<T(std::size_t cell)> traversal,
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

template <typename T>
T &GameBoard<T>::toTheRight(std::size_t index, std::size_t cell)
{
	return board[index][cell];
}

template <typename T>
T &GameBoard<T>::toTheLeft(std::size_t index, std::size_t cell)
{
	return board[index][N - 1 - cell];
}

template <typename T>
T &GameBoard<T>::upwards(std::size_t index, std::size_t cell)
{
	return board[N - 1 - cell][index];
}

template <typename T>
T &GameBoard<T>::downwards(std::size_t index, std::size_t cell)
{
	return board[cell][index];
}

template class GameBoard<int>;