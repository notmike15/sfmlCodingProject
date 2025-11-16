//
// Created by gavin-lp on 11/16/2025.
//
#include "Object.h"

namespace NMGP {
    Object::Object(sf::Texture texture, LAYER layer, sf::Vector2f pos, sf::Vector2f scale) : objSprite(texture) {
        objTexture = texture;
        objLayer = layer;
        objPos = pos;
        objSprite.setTexture(objTexture);
        objSprite.setPosition(objPos);
        objSprite.setScale(scale);
    }
}