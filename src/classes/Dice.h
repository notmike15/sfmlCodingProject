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
            sf::Time timeRolling;
            sf::Clock *clockTime;
        public:
            Dice(std::string name, const sf::Texture &texture, LAYER layer,
                sf::Vector2f pos, sf::Vector2f scale, sf::Clock *clock);
            sf::Drawable* getDrawable() override;
            void startRoll();
            void endRoll();

    };
}


#endif //SFMLCODINGPROJECT_DICE_H