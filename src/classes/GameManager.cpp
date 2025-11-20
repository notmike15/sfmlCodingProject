//
// Created by gavin on 11/20/2025.
//

#include "GameManager.h"

#include "Level.h"

namespace NMGP {
    GameManager::GameManager() {
        window = std::make_shared<sf::RenderWindow>(sf::VideoMode({options.getWindowWidth(), options.getWindowHeight()}),
            Constants::WINDOW_TITLE, sf::Style::Close);
        window->setVerticalSyncEnabled(options.isVSyncEnabled());
        window->setFramerateLimit(options.getFrameRate());
        options = Options();
        instantiateLevels();
        currentLevel = Level::ACTIVELEVEL::MAIN_MENU;
    }

    GameManager::~GameManager() {
        levels.clear();
    }

    std::shared_ptr<sf::RenderWindow> GameManager::getWindow() const {
        return window;
    }

    std::vector<std::shared_ptr<Level>> GameManager::getLevels() const {
        return levels;
    }

    std::shared_ptr<Level> GameManager::getLevel(int id) const {
        return levels[id];
    }

    std::shared_ptr<Level> GameManager::getLevelByActiveLevelID(Level::ACTIVELEVEL alv) const {
        for (auto &level : levels) {
            if (level->getActiveLevel() == alv) {
                return level;
            }
        }
        return nullptr;
    }

    Options* GameManager::getOptions() {
        return &options;
    }

    void GameManager::setOptions(const Options& newOptions) {
        options = newOptions;
    }

    Level::ACTIVELEVEL GameManager::getCurrentLevel() const {
        return currentLevel;
    }

    std::shared_ptr<Level> GameManager::getActiveLevel() const {
        for (auto &level : levels) {
            if (level->getActiveLevel() == currentLevel) {
                return level;
            }
        }
        return nullptr;
    }
    void GameManager::instantiateLevels() {
        // Adding all objects to all levels
        levels.push_back(std::make_shared<Level>());
        levels[0]->addObject(std::make_shared<Object>());
        levels[0]->addObject(std::shared_ptr<Object>(new Button(
            "Test", "Testing", Object::BUTTON, sf::Font(Constants::DEFAULT_FONT), {500.f, 500.f},
            sf::Texture(Constants::PLAY_BUTTON), {Constants::PIXEL_RATIO, Constants::PIXEL_RATIO}, PLAY_BUTTON)));
        levels[0]->setActiveLevel(Level::ACTIVELEVEL::MAIN_MENU);

        levels.push_back(std::make_shared<Level>());
        levels[1]->addObject(std::shared_ptr<Object>(new Button("Main Menu", "Main Menu", Object::BACKGROUND, sf::Font(Constants::DEFAULT_FONT),
            {50.f, 50.f}, Constants::DEFAULT_TEXTURE, {Constants::PIXEL_RATIO, Constants::PIXEL_RATIO}, ButtonType::MENU_BUTTON)));
        levels[1]->setActiveLevel(Level::ACTIVELEVEL::PLAY);

        // Setting to active view
        currentLevel = Level::ACTIVELEVEL::MAIN_MENU;
    }
    void GameManager::drawWindow() const {
        std::shared_ptr<Level> activeLevel = getActiveLevel();
        for (int i = 0; i < activeLevel->getObjects().size(); i++) {
            window->draw(activeLevel->getObjects()[i]->getSprite());
        }
    }

    void GameManager::changeLevel(Level::ACTIVELEVEL alv) {
        currentLevel = alv;
    }
} // NMGP