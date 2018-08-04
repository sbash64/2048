#pragma once
#include <vector>

class GameBoard
{
public:
	GameBoard(std::vector<std::vector<double>> board);
	const std::vector<std::vector<double>> &getBoard();
	void moveRight();
};