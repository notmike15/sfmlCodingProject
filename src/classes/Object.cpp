//
// Created by gavin-lp on 11/16/2025.
//
#include "Object.h"
#include <utility>

namespace NMGP {
    Object::Object() {
        objName = Constants::DEFAULT_OBJECT_NAME;
        objLayer = LAYER::BACKGROUND;
    }

    Object::Object(std::string name, LAYER layer, sf::Vector2f pos, sf::Vector2f scale){
        objName = std::move(name);
        objLayer = layer;
        objPos = pos;
        this->Object::setPosition(objPos);
    }

    void Object::setPosition(sf::Vector2f pos) {
        objPos = pos;
    }

}