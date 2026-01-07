//
// Created by gavin on 11/24/2025.
//

#ifndef SFMLCODINGPROJECT_TEXTUREDOBJECT_H
#define SFMLCODINGPROJECT_TEXTUREDOBJECT_H
#include "Object.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace NMGP {
    class TexturedObject : public Object{
    protected:
        sf::Texture objTexture;
        sf::Sprite objSprite;
    public:
        TexturedObject();
        TexturedObject(std::string name, const sf::Texture& texture, LAYER layer, sf::Vector2f pos);
        TexturedObject(const sf::Texture& texture, LAYER layer, sf::Vector2f pos) :
            TexturedObject(Constants::DEFAULT_OBJECT_NAME, texture, layer, pos) {};
        sf::Texture getTexture() { return objTexture; };
        sf::Sprite getSprite() override { return objSprite; };
        void setTexture(sf::Texture texture) { objTexture = std::move(texture); };
        void setSprite(sf::Sprite sprite) { objSprite = std::move(sprite); };
        sf::Drawable* getDrawable() { return &objSprite; };
        void setPosition(sf::Vector2f pos) override;
    };
}

#endif //SFMLCODINGPROJECT_TEXTUREDOBJECT_H