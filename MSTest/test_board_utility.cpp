#include "stdafx.h"
#include "test_board_utility.h"

template<std::size_t N>
std::array<std::array<double, N>, N> rotateClockwise(
	std::array<std::array<double, N>, N> board)
{
	auto rotated(board);
	for (size_t row = 0; row < rotated.size(); row++)
		for (size_t col = 0; col < rotated[row].size(); col++)
			rotated[row][col] = (*(board.end() - col - 1))[row];
	return rotated;
}

template std::array<std::array<double, 4>, 4> rotateClockwise(
	std::array<std::array<double, 4>, 4> board);
