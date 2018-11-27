#include "ConsoleGameController.h"

ConsoleGameController::ConsoleGameController(
    std::shared_ptr<GameModel> model,
    std::shared_ptr<IODevice> device
) :
    model{ std::move(model) },
    device{ std::move(device) }
{
    this->device->print(this->model->newGame());
}

void ConsoleGameController::next() {
    device->getKeyPress();
    if (device->rightArrowKeyPressed())
        device->print(model->right());
    else if (device->downArrowKeyPressed())
        device->print(model->down());
    else if (device->leftArrowKeyPressed())
        device->print(model->left());
    else if (device->upArrowKeyPressed())
        device->print(model->up());
}
