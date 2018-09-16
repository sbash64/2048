#include "ConsoleGameController.h"

ConsoleGameController::ConsoleGameController(
	GameBoard game,
	std::shared_ptr<Formatter> formatter,
	std::shared_ptr<IODevice> device) :
	game(std::move(game)),
	formatter(std::move(formatter)),
	device(std::move(device))
{
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
		header = "Unrecognized key pressed. Press an arrow key to play.\n\n";
	device->print(header + formatter->asString(game));
}
