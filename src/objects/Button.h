//
// Created by gavin on 11/13/2025.
//

#ifndef SFMLCODINGPROJECT_BUTTON_H
#define SFMLCODINGPROJECT_BUTTON_H
#include "Clickable.h"
#include "Constants.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace NMGP {
    const sf::Texture play_button_texture(Constants::PLAY_BUTTON);
    enum ButtonType {
        PLAY_BUTTON = 1
    };
    enum ButtonState {
        DEFAULT = 0,
        HOVER = 1,
        PRESSED = 2,
        DISABLED = 3
    };
    class Button : public Clickable {
        private:
            std::string buttonName;
            std::string buttonText;
            sf::Font buttonFont;
            sf::Vector2f buttonPos;
            sf::Texture buttonTexture;
            sf::Sprite buttonSprite;
            ButtonType buttonType;
            ButtonState buttonState;
        public:
            Button(const std::string &name, const std::string &text, const sf::Font &font, sf::Vector2f pos, const sf::Texture& texture);
            // Button(const std::string& name, const std::string& text) : Button(name, text,
            //     sf::Font(Constants::DEFAULT_FONT), {0,0}, sf::Texture(Constants::PLAY_BUTTON)) {};
            std::string getButtonName() const;
            std::string getButtonText() const;
            sf::Font getFont() const;
            sf::Vector2f getButtonPos() const;
            sf::Sprite getButtonSprite() const;
            ButtonType getButtonType() const;
            ButtonState getButtonState() const;
            int onClick() override;
            int onHover() override;
            int offHover() override;
    };
}

#endif //SFMLCODINGPROJECT_BUTTON_H