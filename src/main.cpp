#include <iostream>
#include <memory>

#include "Button.h"
#include "Constants.h"
#include "Level.h"
#include "Options.h"
#include "SFML/Graphics/RenderWindow.hpp"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char* argv[]) {

    NMGP::Options options;
    if (argc >= 2) {
        if (argv[1] == Constants::DEBUG_CODE) {
            options = NMGP::Options(true);
        }
        else {
            options = NMGP::Options(false);
        }
    }
    sf::RenderWindow window(sf::VideoMode({options.getWindowWidth(), options.getWindowHeight()}),
        Constants::WINDOW_TITLE, sf::Style::Close);
    window.setVerticalSyncEnabled(options.isVSyncEnabled());
    window.setFramerateLimit(options.getFrameRate());

    NMGP::Level level1 = NMGP::Level();

    level1.addObject(std::make_shared<NMGP::Object>());
    level1.addObject(std::shared_ptr<NMGP::Object>(new NMGP::Button(
        "Test", "Testing", NMGP::Object::BUTTON, sf::Font(Constants::DEFAULT_FONT), {500.f, 500.f},
        sf::Texture(Constants::PLAY_BUTTON), {Constants::PIXEL_RATIO, Constants::PIXEL_RATIO}, NMGP::PLAY_BUTTON)));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
                    std::shared_ptr<NMGP::Object> clicked = level1.getClickedOn(window.mapPixelToCoords(mouseButtonPressed->position));
                    if (clicked != nullptr) {
                        clicked->onClick();
                    }
                }
            }
            // "close requested" event: we close the window
            else if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        for (std::shared_ptr<NMGP::Object> obj : level1.getObjects()) {
            window.draw(obj->getSprite());
        }
        // end the current frame
        window.display();
    }
}