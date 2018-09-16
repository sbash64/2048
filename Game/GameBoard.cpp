#include "GameBoard.h"

template<std::size_t N>
GameBoard<N>::GameBoard(std::array<std::array<double, N>, N> board) :
	board(std::move(board))
{
	if (N == 0)
		throw std::runtime_error("Empty board.");
}

template<std::size_t N>
const std::array<std::array<double, N>, N> &GameBoard<N>::getBoard() const noexcept
{
	return board;
}

template<std::size_t N>
void GameBoard<N>::moveRight()
{
	moveAlong(&GameBoard::toTheRight);
}

template<std::size_t N>
void GameBoard<N>::moveLeft()
{
	moveAlong(&GameBoard::toTheLeft);
}

template<std::size_t N>
void GameBoard<N>::moveDown()
{
	moveAlong(&GameBoard::downwards);
}

template<std::size_t N>
void GameBoard<N>::moveUp()
{
	moveAlong(&GameBoard::upwards);
}

template<std::size_t N>
void GameBoard<N>::moveAlong(
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

template<std::size_t N>
double &GameBoard<N>::toTheRight(size_t slice, size_t element)
{
	return board[slice][element];
}

template<std::size_t N>
double &GameBoard<N>::toTheLeft(size_t slice, size_t element)
{
	return board[slice][N - 1 - element];
}

template<std::size_t N>
double &GameBoard<N>::upwards(size_t slice, size_t element)
{
	return board[N - 1 - element][slice];
}

template<std::size_t N>
double &GameBoard<N>::downwards(size_t slice, size_t element)
{
	return board[element][slice];
}

