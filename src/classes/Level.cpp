//
// Created by gavin-lp on 11/16/2025.
//

#include "Level.h"
#include <algorithm>
#include <iostream>
#include <utility>


namespace NMGP {
    Level::~Level() {
        objects.clear();
    }

    bool Level::comp(std::shared_ptr<Object> a, std::shared_ptr<Object> b) {
        return a->getObjectID() > b->getObjectID();
    }
    Level::Level(std::vector<std::shared_ptr<Object>> objs, int id) {
        for (std::shared_ptr<Object> object : objs) {
            objects.push_back(object);
        };
        levelID = id;
        if (!objects.empty()) {
            std::ranges::sort(objects, comp);
        }
    }

    std::shared_ptr<Object> Level::getObjectByName(std::string name) {
        for (std::shared_ptr<Object> obj : objects) {
            if (obj->getObjectName() == name) {
                return obj;
            }
        }
        return objects.back();
    }

    std::shared_ptr<Object> Level::getObjectById(int id) {
        return objects[id];
    }

    void Level::addObject(std::shared_ptr<Object> object) {
        objects.insert(
            std::ranges::upper_bound(objects, object, comp),
            object
        );
    }

    void Level::draw(sf::RenderWindow* window) {
        for (std::shared_ptr<Object> obj : objects) {
            window->draw(obj->getSprite());
        }
    }


    std::shared_ptr<Object> Level::getClickedOn(sf::Vector2f mousePosition) {
        for (std::shared_ptr<Object> object : objects) {
            if (object->getSprite().getGlobalBounds().contains(mousePosition)) {
                return object;
            }
        }
        std::cout << "Did not click on anything...\n";
        return {};
    }



}
