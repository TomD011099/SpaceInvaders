#ifndef SPACEINVADERS_CONTROLLER_H
#define SPACEINVADERS_CONTROLLER_H

#include "../GameConstants.h"
#include <vector>

namespace Abs {
    /**
     * An abstract controller that has to be implemented with the desired input method
     */
    class Controller {
    public:
        virtual ~Controller() = default;

        virtual std::vector<EVENT> pollEvents() = 0;

        virtual bool isQuit() = 0;
    };
}

#endif