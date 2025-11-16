//
// Created by gavin-lp on 11/16/2025.
//

#ifndef SFMLCODINGPROJECT_OBJECT_H
#define SFMLCODINGPROJECT_OBJECT_H
#include <utility>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace NMGP {
    class Object {
        public:
            enum LAYER {
                BACKGROUND = 0,
                SEMI_BACKGROUND = 1,
                SPRITE = 2,
                SPRITE_TOP = 3,
                BUTTON = 4,
                TOP = 5
            };
        protected:
            sf::Texture objTexture;
            sf::Sprite objSprite;
            LAYER objLayer;
            sf::Vector2f objPos;
        public:
            Object(sf::Texture texture, LAYER layer, sf::Vector2f pos, sf::Vector2f scale);
            virtual ~Object() = default;
            sf::Texture getTexture() { return objTexture; };
            sf::Sprite getSprite() { return objSprite; };
            LAYER getLayer() const { return objLayer; };
            void setLayer(LAYER layer) { objLayer = layer; };
            void setTexture(sf::Texture texture) { objTexture = std::move(texture); };
            void setSprite(sf::Sprite sprite) { objSprite = std::move(sprite); };
    };
}

#endif //SFMLCODINGPROJECT_OBJECT_H