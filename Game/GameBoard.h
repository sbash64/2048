#pragma once
#include <vector>
#include <functional>

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
	class InvalidBoard {};
	GAME_API explicit GameBoard(std::vector<std::vector<double>> board);
	GAME_API const std::vector<double> &operator[](std::size_t row) const;
	GAME_API std::size_t size() const;
	GAME_API void slideRight();
	GAME_API void slideLeft();
	GAME_API void slideDown();
	GAME_API void slideUp();
	GAME_API void setCell(std::size_t row, std::size_t col, double value);

private:
	void slide(
		double &(GameBoard::*)(std::size_t slice, std::size_t element));
	double findNextNonzeroOrLastCell(
		std::function<double(std::size_t cell)> direction,
		double start);
	double &toTheRight(std::size_t slice, std::size_t element);
	double &toTheLeft(std::size_t slice, std::size_t element);
	double &upwards(std::size_t slice, std::size_t element);
	double &downwards(std::size_t slice, std::size_t element);
};