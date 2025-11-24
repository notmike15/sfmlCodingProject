//
// Created by gavin-lp on 11/20/2025.
//

#include "Label.h"

namespace NMGP {
    Label::Label(std::string name, std::string displayText, sf::Color color, sf::Vector2f pos, LAYER layer, int textPointSize) :
        text(*font), Object(name, layer, pos, {1.f, 1.f})
    {
        textColor = color;
        text.setCharacterSize(textPointSize);
        text.setString(displayText);
        this->Label::setPosition(pos);
    }

    sf::Text Label::getText() {
        return text;
    }

    sf::Color Label::getTextColor() {
        return textColor;
    }

    void Label::setTextColor(sf::Color color) {
        textColor = color;
    }

    void Label::setText(std::string text) {
        this->text.setString(text);
    }

    void Label::setTextPointSize(int textPointSize) {
        this->text.setCharacterSize(textPointSize);
    }

    sf::Drawable* Label::getDrawable() {
        return &text;
    }

    void Label::setPosition(sf::Vector2f pos) {
        text.setPosition(pos);
        objPos = pos;
    }

    sf::Sprite Label::getSprite() {
        return sf::Sprite(Constants::DEFAULT_TEXTURE, sf::IntRect(
            {-99, -99}, {0, 0
        }));
    }

} // NMGP