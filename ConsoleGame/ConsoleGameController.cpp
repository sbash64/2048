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
	game.moveRight();
	device->print(formatter->asString(game));
}
