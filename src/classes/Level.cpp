//
// Created by gavin-lp on 11/16/2025.
//

#include "Level.h"
#include <algorithm>
#include <iostream>



namespace NMGP {
    Level::~Level() {
        objects.clear();
    }
    bool Level::compLayer(std::shared_ptr<Object> a, std::shared_ptr<Object> b) {
        return a->getLayer() < b->getLayer();
    }
    void Level::sortObjectsByLayer() {
        std::ranges::sort(objects, compLayer);
    }
    Level::Level(std::vector<std::shared_ptr<Object>> objs, std::int32_t id, ACTIVELEVEL lv) {
        for (std::shared_ptr<Object> object : objs) {
            objects.push_back(object);
        };
        levelID = id;
        levelActiveView = lv;
    }

    std::shared_ptr<Object> Level::getObjectByName(std::string name) {
        for (std::shared_ptr<Object> obj : objects) {
            if (obj->getObjectName() == name) {
                return obj;
            }
        }
        return objects.back();
    }

    std::shared_ptr<Object> Level::getObjectById(std::int32_t id) {
        return objects[id];
    }

    void Level::addObject(std::shared_ptr<Object> object) {
        objects.insert(
            std::ranges::upper_bound(objects, object, compLayer),
            object
        );
    }

    std::shared_ptr<Object> Level::getClickedOn(sf::Vector2f mousePosition) {
        std::vector<std::shared_ptr<Object>> objs;
        for (std::shared_ptr<Object> object : objects) {
            if (object->getSprite().getGlobalBounds().contains(mousePosition)) {
                objs.push_back(object);
            }
        }
        if (objs.empty()) { return {}; }
        return *std::ranges::max_element(objs, compLayer);
    }

    void Level::setActiveLevel(ACTIVELEVEL lv) {
        levelActiveView = lv;
    }


}
