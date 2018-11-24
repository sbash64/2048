#pragma once

#include "console_game_exports.h"
#include "GameModel.h"
#include "IODevice.h"
#include <memory>

class ConsoleGameController {
	std::shared_ptr<GameModel> model;
	std::shared_ptr<IODevice> device;
public:
	CONSOLEGAME_API ConsoleGameController(
		std::shared_ptr<GameModel> model,
		std::shared_ptr<IODevice> device);
	CONSOLEGAME_API void next();
};