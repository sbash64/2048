#pragma once

#include <GameBoard.h>
#include <string>

#ifdef CONSOLEGAME_EXPORTS
#define CONSOLEGAME_API __declspec(dllexport)
#else
#define CONSOLEGAME_API __declspec(dllimport)
#endif

class GameBoardFormatter
{
public:
	template<std::size_t N>
	CONSOLEGAME_API std::string asString(const GameBoard<N> &board);
};