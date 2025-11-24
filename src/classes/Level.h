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
    // Stores the level data for each level
    // For example, we have menu, options and playable area
    class Level {
    public:
        // Used to store which level is currently selected
        // This creates a map in the GameManager object
        enum ACTIVELEVEL {
            MAIN_MENU = 1,
            OPTIONS = 2,
            PLAY = 3
        };
    private:
        // Store all objects to be drawn to the window
        std::vector<std::shared_ptr<Object>> objects;
        std::int32_t levelID;
        ACTIVELEVEL levelActiveView;
    public:
        // Compare by layer
        static bool compLayer(std::shared_ptr<Object> a, std::shared_ptr<Object> b);
        // Sort the objects list by the layer
        void sortObjectsByLayer();

        Level(std::vector<std::shared_ptr<Object>> objs, std::int32_t id, ACTIVELEVEL lv);
        Level() : Level(std::vector<std::shared_ptr<Object>>(), 0, ACTIVELEVEL::MAIN_MENU) {};
        ~Level();
        [[nodiscard]] std::int32_t getLevelID() const { return levelID; };
        std::shared_ptr<Object> getObjectById(std::int32_t id);
        std::shared_ptr<Object> getObjectByName(std::string name);
        std::vector<std::shared_ptr<Object>> getObjects() { return objects; };
        void addObject(std::shared_ptr<Object> object);
        std::shared_ptr<Object> getClickedOn(sf::Vector2f mousePosition);
        void setActiveLevel(ACTIVELEVEL lv);
        [[nodiscard]] ACTIVELEVEL getActiveLevel() const { return levelActiveView; };
    };
}


#endif //SFMLCODINGPROJECT_LEVEL_H