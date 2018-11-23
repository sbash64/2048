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
	using Row = std::vector<T>;
	using Board = std::vector<Row>;
	using size_type = typename std::vector<T>::size_type;
	// Order important for construction.
	Board board;
	const size_type N;
public:
	class InvalidBoard {};
	GAME_API explicit GameBoard(Board);
	GAME_API const Row &operator[](size_type row) const;
	GAME_API size_type size() const;
	GAME_API void slideRight();
	GAME_API void slideLeft();
	GAME_API void slideDown();
	GAME_API void slideUp();
	struct CellPosition {
		size_type row;
		size_type col;
	};
	GAME_API void setCell(CellPosition cell, T value);

private:
	void slide(
		T &(GameBoard::*)(size_type slice, size_type element));
	size_type findNextNonzeroOrLastCell(
		std::function<T(size_type cell)> direction,
		size_type start);
	T &toTheRight(size_type slice, size_type element);
	T &toTheLeft(size_type slice, size_type element);
	T &upwards(size_type slice, size_type element);
	T &downwards(size_type slice, size_type element);
};