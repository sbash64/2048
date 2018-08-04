#pragma once
#include <vector>

class GameBoard
{
	std::vector<std::vector<double>> board;
public:
	GameBoard(std::vector<std::vector<double>> board);
	const std::vector<std::vector<double>> &getBoard();
	void moveRight();
};