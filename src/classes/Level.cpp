//
// Created by gavin-lp on 11/16/2025.
//

#include "Level.h"

#include <algorithm>
#include <iostream>


namespace NMGP {
    bool Level::comp(Object a, Object b) {
        return a.getObjectID() > b.getObjectID();
    }
    Level::Level(std::vector<Object> objs, int id) {
        objects = objs;
        levelID = id;
        if (!objects.empty()) {
            std::ranges::sort(objects, comp);
        }
    }

    Object Level::getObjectByName(std::string name) {
        for (Object& obj : objects) {
            if (obj.getObjectName() == name) {
                return obj;
            }
        }
        return objects.back();
    }

    Object Level::getObjectById(int id) {
        return objects[id];
    }

    void Level::addObject(const Object &object) {
        objects.insert(
            std::ranges::upper_bound(objects, object, comp),
            object
        );
    }

    void Level::draw(sf::RenderWindow* window) {
        for (Object& obj : objects) {
            window->draw(obj.getSprite());
        }
    }


    Clickable *Level::getClickedOn(sf::Vector2f mousePosition) {
        std::cout << "Checking click...\n";
        std::vector<Clickable*> clickables;
        for (Object& obj : objects) {
            if (sizeof(obj) == sizeof(Button)) {
                clickables.push_back(dynamic_cast<Clickable*>(&obj));
            }
        }
        if (clickables.empty()) {
            std::cout << "Failed to find any clickables...\n";
            return nullptr;
        }
        for (Clickable* clickable : clickables) {
            std::cout << clickable->getObjectID() << std::endl;
            std::cout << clickable->getSprite().getGlobalBounds().position.x << ", " << clickable->getSprite().getGlobalBounds().position.y << std::endl;
            if (clickable->getSprite().getGlobalBounds().contains(mousePosition)) {
                return clickable;
            }
        }
        std::cout << "Did not click on anything...\n";
        return nullptr;
    }



}
