#ifndef SPACEINVADERS_BONUSENTITY_H
#define SPACEINVADERS_BONUSENTITY_H

#include "Entity.h"

namespace Abs{
    class BonusEntity: public Entity {
    public:
        virtual void visualize() = 0;
    };
}

#endif