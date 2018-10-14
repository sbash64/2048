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
	this->device->print(
		"Press an arrow key to play.\n\n" + 
		this->formatter->asString(this->game) + "\n\n");
}

void ConsoleGameController::next()
{
	device->getKeyPress();
	std::string header;
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
		header = 
			"Unrecognized key pressed.\n"
			"Press an arrow key to play.\n\n";
		device->print(header + formatter->asString(game) + "\n\n");
		return;
	}
	const auto openCells = GameBoardAnalyzer{}.openCells(game);
	const auto x = generator->randomIntBetween(0, openCells.size() - 1);
	game.setCell(openCells[x] % game.size(), openCells[x] / game.size(), 2);
	device->print(header + formatter->asString(game) + "\n\n");
}
