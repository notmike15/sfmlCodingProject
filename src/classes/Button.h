//
// Created by gavin on 11/13/2025.
//

#ifndef SFMLCODINGPROJECT_BUTTON_H
#define SFMLCODINGPROJECT_BUTTON_H
#include "Constants.h"
#include "Object.h"
#include "TexturedObject.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace NMGP {
    // Used to determine which type of button is instantiated
    enum ButtonType {
        PLAY_BUTTON = 901,
        MENU_BUTTON = 902,
        OPTIONS_BUTTON = 903,
        DICE_BUTTON = 904
    };
    // Used to make sure only processing clicks when active
    enum ButtonState {
        DEFAULT = 0,
        HOVER = 1,
        PRESSED = 2,
        DISABLED = 3
    };
    class Button : public TexturedObject {
        private:
            std::string buttonName;
            std::string buttonText;
            sf::Font buttonFont;
            ButtonType buttonType;
            ButtonState buttonState;
        public:
            Button(const std::string &name, const std::string &text, LAYER layer, const sf::Font &font, sf::Vector2f pos,
                const sf::Texture& texture, ButtonType btype);
            Button(const std::string &name, const std::string &text, LAYER layer, const sf::Font &font, sf::Vector2f pos,
                const sf::Texture& texture) : Button(name, text, layer, font, pos, texture, ButtonType::PLAY_BUTTON) {};
            Button(const std::string& name, const std::string& text) : Button(name, text, LAYER::BUTTON,
                sf::Font(Constants::DEFAULT_FONT_FILE), {0,0}, sf::Texture(Constants::PLAY_BUTTON)) {};

            std::string getButtonName() const;
            std::string getButtonText() const;
            sf::Font getFont() const;
            sf::Vector2f getButtonPos() const;
            sf::Sprite getButtonSprite() const;
            ButtonType getButtonType() const;
            ButtonState getButtonState() const;
            void setButtonState(ButtonState newState) { buttonState = newState; };

            int onClick() override;
            int onHover() override;
            int offHover() override;
    };
}

#endif //SFMLCODINGPROJECT_BUTTON_H