#pragma once

#include <vector>
#include <ConsoleGameModel/Formatter.h>

#ifdef CONSOLEGAMEFORMATTING_EXPORTS
	#define CONSOLEGAMEFORMATTING_API __declspec(dllexport)
#else
	#define CONSOLEGAMEFORMATTING_API __declspec(dllimport)
#endif

class GameBoardFormatter : public Formatter {
	using size_type = GameBoard<int>::size_type;
public:
	CONSOLEGAMEFORMATTING_API std::string asString(
		const GameBoard<int> &board) override;
private:
	std::vector<int> maxDigitsInEachColumn(const GameBoard<int> &board);
};