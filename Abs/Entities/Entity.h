#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include "../../GameConstants.h"

namespace Abs {
    class Entity {
    public:
        Entity(float, float, float, float);

        virtual void visualize() = 0;

        virtual float getXPos();

        virtual float getYPos();

        virtual bool update(EVENT) = 0;

    protected:
        float xPos;
        float yPos;
        float width;
        float height;
    };
}

#endif