#pragma once

#include "console_game_control_exports.h"
#include "GameModel.h"
#include "IODevice.h"
#include <memory>

class ConsoleGameController {
	std::shared_ptr<GameModel> model;
	std::shared_ptr<IODevice> device;
public:
	CONSOLEGAMECONTROL_API ConsoleGameController(
		std::shared_ptr<GameModel> model,
		std::shared_ptr<IODevice> device);
	CONSOLEGAMECONTROL_API void next();
};