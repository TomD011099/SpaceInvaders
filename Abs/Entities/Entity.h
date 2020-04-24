#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

#include "../../GameConstants.h"

namespace Abs {
    class Entity {
    public:
        Entity(double, double, double, double);

        virtual void visualize() = 0;

        virtual ~Entity() = default;

        virtual double getXPos();

        virtual double getYPos();

        virtual void move(double, double);

        double getWidth() const;

        double getHeight() const;

    protected:
        double xPos;     //Position of center
        double yPos;     //Position of center
        double width;
        double height;
    };
}

#endif