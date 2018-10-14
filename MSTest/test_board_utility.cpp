#include "stdafx.h"
#include "test_board_utility.h"

std::vector<std::vector<double>> rotateClockwise(
	std::vector<std::vector<double>> board)
{
	auto rotated(board);
	for (std::size_t row = 0; row < rotated.size(); ++row)
		for (std::size_t col = 0; col < rotated[row].size(); ++col)
			rotated[row][col] = (*(board.end() - col - 1))[row];
	return rotated;
}
