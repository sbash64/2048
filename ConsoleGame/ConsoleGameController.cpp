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
	if (device->rightArrowKeyPressed())
		game.moveRight();
	else if (device->downArrowKeyPressed())
		game.moveDown();
	else
		game.moveLeft();
	device->print(formatter->asString(game));
}
