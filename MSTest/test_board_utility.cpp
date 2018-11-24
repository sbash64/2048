#include "test_board_utility.h"

GameBoard<int>::Board rotateClockwise(GameBoard<int>::Board board) {
	auto rotated{ board };
	using size_type = GameBoard<int>::size_type;
	for (size_type row = 0; row < rotated.size(); ++row)
		for (size_type col = 0; col < rotated[row].size(); ++col)
			rotated[row][col] = (*(board.end() - col - 1))[row];
	return rotated;
}
