//
// Created by gavin-lp on 12/9/2025.
//

#ifndef SFMLCODINGPROJECT_ANIMATEDOBJECT_H
#define SFMLCODINGPROJECT_ANIMATEDOBJECT_H
#include "TexturedObject.h"

namespace NMGP {
    class AnimatedObject : public NMGP::TexturedObject{
    public:
        enum AnimType {
            DEFAULT = 0
        };
    protected:
        const int TEXTURE_WIDTH = 32;
        const int TEXTURE_HEIGHT = 32;
        sf::IntRect textureRect = sf::IntRect({0, 0}, {TEXTURE_WIDTH, TEXTURE_HEIGHT});
        int numberOfSprites;
        int currentSprite;
    public:
        AnimatedObject(std::string name, const sf::Texture &texture, LAYER layer,
        sf::Vector2f pos, sf::Vector2f scale) : TexturedObject::TexturedObject(name, texture, layer, pos, scale) {};
        AnimatedObject() : AnimatedObject("default", Constants::DEFAULT_TEXTURE, LAYER::BACKGROUND,
            {0.f, 0.f}, {Constants::PIXEL_RATIO, Constants::PIXEL_RATIO}) {
            numberOfSprites = 0;
            currentSprite = 0;
        };
        sf::IntRect getTextureRect() { return textureRect; }
        void setTextureRect(sf::IntRect rect) { textureRect = rect; }
        void setSpriteCountInSpriteSheet(int newSpritePosition);
        int getNumberOfSprites() const { return numberOfSprites; }
        int getCurrentSprite() const { return currentSprite; }
    };
}


#endif //SFMLCODINGPROJECT_ANIMATEDOBJECT_H