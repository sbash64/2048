#pragma once

#ifdef CONSOLEGAMEMODEL_EXPORTS
    #define CONSOLEGAMEMODEL_API __declspec(dllexport)
#else
    #define CONSOLEGAMEMODEL_API __declspec(dllimport)
#endif

#include "RandomNumberGenerator.h"
#include "Formatter.h"
#include <ConsoleGameControl/GameModel.h>
#include <memory>

class Game2048Model : public GameModel {
    GameBoard<int> game;
    std::shared_ptr<Formatter> formatter;
    std::shared_ptr<RandomNumberGenerator> generator;
public:
    CONSOLEGAMEMODEL_API Game2048Model(
        GameBoard<int>,
        std::shared_ptr<Formatter>,
        std::shared_ptr<RandomNumberGenerator>);
    CONSOLEGAMEMODEL_API std::string newGame() override;
    CONSOLEGAMEMODEL_API std::string down() override;
    CONSOLEGAMEMODEL_API std::string up() override;
    CONSOLEGAMEMODEL_API std::string left() override;
    CONSOLEGAMEMODEL_API std::string right() override;
private:
    std::string nextMove();
};