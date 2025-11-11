//
// Created by gavin on 11/10/2025.
//

#include "Options.h"
#include <fstream>
#include <string>
#include "Logger.h"
#include "Constants.h"


Options::~Options() {
    std::fstream file(Constants::OPTIONS_FILE_NAME, std::ios::out);
    if (!file.is_open()) {
        Logger logger(Constants::ERROR_FILE_NAME);
        logger.log(LogLevel::CRITICAL, Constants::UNABLE_TO_WRITE_FILE + Constants::OPTIONS_FILE_NAME + '\n');
        std::cout << Constants::UNABLE_TO_WRITE_FILE << Constants::OPTIONS_FILE_NAME << std::endl;
        logger.closeLog();
    }
    file << getFrameRate() << endl;
    file << getWindowHeight() << endl;
    file << getWindowWidth() << endl;
    file << (isFPSVisible() ? "1" : "0") << endl;
    file << (isVSyncEnabled() ? "1" : "0") << endl;
    file.close();
}

Options::Options() {
    std::fstream file(Constants::OPTIONS_FILE_NAME, std::ios::in);
    if (!file.is_open()) {
        file.open(Constants::OPTIONS_FILE_NAME, std::ios::out);
        if (!file.is_open()) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::CRITICAL, Constants::UNABLE_TO_WRITE_FILE + Constants::OPTIONS_FILE_NAME + '\n');
            std::cout << Constants::UNABLE_TO_WRITE_FILE << Constants::OPTIONS_FILE_NAME << std::endl;
            logger.closeLog();
        }
        file << defaultFrameRate << endl;
        file << defaultWindowHeight << endl;
        file << defaultWindowWidth << endl;
        file << (defaultIsFPSVisible ? "1" : "0") << endl;
        file << (defaultIsVsyncEnabled ? "1" : "0") << endl;
        file.close();
        file.open(Constants::OPTIONS_FILE_NAME, std::ios::in);
        if (!file.is_open()) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::CRITICAL, Constants::UNABLE_TO_WRITE_FILE + Constants::OPTIONS_FILE_NAME + '\n');
            std::cout << Constants::UNABLE_TO_WRITE_FILE << Constants::OPTIONS_FILE_NAME << std::endl;
            logger.closeLog();
        }
    }
    std::string input;
    getline(file, input);
    frameRate = stoi(input);
    getline(file, input);
    windowHeight = stoi(input);
    getline(file, input);
    windowWidth = stoi(input);
    getline(file, input);
    showFPS = stoi(input);
    getline(file, input);
    isVSync = stoi(input);
}

int Options::getFrameRate() const {
    return frameRate;
}
unsigned Options::getWindowHeight() const {
    return windowHeight;
}
unsigned Options::getWindowWidth() const {
    return windowWidth;
}
bool Options::isVSyncEnabled() const {
    return isVSync;
}
bool Options::isFPSVisible() const {
    return showFPS;
}
