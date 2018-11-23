#pragma once
#include <vector>
#include <functional>

#ifdef GAME_EXPORTS
	#define GAME_API __declspec(dllexport)
#else
	#define GAME_API __declspec(dllimport)
#endif

template <typename T>
class GameBoard {
	// Order important for construction.
	std::vector<std::vector<T>> board;
	const std::size_t N;
public:
	class InvalidBoard {};
	GAME_API explicit GameBoard(std::vector<std::vector<T>> board);
	GAME_API const std::vector<T> &operator[](std::size_t row) const;
	GAME_API std::size_t size() const;
	GAME_API void slideRight();
	GAME_API void slideLeft();
	GAME_API void slideDown();
	GAME_API void slideUp();
	struct CellPosition {
		std::size_t row;
		std::size_t col;
	};
	GAME_API void setCell(CellPosition cell, T value);

private:
	void slide(
		T &(GameBoard::*)(std::size_t slice, std::size_t element));
	std::size_t findNextNonzeroOrLastCell(
		std::function<T(std::size_t cell)> direction,
		std::size_t start);
	T &toTheRight(std::size_t slice, std::size_t element);
	T &toTheLeft(std::size_t slice, std::size_t element);
	T &upwards(std::size_t slice, std::size_t element);
	T &downwards(std::size_t slice, std::size_t element);
};