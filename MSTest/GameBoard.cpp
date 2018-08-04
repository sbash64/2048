#include "stdafx.h"
#include "GameBoard.h"

GameBoard::GameBoard(std::vector<std::vector<double>> board) :
	board(board)
{
}

const std::vector<std::vector<double>>& GameBoard::getBoard()
{
	return board;
}

void GameBoard::moveRight()
{
}
