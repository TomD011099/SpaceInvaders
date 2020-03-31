#ifndef SPACEINVADERS_CONTROLLER_H
#define SPACEINVADERS_CONTROLLER_H

#include "../GameConstants.h"
#include <vector>

namespace Abs {
    class Controller {
    public:
        virtual std::vector<EVENT> pollEvents() = 0;
    };
}

#endif