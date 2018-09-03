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

private:
	int getNextNonzeroOrLastColumn(size_t row, size_t col);
	int getNextNonzeroOrLastRow(size_t row, size_t col);
};