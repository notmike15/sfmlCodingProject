//
// Created by gavin on 11/20/2025.
//

#ifndef SFMLCODINGPROJECT_GAMEMANAGER_H
#define SFMLCODINGPROJECT_GAMEMANAGER_H
#include <map>
#include <memory>
#include <vector>

#include "Level.h"

namespace NMGP {
    // Manages much of the game data including loaded objects, current level,
    // options data, and eventually, player data
    class GameManager {
        private:
            std::shared_ptr<sf::RenderWindow> window;
            // Level that is currently selected
            Level::ACTIVELEVEL currentLevel;
            std::vector<std::shared_ptr<Level>> levels;
            Options options;
            std::map<std::string, sf::Texture> textures;
            sf::Clock clock;
            std::int32_t deltaTime;
        public:
            GameManager();
            ~GameManager();
            [[nodiscard]] std::shared_ptr<sf::RenderWindow> getWindow() const;
            [[nodiscard]] std::vector<std::shared_ptr<Level>> getLevels() const;
            [[nodiscard]] std::shared_ptr<Level> getLevel(int id) const;
            [[nodiscard]] std::shared_ptr<Level> getActiveLevel() const;
            [[nodiscard]] std::shared_ptr<Level> getLevelByActiveLevelID(Level::ACTIVELEVEL alv) const;
            Options* getOptions();
            [[nodiscard]] Level::ACTIVELEVEL getCurrentLevel() const;
            void setOptions(const Options& newOptions);
            // Draws all the objects to the window renderer in correct order
            // based on layer
            void drawWindow();
            void loadTextures();
            // Loads all level objects with the correct data
            // There is no need to do this dynamically as this is a very small game
            void instantiateLevels();
            // Sets the active level value so when the level is drawn, it draws
            // the corresponding level data
            void changeLevel(Level::ACTIVELEVEL alv);
    };
} // NMGP

#endif //SFMLCODINGPROJECT_GAMEMANAGER_H