#include "GameBoardFormatter.h"
#include <sstream>
#include <algorithm>

static int digits(int number)
{
	if (number == 0)
		return 1;
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
	const auto maxDigits = maxDigitsInEachColumn(board);
	for (size_t row = 0; row < board.size(); ++row)
		for (size_t col = 0; col < board.size(); ++col)
		{
			for (
				int i = 0; 
				i < maxDigits[col] - digits(board[row][col]);
				++i
				)
				stream << " ";
			stream << board[row][col];
			if (col == board.size() - 1)
				if (row == board.size() - 1)
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
	std::vector<int> maxDigits;
	for (size_t col = 0; col < board.size(); ++col)
	{
		double max = 0;
		for (size_t row = 0; row < board.size(); ++row)
			max = std::max(max, board[row][col]);
		maxDigits.push_back(digits(max));
	}
	return maxDigits;
}
