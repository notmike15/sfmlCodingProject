//
// Created by gavin on 1/7/2026.
//

#include "Dice.h"

#include <iostream>

namespace NMGP {
    Dice::Dice(std::string name, const sf::Texture &texture, LAYER layer,
        sf::Vector2f pos, std::int32_t *dt) : AnimatedObject(name, texture, layer, pos)
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
        deltaTime = dt;
        timeRolling = 0;
    }
    sf::Drawable* Dice::getDrawable() {
        if (state == STATIC) {
            textureRect.position = {currentSprite * TEXTURE_WIDTH, 0};
            textureRect.size = {32, 32};
            objSprite.setTextureRect(getTextureRect());
            objSprite.setOrigin({16.f, 0});
        }
        else {
            timeRolling += *deltaTime;
            if (timeRolling >= 2099) {
                endRoll();
            }
            else if ((timeRolling / 10) % 15 == 0) {
                if (!hasSwapped) {
                    hasSwapped = true;
                    int randomNumber = rand() % 4;
                    if (randomNumber < 3) {
                        currentSprite = currentSprite == 6 ? 7 : 6;
                    }
                    else {
                        int newSprite = rand() % 6;
                        currentSprite = newSprite == currentSprite ?
                            (currentSprite == 0 ? 5 : newSprite - 1) : newSprite;
                    }
                    textureRect.position = {currentSprite * TEXTURE_WIDTH, 0};
                    textureRect.size = {32, 32};
                    objSprite.setTextureRect(getTextureRect());
                    objSprite.setOrigin({16.f, 0});
                }
            }
            else {
                hasSwapped = false;
            }
        }
        // objSprite.setPosition({1000.f, 50.f});
        return &objSprite;
    }
    void Dice::startRoll() {
        state = ROLLING;
    }
    void Dice::endRoll() {
        hasSwapped = false;
        value = rand() % 6;
        currentSprite = value;
        timeRolling = 0;
        state = STATIC;
    }
    int Dice::onClick() {
        dicePressed();
        return -1;
    }
    void Dice::dicePressed() {
        if (state == STATIC) {
            startRoll();
        }
    }
}
