#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include "../../GameConstants.h"

namespace Abs {
    class Entity {
    public:
        Entity(float, float, int, int);

        virtual void visualize() = 0;

        virtual int getXPos();

        virtual int getYPos();

        virtual void update(EVENT) = 0;

    protected:
        float xPos;
        float yPos;
        int width;
        int height;
    };
}

#endif