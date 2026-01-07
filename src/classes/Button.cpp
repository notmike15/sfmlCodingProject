//
// Created by gavin on 11/13/2025.
//

#include "Button.h"

#include <iostream>

#include "Object.h"

NMGP::Button::Button(const std::string &name, const std::string &text, LAYER layer, const sf::Font &font, const sf::Vector2f pos,
                     const sf::Texture &texture, ButtonType btype) : TexturedObject(name, texture, layer, pos)  {
    buttonType = btype;
    buttonState = ButtonState::DEFAULT;
    buttonName = name;
    buttonText = text;
    buttonFont = font;

} ;
std::string NMGP::Button::getButtonName() const { return buttonName; };
std::string NMGP::Button::getButtonText() const { return buttonText; };
sf::Font NMGP::Button::getFont() const { return buttonFont; };
sf::Vector2f NMGP::Button::getButtonPos() const { return objPos; };
sf::Sprite NMGP::Button::getButtonSprite() const { return objSprite; };
NMGP::ButtonState NMGP::Button::getButtonState() const { return buttonState; };
NMGP::ButtonType NMGP::Button::getButtonType() const { return buttonType; };
int NMGP::Button::onClick() {
    if (buttonState != NMGP::ButtonState::PRESSED &&
        buttonState != NMGP::ButtonState::DISABLED)
    {
        buttonState = NMGP::ButtonState::PRESSED;
        std::cout << buttonName << std::endl;
        buttonState = NMGP::ButtonState::HOVER;
        switch (buttonType) {
            case ButtonType::MENU_BUTTON:
                return Constants::ButtonClicks::MAIN_MENU_PRESSED;
            case ButtonType::PLAY_BUTTON:
                return Constants::ButtonClicks::PLAY_BUTTON_PRESSED;
            case ButtonType::OPTIONS_BUTTON:
                return Constants::ButtonClicks::OPTIONS_PRESSED;
            default:
                return Constants::ButtonClicks::MAIN_MENU_PRESSED;
        }
    }
    return -99;
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