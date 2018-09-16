#pragma once
#include <array>

#ifdef GAME_EXPORTS
	#define GAME_API __declspec(dllexport)
#else
	#define GAME_API __declspec(dllimport)
#endif

template<std::size_t N>
class GameBoard
{
	std::array<std::array<double, N>, N> board;
public:
	GAME_API GameBoard(std::array<std::array<double, N>, N> board);
	GAME_API const std::array<std::array<double, N>, N> &getBoard() const noexcept;
	GAME_API void moveRight();
	GAME_API void moveLeft();
	GAME_API void moveDown();
	GAME_API void moveUp();

private:
	void moveAlong(
		double &(GameBoard::*)(std::size_t slice, std::size_t element));
	double &toTheRight(std::size_t slice, std::size_t element);
	double &toTheLeft(std::size_t slice, std::size_t element);
	double &upwards(std::size_t slice, std::size_t element);
	double &downwards(std::size_t slice, std::size_t element);
};