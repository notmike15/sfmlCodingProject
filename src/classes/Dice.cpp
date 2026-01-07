//
// Created by gavin on 1/7/2026.
//

#include "Dice.h"

namespace NMGP {
    Dice::Dice(std::string name, const sf::Texture &texture, LAYER layer,
        sf::Vector2f pos, sf::Vector2f scale, sf::Clock *clock) : AnimatedObject(name, texture, layer, pos, scale)
    {
        srand(time(0));
        numberOfSprites = 8;
        currentSprite = 0;
        setTextureRect(
            sf::IntRect({currentSprite * TEXTURE_WIDTH, 0}, {TEXTURE_WIDTH, TEXTURE_HEIGHT})
        );
        textureRect.position = {currentSprite * TEXTURE_WIDTH, 0};
        textureRect.size = {32, 32};
        objSprite.setTextureRect(getTextureRect());
        objSprite.setOrigin({16.f, 0});
        state = ROLLING;
        clockTime = clock;
    }
    sf::Drawable* Dice::getDrawable() {
        if (state == STATIC) {
            textureRect.position = {currentSprite * TEXTURE_WIDTH, 0};
            textureRect.size = {32, 32};
            objSprite.setTextureRect(getTextureRect());
            objSprite.setOrigin({16.f, 0});
        }
        else {
            timeRolling += clockTime->restart();
            if (timeRolling.asSeconds() >= 2.f) {
                endRoll();
            }
            else if (timeRolling.asMicroseconds() % 15 == 0) {
                int randomNumber = rand() % 4;
                if (randomNumber < 3) {
                    currentSprite = currentSprite == 6 ? 7 : 6;
                }
                else {
                    currentSprite = rand() % 6;
                }
                textureRect.position = {currentSprite * TEXTURE_WIDTH, 0};
                textureRect.size = {32, 32};
                objSprite.setTextureRect(getTextureRect());
                objSprite.setOrigin({16.f, 0});
            }
        }
        // objSprite.setPosition({1000.f, 50.f});
        return &objSprite;
    }
    void Dice::startRoll() {
        state = ROLLING;
    }
    void Dice::endRoll() {
        value = rand() % 6;
        currentSprite = value;
        timeRolling = sf::Time::Zero;
        state = STATIC;
    }
}
