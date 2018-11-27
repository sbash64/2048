#include "GameBoardAnalyzer.h"

GameBoardAnalyzer::cellIndices GameBoardAnalyzer::openCells(
    const GameBoard<int> &board)
{
    cellIndices cells;
    for (size_type col = 0; col < board.size(); ++col)
        for (size_type row = 0; row < board.size(); ++row)
            if (board[row][col] == 0)
                cells.push_back(row + col * board.size());
    return cells;
}

bool GameBoardAnalyzer::canMove(const GameBoard<int> &board) {
    for (size_type row = 0; row < board.size(); ++row)
        for (size_type col = 0; col < board.size(); ++col) {
            if (board[row][col] == 0)
                return true;
            if (
                col < board.size() - 1 && 
                board[row][col] == board[row][col + 1]
            )
                return true;
            if (
                row < board.size() - 1 &&
                board[row][col] == board[row + 1][col]
            )
                return true;
        }
    return false;
}
