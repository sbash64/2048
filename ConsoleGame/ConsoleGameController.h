#pragma once

#include "IODevice.h"
#include <GameBoard.h>
#include <memory>

#ifdef CONSOLEGAME_EXPORTS
#define CONSOLEGAME_API __declspec(dllexport)
#else
#define CONSOLEGAME_API __declspec(dllimport)
#endif

class ConsoleGameController
{
public:
	CONSOLEGAME_API explicit ConsoleGameController(
		GameBoard game,
		std::shared_ptr<IODevice> device);
};