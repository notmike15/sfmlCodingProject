//
// Created by gavin on 11/24/2025.
//

#include "TexturedObject.h"

NMGP::TexturedObject::TexturedObject() :  objSprite(Constants::DEFAULT_TEXTURE) {
    objTexture = Constants::DEFAULT_TEXTURE;
    objPos = sf::Vector2f(0.f, 0.f);
    objSprite.setPosition(objPos);
}

NMGP::TexturedObject::TexturedObject(std::string name, const sf::Texture &texture, LAYER layer,
    sf::Vector2f pos) : objSprite(texture), Object(name, layer, pos){
    objTexture = texture;
    objSprite.setTexture(objTexture);
    objSprite.setScale(OBJECT_SCALE);
    TexturedObject::setPosition(pos);
    objSprite.setOrigin(
        sf::Vector2f(static_cast<float>(objSprite.getTexture().getSize().x) / 2.0f,
            static_cast<float>(objSprite.getTexture().getSize().y) / 2.0f)
    );
}

void NMGP::TexturedObject::setPosition(sf::Vector2f pos) {
    objPos = pos;
    objSprite.setPosition(objPos);
}