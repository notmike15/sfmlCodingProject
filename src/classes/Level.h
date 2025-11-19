//
// Created by gavin-lp on 11/16/2025.
//

#ifndef SFMLCODINGPROJECT_LEVEL_H
#define SFMLCODINGPROJECT_LEVEL_H
#include <vector>

#include "Button.h"
#include "Object.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include <memory>

namespace NMGP {
    class Level {
    private:
        std::vector<std::shared_ptr<Object>> objects;
        int levelID;
    public:
        static bool comp(std::shared_ptr<Object> a, std::shared_ptr<Object> b);
        Level(std::vector<std::shared_ptr<Object>> objs, int id);
        Level() : Level(std::vector<std::shared_ptr<Object>>(), 0) {};
        ~Level();
        int getLevelID() const { return levelID; };
        std::shared_ptr<Object> getObjectById(int id);
        std::shared_ptr<Object> getObjectByName(std::string name);
        std::vector<std::shared_ptr<Object>> getObjects() { return objects; };
        void addObject(std::shared_ptr<Object> object);
        std::shared_ptr<Object> getClickedOn(sf::Vector2f mousePosition);
        void draw(sf::RenderWindow* window);
    };
}


#endif //SFMLCODINGPROJECT_LEVEL_H