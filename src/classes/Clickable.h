//
// Created by gavin on 11/13/2025.
//

#ifndef SFMLCODINGPROJECT_CLICKABLE_H
#define SFMLCODINGPROJECT_CLICKABLE_H
#include <utility>

#include "Object.h"
#include "SFML/Window/Window.hpp"

namespace NMGP {
    class Clickable : public Object {
    public:
        Clickable(sf::Texture texture, LAYER layer, sf::Vector2f pos, sf::Vector2f scale)  :
            Object(std::move(texture), layer, pos, scale) {};
        ~Clickable() override = default;

        virtual int onClick() = 0;
        virtual int onHover() = 0;
        virtual int offHover() = 0;
    };
}

#endif //SFMLCODINGPROJECT_CLICKABLE_H