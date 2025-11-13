//
// Created by gavin on 11/13/2025.
//

#include "Button.h"

#include <iostream>

NMGP::Button::Button(const std::string &name, const std::string &text, const sf::Font &font, const sf::Vector2f pos,
    const sf::Texture &texture, sf::Vector2f scale) : buttonSprite(texture) {
    buttonName = name;
    buttonText = text;
    buttonFont = font;
    buttonPos = pos;
    buttonTexture = texture;
    buttonSprite.setScale(scale);
    buttonSprite.setPosition(buttonPos);
    buttonSprite.setOrigin(
        sf::Vector2f(buttonSprite.getTexture().getSize().x / 2.0f, buttonSprite.getTexture().getSize().y / 2.0f)
    );
    std::cout << buttonName << " initialized at " << buttonSprite.getPosition().x << ", " << buttonSprite.getPosition().
            y << std::endl;
} ;
std::string NMGP::Button::getButtonName() const { return buttonName; };
std::string NMGP::Button::getButtonText() const { return buttonText; };
sf::Font NMGP::Button::getFont() const { return buttonFont; };
sf::Vector2f NMGP::Button::getButtonPos() const { return buttonPos; };
sf::Sprite NMGP::Button::getButtonSprite() const { return buttonSprite; };
NMGP::ButtonState NMGP::Button::getButtonState() const { return buttonState; };
NMGP::ButtonType NMGP::Button::getButtonType() const { return buttonType; };
int NMGP::Button::onClick() {
    if (buttonState != NMGP::ButtonState::PRESSED ||
        buttonState != NMGP::ButtonState::DISABLED)
    {
        buttonState = NMGP::ButtonState::PRESSED;
        std::cout << buttonName << std::endl;
        buttonState = NMGP::ButtonState::HOVER;
        return 1;
    }
    return 0;
};
int NMGP::Button::onHover() {
    if (buttonState != NMGP::ButtonState::DISABLED) {
        buttonState = NMGP::ButtonState::HOVER;
        std::cout << buttonName << std::endl;
        return 1;
    }
    return 0;
};
int NMGP::Button::offHover() {
    if (buttonState != NMGP::ButtonState::DISABLED) {
        buttonState = NMGP::ButtonState::DEFAULT;
        std::cout << buttonName << std::endl;
        return 1;
    }
    return 0;
};