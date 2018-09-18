#pragma once

#include "IODevice.h"
#include "Formatter.h"
#include "RandomNumberGenerator.h"
#include <GameBoard.h>
#include <memory>

#ifdef CONSOLEGAME_EXPORTS
#define CONSOLEGAME_API __declspec(dllexport)
#else
#define CONSOLEGAME_API __declspec(dllimport)
#endif

class ConsoleGameController
{
	GameBoard game;
	std::shared_ptr<Formatter> formatter;
	std::shared_ptr<IODevice> device;
public:
	CONSOLEGAME_API ConsoleGameController(
		GameBoard game,
		std::shared_ptr<Formatter> formatter,
		std::shared_ptr<IODevice> device,
		std::shared_ptr<RandomNumberGenerator> generator);
	CONSOLEGAME_API void next();
};