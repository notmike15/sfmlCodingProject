
#include <memory>

#include "Button.h"
#include "Constants.h"
#include "GameManager.h"
#include "Level.h"
#include "Options.h"
#include "SFML/Graphics/RenderWindow.hpp"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char* argv[]) {

    NMGP::GameManager game;
    if (argc >= 2) {
        if (argv[1] == Constants::DEBUG_CODE) {
            game.setOptions(NMGP::Options(true));
        }
    }

    // run the program as long as the window is open
    while (game.getWindow()->isOpen())
    {
        game.getWindow()->clear(sf::Color::Black);
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional<sf::Event> event = game.getWindow()->pollEvent())
        {
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
                    std::shared_ptr<NMGP::Object> clicked = game.getActiveLevel()->
                        getClickedOn(game.getWindow()->mapPixelToCoords(mouseButtonPressed->position));
                    if (clicked != nullptr) {
                        switch (clicked->onClick()) {
                            case Constants::ButtonClicks::MAIN_MENU_PRESSED:
                                game.changeLevel(NMGP::Level::MAIN_MENU);
                                break;
                            case Constants::ButtonClicks::OPTIONS_PRESSED:
                                game.changeLevel(NMGP::Level::OPTIONS);
                                break;
                            case Constants::ButtonClicks::PLAY_BUTTON_PRESSED:
                                game.changeLevel(NMGP::Level::PLAY);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
            // "close requested" event: we close the window
            else if (event->is<sf::Event::Closed>()) {
                game.getWindow()->close();
            }
        }
        game.drawWindow();
        // end the current frame
        game.getWindow()->display();
    }
}