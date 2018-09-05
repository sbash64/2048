#pragma once
#include <vector>

#ifdef GAME_EXPORTS
	#define GAME_API __declspec(dllexport)
#else
	#define GAME_API __declspec(dllimport)
#endif

class GameBoard
{
	// Order important for construction.
	std::vector<std::vector<double>> board;
	const size_t N;
public:
	GAME_API GameBoard(std::vector<std::vector<double>> board);
	GAME_API const std::vector<std::vector<double>> &getBoard();
	GAME_API void moveRight();
	GAME_API void moveLeft();
	GAME_API void moveDown();
	GAME_API void moveUp();

private:
	void moveAlong(double &(GameBoard::*)(size_t range, size_t element));
	double &toTheRight(size_t range, size_t element);
	double &toTheLeft(size_t range, size_t element);
	double &upwards(size_t range, size_t element);
	double &downwards(size_t range, size_t element);
	size_t nextNonzeroOrLastColumn(size_t row, size_t col);
	size_t previousNonzeroOrFirstColumn(size_t row, size_t col);
	size_t nextNonzeroOrLastRow(size_t row, size_t col);
	size_t previousNonzeroOrFirstRow(size_t row, size_t col);
};