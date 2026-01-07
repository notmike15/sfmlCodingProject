//
// Created by gavin-lp on 11/16/2025.
//

#ifndef SFMLCODINGPROJECT_OBJECT_H
#define SFMLCODINGPROJECT_OBJECT_H
#include <utility>

#include <string>
#include "Constants.h"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace NMGP {
    // Used as a base class for most drawable objects
    class Object {
    public:
        // Sets the order objects are displayed
        // and interacted with
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
            LAYER objLayer;
            sf::Vector2f objPos;
            const sf::Vector2f OBJECT_SCALE = sf::Vector2f(8.f, 8.f);
        public:
            Object();
            virtual ~Object() = default;
            Object(std::string name, LAYER layer, sf::Vector2f pos);
            Object(LAYER layer, sf::Vector2f pos) :
                Object(Constants::DEFAULT_OBJECT_NAME, layer, pos) {};

            LAYER getLayer() const { return objLayer; };
            void setLayer(LAYER layer) { objLayer = layer; };

            // Virtual so derived classes can change which
            // drawable object will have its position updated
            virtual void setPosition(sf::Vector2f pos);
            sf::Vector2f getPosition() const { return objPos; };
            void setObjectName(const std::string &name) { objName = name; };
            std::string getObjectName() { return objName; };
            // Most drawable objects will not need to process a click
            // but this allows processing derived class clicks properly
            virtual std::int32_t onClick() { return -1; };
            virtual std::int32_t onHover() { return -1; };
            virtual std::int32_t offHover() { return -1; };
            // Virtual so derived classes can change which
            // drawable object will be displayed on draw
            virtual sf::Drawable* getDrawable() = 0;
            virtual sf::Sprite getSprite() = 0;
    };
}

#endif //SFMLCODINGPROJECT_OBJECT_H