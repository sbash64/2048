#include "GameBoard.h"

template<typename T>
GameBoard<T>::GameBoard(Board board) :
	board(std::move(board)),
	N(this->board.size())
{
	if (N == 0)
		throw InvalidBoard{};
	for (const auto &row : this->board)
		if (row.size() != N)
			throw InvalidBoard{};
}

template<typename T>
typename const GameBoard<T>::Row 
	&GameBoard<T>::operator[](size_type row) const
{
	return board[row];
}

template<typename T>
typename GameBoard<T>::size_type GameBoard<T>::size() const
{
	return N;
}

template<typename T>
void GameBoard<T>::right()
{
	slide(&GameBoard::toTheRight);
}

template<typename T>
void GameBoard<T>::left()
{
	slide(&GameBoard::toTheLeft);
}

template<typename T>
void GameBoard<T>::down()
{
	slide(&GameBoard::downwards);
}

template<typename T>
void GameBoard<T>::up()
{
	slide(&GameBoard::upwards);
}

template<typename T>
void GameBoard<T>::setCell(CellPosition cell, T value)
{
	board[cell.row][cell.col] = value;
}

template<typename T>
void GameBoard<T>::slide(
	T &(GameBoard::*traversal)(size_type index, size_type cell))
{
	for (size_type index = 0; index < N; ++index) {
		const auto innerTraversal =
			[=](size_type cell) -> decltype(auto) { 
				return (this->*traversal)(index, cell); 
			};
		std::vector<bool> hasBeenCombined(N, false);
		for (
			size_type adjacentCell = N - 1;
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
typename GameBoard<T>::size_type GameBoard<T>::findNextNonzeroOrLastCell(
	std::function<T(size_type cell)> traversal,
	size_type start)
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
T &GameBoard<T>::toTheRight(size_type index, size_type cell)
{
	return board[index][cell];
}

template <typename T>
T &GameBoard<T>::toTheLeft(size_type index, size_type cell)
{
	return board[index][N - 1 - cell];
}

template <typename T>
T &GameBoard<T>::upwards(size_type index, size_type cell)
{
	return board[N - 1 - cell][index];
}

template <typename T>
T &GameBoard<T>::downwards(size_type index, size_type cell)
{
	return board[cell][index];
}

template class GameBoard<int>;