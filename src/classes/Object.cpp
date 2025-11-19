//
// Created by gavin-lp on 11/16/2025.
//
#include "Object.h"
#include <utility>

namespace NMGP {
    Object::Object() : objSprite(Constants::DEFAULT_TEXTURE) {
        objName = Constants::DEFAULT_OBJECT_NAME;
        objectID = Constants::ERROR_OBJECT_ID;
        objLayer = LAYER::BACKGROUND;
        objTexture = Constants::DEFAULT_TEXTURE;
        objPos = sf::Vector2f(0.f, 0.f);
        objSprite.setPosition(sf::Vector2f(objPos.x, objPos.y));
    }

    Object::Object(std::string name, int id, const sf::Texture& texture, LAYER layer, sf::Vector2f pos, sf::Vector2f scale) : objSprite(texture) {
        objName = std::move(name);
        setObjectID(id);
        objTexture = texture;
        objLayer = layer;
        objPos = pos;
        objSprite.setTexture(objTexture);
        objSprite.setPosition(objPos);
        objSprite.setScale(scale);
    }
    void Object::setObjectID(int id) {
        if (id >= 0) {
            objectID = id;
        }
        else {
            objectID = 0;
        }
    }

}