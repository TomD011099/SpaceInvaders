cmake_minimum_required(VERSION 3.15)
project(SpaceInvaders)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(SpaceInvaders main.cpp
        GameConstants.h
        Game.cpp                    Game.h

        Abs/Factory.h
        SDL/SDLFactory.cpp          SDL/SDLFactory.h

        Abs/Controller.h
        SDL/SDLController.cpp       SDL/SDLController.h

        SDL/Window/SDLWindow.cpp    SDL/Window/SDLWindow.h
        SDL/Window/LTexture.cpp     SDL/Window/LTexture.h

        Abs/Entities/Entity.cpp             Abs/Entities/Entity.h
            Abs/Entities/PlayerEntity.cpp       Abs/Entities/PlayerEntity.h
                Abs/Entities/PlayerShip.cpp         Abs/Entities/PlayerShip.h
                SDL/Entities/SDLPlayerShip.cpp      SDL/Entities/SDLPlayerShip.h
                Abs/Entities/PlayerBullet.cpp       Abs/Entities/PlayerBullet.h
                SDL/Entities/SDLPlayerBullet.cpp    SDL/Entities/SDLPlayerBullet.h
            Abs/Entities/EnemyEntity.cpp        Abs/Entities/EnemyEntity.h
                Abs/Entities/EnemyShip.cpp          Abs/Entities/EnemyShip.h
                SDL/Entities/SDLEnemyShip.cpp       SDL/Entities/SDLEnemyShip.h
                Abs/Entities/EnemyBullet.cpp        Abs/Entities/EnemyBullet.h
                SDL/Entities/SDLEnemyBullet.cpp     SDL/Entities/SDLEnemyBullet.h
            Abs/Entities/BonusEntity.cpp        Abs/Entities/BonusEntity.h
                Abs/Entities/PosBonus.cpp           Abs/Entities/PosBonus.h
                SDL/Entities/SDLPosBonus.cpp        SDL/Entities/SDLPosBonus.h
                Abs/Entities/NegBonus.cpp           Abs/Entities/NegBonus.h
                SDL/Entities/SDLNegBonus.cpp        SDL/Entities/SDLNegBonus.h)

target_link_libraries(SpaceInvaders ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)