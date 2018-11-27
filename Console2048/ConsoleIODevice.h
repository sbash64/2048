#pragma once

#include <ConsoleGameControl/IODevice.h>

class ConsoleIODevice : public IODevice {
    int key;
public:
    void print(std::string) override;
    bool rightArrowKeyPressed() override;
    bool downArrowKeyPressed() override;
    bool leftArrowKeyPressed() override;
    bool upArrowKeyPressed() override;
    void getKeyPress() override;
};
