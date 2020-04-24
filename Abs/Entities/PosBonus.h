#ifndef SPACEINVADERS_POSBONUS_H
#define SPACEINVADERS_POSBONUS_H

#include "BonusEntity.h"

namespace Abs{
    class PosBonus: public BonusEntity {
    public:
        PosBonus(float, float, float, float);

        virtual void visualize() = 0;
    };
}

#endif