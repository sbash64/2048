#pragma once

#include "console_game_exports.h"
#include "GameModel.h"
#include "Formatter.h"
#include "RandomNumberGenerator.h"
#include <GameBoard.h>
#include <memory>

class Game2048Model : public GameModel {
	GameBoard<int> game;
	std::shared_ptr<Formatter> formatter;
	std::shared_ptr<RandomNumberGenerator> generator;
public:
	CONSOLEGAME_API Game2048Model(
		GameBoard<int>,
		std::shared_ptr<Formatter>,
		std::shared_ptr<RandomNumberGenerator>);
	CONSOLEGAME_API std::string newGame() override;
	CONSOLEGAME_API std::string down() override;
	CONSOLEGAME_API std::string up() override;
	CONSOLEGAME_API std::string left() override;
	CONSOLEGAME_API std::string right() override;
private:
	std::string nextMove();
};