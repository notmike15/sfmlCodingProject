#include <iostream>
#include <SFML/Window.hpp>
#include "Constants.h"
#include "Options.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Options options {};
    sf::Window window(sf::VideoMode({options.getWindowWidth(), options.getWindowHeight()}), Constants::WINDOW_TITLE, sf::Style::Close);
    window.setVerticalSyncEnabled(options.isVSyncEnabled());
    window.setFramerateLimit(options.getFrameRate());

    std::cout << options.getWindowWidth() << " " << options.getWindowHeight() << std::endl;
    std::cout << options.getFrameRate() << std::endl;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    }
}