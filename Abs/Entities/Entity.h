#ifndef SPACEINVADERS_ENTITY_H
#define SPACEINVADERS_ENTITY_H

namespace Abs {
    class Entity {
    public:
        Entity(float, float);

        virtual void visualize() = 0;

        virtual int getXPos();

        virtual int getYPos();

        virtual void update(int) = 0;

    protected:
        float xPos;
        float yPos;
    };
}

#endif