//
// Created by gavin on 11/20/2025.
//

#ifndef SFMLCODINGPROJECT_GAMEMANAGER_H
#define SFMLCODINGPROJECT_GAMEMANAGER_H
#include <memory>
#include <vector>

#include "Level.h"

namespace NMGP {
    class GameManager {
        private:
            std::shared_ptr<sf::RenderWindow> window;
            Level::ACTIVELEVEL currentLevel;
            std::vector<std::shared_ptr<Level>> levels;
            Options options;
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
            void drawWindow() const;
            void instantiateLevels();
            void changeLevel(Level::ACTIVELEVEL alv);
    };
} // NMGP

#endif //SFMLCODINGPROJECT_GAMEMANAGER_H