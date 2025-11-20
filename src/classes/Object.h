//
// Created by gavin-lp on 11/16/2025.
//

#ifndef SFMLCODINGPROJECT_OBJECT_H
#define SFMLCODINGPROJECT_OBJECT_H
#include <utility>
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <string>
#include "Constants.h"

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
            std::string objName;
            int objectID;
            sf::Texture objTexture;
            sf::Sprite objSprite;
            LAYER objLayer;
            sf::Vector2f objPos;
        public:
            Object();
            virtual ~Object() = default;
            Object(std::string name, int id, const sf::Texture& texture, LAYER layer, sf::Vector2f pos, sf::Vector2f scale);
            Object(const sf::Texture& texture, LAYER layer, sf::Vector2f pos, sf::Vector2f scale) :
                Object(Constants::DEFAULT_OBJECT_NAME, 0, texture, layer, pos, scale) {};
            sf::Texture getTexture() { return objTexture; };
            sf::Sprite getSprite() { return objSprite; };
            LAYER getLayer() const { return objLayer; };
            void setLayer(LAYER layer) { objLayer = layer; };
            void setTexture(sf::Texture texture) { objTexture = std::move(texture); };
            void setSprite(sf::Sprite sprite) { objSprite = std::move(sprite); };
            void setPosition(sf::Vector2f pos) { objPos = pos; };
            sf::Vector2f getPosition() const { return objPos; };
            void setObjectID(int id);
            int getObjectID() const { return objectID; };
            void setObjectName(const std::string &name) { objName = name; };
            std::string getObjectName() { return objName; };

            virtual int onClick() { return -1; };
            virtual int onHover() { return -1; };
            virtual int offHover() { return -1; };
    };
}

#endif //SFMLCODINGPROJECT_OBJECT_H