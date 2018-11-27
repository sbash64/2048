#pragma once

#ifdef CONSOLEGAMECONTROL_EXPORTS
    #define CONSOLEGAMECONTROL_API __declspec(dllexport)
#else
    #define CONSOLEGAMECONTROL_API __declspec(dllimport)
#endif

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