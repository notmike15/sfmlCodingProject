//
// Created by gavin on 11/20/2025.
//

#include "GameManager.h"

#include "Label.h"
#include "Level.h"

namespace NMGP {
    GameManager::GameManager() {
        window = std::make_shared<sf::RenderWindow>(sf::VideoMode({options.getWindowWidth(), options.getWindowHeight()}),
            Constants::WINDOW_TITLE, sf::Style::Close);
        window->setVerticalSyncEnabled(options.isVSyncEnabled());
        window->setFramerateLimit(options.getFrameRate());
        options = Options();
        loadTextures();
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
        levels[0]->addObject(std::shared_ptr<Object>(new Button(
            "playButton", "", Object::BUTTON, sf::Font(Constants::DEFAULT_FONT),
            {(window->getSize().x / 2.0f), (window->getSize().y / 1.5f)},
            textures[Constants::PLAY_BUTTON], {Constants::PIXEL_RATIO, Constants::PIXEL_RATIO}, PLAY_BUTTON)));
        levels[0]->addObject(std::shared_ptr<Object>(new Label(
            "Title", "Title", sf::Color::White, {
            (window->getSize().x / 2.0f) - 64, (window->getSize().y / 3.5f)
        }, Object::SEMI_BACKGROUND, 64
        )));
        levels[0]->addObject(std::shared_ptr<Object>(new TexturedObject("bg_test", textures[Constants::BG_TEXTURE_DEBUG_LOCATION],
            Object::BACKGROUND, {0.f, 0.f},{Constants::PIXEL_RATIO, Constants::PIXEL_RATIO})));
        levels[0]->setActiveLevel(Level::ACTIVELEVEL::MAIN_MENU);

        levels.push_back(std::make_shared<Level>());
        levels[1]->addObject(std::shared_ptr<Object>(new Button("Main Menu", "Main Menu", Object::BACKGROUND, sf::Font(Constants::DEFAULT_FONT),
            {50.f, 50.f}, textures[Constants::PLAY_BUTTON], {Constants::PIXEL_RATIO, Constants::PIXEL_RATIO}, ButtonType::MENU_BUTTON)));
        levels[1]->setActiveLevel(Level::ACTIVELEVEL::PLAY);

        // Setting to active view
        currentLevel = Level::ACTIVELEVEL::MAIN_MENU;
    }
    void GameManager::drawWindow() const {
        // Gets current active level based on the current level value
        std::shared_ptr<Level> activeLevel = getActiveLevel();
        // Sorts it by layer and draws in that order
        activeLevel->sortObjectsByLayer();
        for (int i = 0; i < activeLevel->getObjects().size(); i++) {
            window->draw(*activeLevel->getObjects()[i]->getDrawable());
        }
    }

    void GameManager::changeLevel(Level::ACTIVELEVEL alv) {
        currentLevel = alv;
    }

    void GameManager::loadTextures() {
        textures[Constants::PLAY_BUTTON] = sf::Texture(Constants::PLAY_BUTTON);
        textures[Constants::BG_TEXTURE_DEBUG_LOCATION] = sf::Texture(Constants::BG_TEXTURE_DEBUG_LOCATION);
    }

} // NMGP