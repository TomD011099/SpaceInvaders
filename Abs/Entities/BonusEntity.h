#ifndef SPACEINVADERS_BONUSENTITY_H
#define SPACEINVADERS_BONUSENTITY_H

#include "Entity.h"

namespace Abs {
    /**
     * The abstract bonusentity, implement this to use it for a specific engine
     */
    class BonusEntity : public Entity {
    public:
        BonusEntity(ENTITY, double, double, double, double);

        void move(double, double);

        ENTITY getEntity();

    protected:
        ENTITY entity;      //The specific type of bonusentity (POSBONUS or NEGBONUS)
    };
}

#endif