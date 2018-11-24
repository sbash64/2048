#include "Game2048Model.h"
#include <GameBoardAnalyzer.h>

Game2048Model::Game2048Model(
	GameBoard<int> game,
	std::shared_ptr<Formatter> formatter,
	std::shared_ptr<RandomNumberGenerator> generator
) :
	game{ std::move(game) },
	formatter{ std::move(formatter) },
	generator{ std::move(generator) } {}

std::string Game2048Model::newGame() {
	std::string directions = GameBoardAnalyzer{}.canMove(game)
		? "Press an arrow key to play."
		: "Wow. That's unfortunate. You didn't even get to play!";
	return directions + "\n\n" + formatter->asString(game) + "\n\n";
}

std::string Game2048Model::down() {
	game.slideDown();
	return nextMove();
}

std::string Game2048Model::up() {
	game.slideUp();
	return nextMove();
}

std::string Game2048Model::left() {
	game.slideLeft();
	return nextMove();
}

std::string Game2048Model::right() {
	game.slideRight();
	return nextMove();
}

std::string Game2048Model::nextMove()
{
	GameBoardAnalyzer analyzer{};
	const auto openCells = analyzer.openCells(game);
	const auto x = generator->randomIntBetween(0, openCells.size() - 1);
	game.setCell({ openCells[x] % game.size(), openCells[x] / game.size() }, 2);
	std::string header = analyzer.canMove(game)
		? ""
		: "No more moves can be done. Game over.\n\n";
	return header + formatter->asString(game) + "\n\n";
}
