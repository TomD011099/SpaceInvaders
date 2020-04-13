#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include "../../GameConstants.h"

namespace Abs {
    class Entity {
    public:
        Entity(float, float, float, float);

        virtual void visualize() = 0;

        virtual ~Entity() = default;

        virtual float getXPos();

        virtual float getYPos();

        virtual void move(float, float);

        float getWidth() const;

        float getHeight() const;

    protected:
        float xPos;     //Position of center
        float yPos;     //Position of center
        float width;
        float height;
    };
}

#endif