//
// Created by gavin-lp on 11/20/2025.
//

#ifndef SFMLCODINGPROJECT_LABEL_H
#define SFMLCODINGPROJECT_LABEL_H
#include "Object.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

namespace NMGP {
    // Used for drawing text to the screen
    class Label : public Object {
    private:
        // Store font, by default it is the downloaded font in resources
        const std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>(Constants::DEFAULT_FONT);
        sf::Text text;
        sf::Color textColor;
    public:
        Label(std::string name, int id, std::string displayText, sf::Color color, sf::Vector2f pos, LAYER layer, int textPointSize);
        Label() : Label("Text", -1, "Text", sf::Color::Blue, {0.f, 0.f}, LAYER::SEMI_BACKGROUND, 16) {}
        sf::Text getText();
        sf::Color getTextColor();
        void setTextColor(sf::Color color);
        void setText(std::string text);

        void setTextPointSize(int textPointSize);
        // Overridden so text can be drawn instead of a sprite/texture
        sf::Drawable* getDrawable() override;
        // Overridden so the text position is updated instead of the sprite's
        void setPosition(sf::Vector2f pos) override;
    };
} // NMGP

#endif //SFMLCODINGPROJECT_LABEL_H