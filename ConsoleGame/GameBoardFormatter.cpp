#include "GameBoardFormatter.h"
#include <sstream>

template<std::size_t N>
std::string GameBoardFormatter::asString(const GameBoard<N> &board)
{
	std::stringstream stream;
	const auto _board = board.getBoard();
	for (size_t row = 0; row < _board.size(); ++row)
		for (size_t col = 0; col < _board[row].size(); ++col)
		{
			stream << _board[row][col];
			if (col == _board[row].size() - 1)
				if (row == _board.size() - 1)
					;
				else
					stream << "\n";
			else
				stream << " ";
		}
	return stream.str();
}

template CONSOLEGAME_API std::string GameBoardFormatter::asString(const GameBoard<4> &board);
