#ifndef SPACEINVADERS_BONUSENTITY_H
#define SPACEINVADERS_BONUSENTITY_H

#include "Entity.h"

namespace Abs{
    class BonusEntity: public Entity {
    public:
        BonusEntity(ENTITY, float, float, float, float);

        virtual void visualize() = 0;

        void move(float, float);

        ENTITY getEntity();

    private:
        ENTITY entity;
    };
}

#endif