#pragma once

#include <GameBoard.h>
#include <string>

#ifdef CONSOLEGAMEFORMATTING_EXPORTS
#define CONSOLEGAMEFORMATTING_API __declspec(dllexport)
#else
#define CONSOLEGAMEFORMATTING_API __declspec(dllimport)
#endif

class GameBoardFormatter
{
public:
	CONSOLEGAMEFORMATTING_API std::string asString(const GameBoard &board);
private:
	std::vector<int> maxDigitsInEachColumn(const GameBoard &board);
};