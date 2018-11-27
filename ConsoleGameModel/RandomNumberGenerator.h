#pragma once

#include <common-includes/Interface.h>

class RandomNumberGenerator {
public:
    INTERFACE_OPERATIONS(RandomNumberGenerator);
    virtual int randomIntBetween(int low, int hi) = 0;
};