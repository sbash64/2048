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
	const std::size_t N;
public:
	GAME_API GameBoard(std::vector<std::vector<double>> board);
	GAME_API const std::vector<std::vector<double>> &getBoard() const noexcept;
	GAME_API void moveRight();
	GAME_API void moveLeft();
	GAME_API void moveDown();
	GAME_API void moveUp();
	GAME_API void setCell(std::size_t row, std::size_t col, double value);

private:
	void moveAlong(double &(GameBoard::*)(std::size_t slice, std::size_t element));
	double &toTheRight(std::size_t slice, std::size_t element);
	double &toTheLeft(std::size_t slice, std::size_t element);
	double &upwards(std::size_t slice, std::size_t element);
	double &downwards(std::size_t slice, std::size_t element);
};