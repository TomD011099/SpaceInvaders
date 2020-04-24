#ifndef SPACEINVADERS_NEGBONUS_H
#define SPACEINVADERS_NEGBONUS_H

#include "BonusEntity.h"

namespace Abs{
    class NegBonus: public BonusEntity {
    public:
        NegBonus(double, double, double, double);

        virtual void visualize() = 0;
    };
}

#endif