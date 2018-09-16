#include "GameBoardFormatter.h"
#include <sstream>
#include <algorithm>

static int digits(int number)
{
	int _digits = 0;
	while (number) {
		number /= 10;
		_digits++;
	}
	return _digits;
}

std::string GameBoardFormatter::asString(const GameBoard &board)
{
	std::stringstream stream;
	const auto _board = board.getBoard();
	const auto maxDigitsInColumn = maxDigitsInEachColumn(board);
	for (size_t row = 0; row < _board.size(); ++row)
		for (size_t col = 0; col < _board.front().size(); ++col)
		{
			for (
				int i = 0; 
				i < maxDigitsInColumn[col] - digits(_board[row][col]); 
				++i
				)
				stream << " ";
			stream << _board[row][col];
			if (col == _board.front().size() - 1)
				if (row == _board.size() - 1)
					;
				else
					stream << "\n";
			else
				stream << " ";
		}
	return stream.str();
}

std::vector<int> GameBoardFormatter::maxDigitsInEachColumn(
	const GameBoard &board)
{
	const auto _board = board.getBoard();
	std::vector<int> maxDigitsInColumn;
	for (size_t col = 0; col < _board.front().size(); ++col)
	{
		double max = 0;
		for (size_t row = 0; row < _board.size(); ++row)
			max = std::max(max, _board[row][col]);
		maxDigitsInColumn.push_back(digits(max));
	}
	return maxDigitsInColumn;
}
