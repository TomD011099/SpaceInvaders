#ifndef SPACEINVADERS_NEGBONUS_H
#define SPACEINVADERS_NEGBONUS_H

#include "BonusEntity.h"

namespace Abs{
    class NegBonus: public BonusEntity {
    public:
        NegBonus(float, float, float, float);

        virtual void visualize() = 0;
    };
}

#endif