//
// Created by gavin on 11/10/2025.
//

#include "Options.h"

#include <fstream>

#include "Logger.h"
#include "SFML/Window/Window.hpp"

Options::Options(char fileName[32]) {
    std::fstream file(fileName, std::fstream::in);
    if (!file.is_open()) {
        file.close();
        file.open(fileName, std::fstream::out);
        if (!file.is_open()) {
            Logger logger("error.log");
            logger.log(LogLevel::CRITICAL, "Unable to write options file, options will not be saved");
            std::cout << ""
        }
    }

}

Options::Options() {

}

int Options::getFrameRate() const {
    return frameRate;
}
int Options::getWindowHeight() const {
    return windowHeight;
}
int Options::getWindowWidth() const {
    return windowWidth;
}
bool Options::isVSyncEnabled() const {
    return isVSync;
}
bool Options::isFPSVisible() const {
    return showFPS;
}
