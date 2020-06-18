#ifndef SPACEINVADERS_SDLBONUSENTITY_H
#define SPACEINVADERS_SDLBONUSENTITY_H

#include "../../Abs/Entities/BonusEntity.h"
#include "../Window/SDLWindow.h"

namespace Sdl {
    /**
     * An implementation of Abs::BonusEntity
     */
    class SDLBonusEntity : public Abs::BonusEntity {
    public:
        SDLBonusEntity(SDLWindow*, ENTITY, double, double, double, double);

        ~SDLBonusEntity() = default;

        void visualize();

    private:
        SDLWindow* window;      //The SDL game window
    };
}

#endif