#ifndef SPACEINVADERS_POSBONUS_H
#define SPACEINVADERS_POSBONUS_H

#include "BonusEntity.h"

namespace Abs {
    /**
     * An abstract PosBonus to be implemented for use by a specific game engine
     */
    class PosBonus : public BonusEntity {
    public:
        PosBonus(double, double, double, double);
    };
}

#endif