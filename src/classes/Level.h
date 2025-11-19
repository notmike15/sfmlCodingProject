//
// Created by gavin-lp on 11/16/2025.
//

#ifndef SFMLCODINGPROJECT_LEVEL_H
#define SFMLCODINGPROJECT_LEVEL_H
#include <vector>

#include "Button.h"
#include "Clickable.h"
#include "Object.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace NMGP {
    class Level {
    private:
        std::vector<Object> objects;
        int levelID;
    public:
        static bool comp(Object a, Object b);
        Level(std::vector<Object> objs, int id);
        Level() : Level(std::vector<Object>(), 0) {};
        int getLevelID() const { return levelID; };
        Object getObjectById(int id);
        Object getObjectByName(std::string name);
        std::vector<Object> getObjects() { return objects; };
        void addObject(const Object& object);
        Clickable* getClickedOn(sf::Vector2f mousePosition);
        void draw(sf::RenderWindow* window);
    };
}


#endif //SFMLCODINGPROJECT_LEVEL_H