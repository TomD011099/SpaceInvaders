#ifndef SPACEINVADERS_NEGBONUS_H
#define SPACEINVADERS_NEGBONUS_H

#include "BonusEntity.h"

namespace Abs{
    class NegBonus: public BonusEntity {
    public:
        virtual void visualize() = 0;
    };
}

#endif