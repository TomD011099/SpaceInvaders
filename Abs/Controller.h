#ifndef SPACEINVADERS_CONTROLLER_H
#define SPACEINVADERS_CONTROLLER_H

#include "../GameConstants.h"

namespace Abs {
    class Controller {
    public:
        virtual EVENT pollEvents() = 0;
    };
}

#endif