//
// Created by gavin on 1/7/2026.
//

#ifndef SFMLCODINGPROJECT_DICE_H
#define SFMLCODINGPROJECT_DICE_H
#include "AnimatedObject.h"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"

namespace NMGP {
    class Dice : public AnimatedObject {
        private:
            enum DiceState {
                STATIC = 0,
                ROLLING = 1
            };
            int value = 0;
            DiceState state = DiceState::STATIC;
            std::int32_t timeRolling;
            std::int32_t *deltaTime;
        public:
            Dice(std::string name, const sf::Texture &texture, LAYER layer,
                sf::Vector2f pos, std::int32_t *dt);
            sf::Drawable* getDrawable() override;
            void startRoll();
            void endRoll();

    };
}


#endif //SFMLCODINGPROJECT_DICE_H