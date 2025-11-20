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

#include "Options.h"

namespace NMGP {
    class Level {
    public:
        enum ACTIVELEVEL {
            MAIN_MENU = 1,
            OPTIONS = 2,
            PLAY = 3
        };
    private:
        std::vector<std::shared_ptr<Object>> objects;
        int levelID;
        ACTIVELEVEL levelActiveView;
    public:
        static bool comp(std::shared_ptr<Object> a, std::shared_ptr<Object> b);
        Level(std::vector<std::shared_ptr<Object>> objs, int id, ACTIVELEVEL lv);
        Level() : Level(std::vector<std::shared_ptr<Object>>(), 0, ACTIVELEVEL::MAIN_MENU) {};
        ~Level();
        [[nodiscard]] int getLevelID() const { return levelID; };
        std::shared_ptr<Object> getObjectById(int id);
        std::shared_ptr<Object> getObjectByName(std::string name);
        std::vector<std::shared_ptr<Object>> getObjects() { return objects; };
        void addObject(std::shared_ptr<Object> object);
        std::shared_ptr<Object> getClickedOn(sf::Vector2f mousePosition);
        void setActiveLevel(ACTIVELEVEL lv);
        [[nodiscard]] ACTIVELEVEL getActiveLevel() const { return levelActiveView; };
        void draw(sf::RenderWindow* window);
    };
}


#endif //SFMLCODINGPROJECT_LEVEL_H