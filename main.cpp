#include <iostream>
#include "Constants.h"
#include "Options.h"
#include "SFML/Graphics/RenderWindow.hpp"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char* argv[]) {

    Options options;
    if (argc >= 2) {
        if (argv[1] == Constants::DEBUG_CODE) {
            options = Options(true);
        }
        else {
            options = Options(false);
        }
    }
    sf::RenderWindow window(sf::VideoMode({options.getWindowWidth(), options.getWindowHeight()}), Constants::WINDOW_TITLE, sf::Style::Close);
    window.setVerticalSyncEnabled(options.isVSyncEnabled());
    window.setFramerateLimit(options.getFrameRate());

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

        window.clear(sf::Color::Black);



        window.display();

    }
}