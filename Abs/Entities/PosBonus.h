#ifndef SPACEINVADERS_POSBONUS_H
#define SPACEINVADERS_POSBONUS_H

#include "BonusEntity.h"

namespace Abs{
    class PosBonus: public BonusEntity {
    public:
        virtual void visualize() = 0;
    };
}

#endif