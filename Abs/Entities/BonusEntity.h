#ifndef SPACEINVADERS_BONUSENTITY_H
#define SPACEINVADERS_BONUSENTITY_H

#include "Entity.h"

namespace Abs{
    class BonusEntity: public Entity {
    public:
        BonusEntity(ENTITY, double, double, double, double);

        virtual void visualize() = 0;

        void move(double, double);

        ENTITY getEntity();

    private:
        ENTITY entity;
    };
}

#endif