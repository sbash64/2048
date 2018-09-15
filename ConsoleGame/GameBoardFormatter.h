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
	CONSOLEGAME_API std::string as_string(const GameBoard &board);
};