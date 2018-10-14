#include "ConsoleGameController.h"
#include <GameBoardAnalyzer.h>

ConsoleGameController::ConsoleGameController(
	GameBoard game,
	std::shared_ptr<Formatter> formatter,
	std::shared_ptr<IODevice> device,
	std::shared_ptr<RandomNumberGenerator> generator) :
	game(std::move(game)),
	formatter(std::move(formatter)),
	device(std::move(device)),
	generator(std::move(generator))
{
	if (GameBoardAnalyzer{}.canMove(this->game))
		printGameBoardWithHeader("Press an arrow key to play.\n\n");
	else
		printGameBoardWithHeader(
			"Wow. That's unfortunate. You didn't even get to play!\n\n");
}

void ConsoleGameController::printGameBoardWithHeader(std::string header)
{
	device->print(header + formatter->asString(game) + "\n\n");
}

void ConsoleGameController::next()
{
	device->getKeyPress();
	if (device->rightArrowKeyPressed())
		game.moveRight();
	else if (device->downArrowKeyPressed())
		game.moveDown();
	else if (device->leftArrowKeyPressed())
		game.moveLeft();
	else if (device->upArrowKeyPressed())
		game.moveUp();
	else
	{
		printGameBoardWithHeader(
			"Unrecognized key pressed.\n"
			"Press an arrow key to play.\n\n");
		return;
	}
	const auto openCells = GameBoardAnalyzer{}.openCells(game);
	const auto x = generator->randomIntBetween(0, openCells.size() - 1);
	game.setCell(openCells[x] % game.size(), openCells[x] / game.size(), 2);
	if (GameBoardAnalyzer{}.canMove(game))
		printGameBoardWithHeader("");
	else
		printGameBoardWithHeader("No more moves can be done. Game over.\n\n");
}
