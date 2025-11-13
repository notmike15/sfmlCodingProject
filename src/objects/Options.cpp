//
// Created by gavin on 11/10/2025.
//

#include "Options.h"
#include <fstream>
#include <string>
#include "Logger.h"
#include "../headers/Constants.h"

namespace NMGP {
    Options::~Options() {
        std::fstream file(Constants::OPTIONS_FILE_NAME, std::ios::out);
        if (!file.is_open()) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::CRITICAL, Constants::UNABLE_TO_WRITE_FILE + Constants::OPTIONS_FILE_NAME + '\n');
            std::cout << Constants::UNABLE_TO_WRITE_FILE << Constants::OPTIONS_FILE_NAME << std::endl;
            logger.closeLog();
        }
        file << getFrameRate() << std::endl;
        file << getWindowHeight() << std::endl;
        file << getWindowWidth() << std::endl;
        file << (isFPSVisible() ? "1" : "0") << std::endl;
        file << (isVSyncEnabled() ? "1" : "0") << std::endl;
        file.close();
    }

    Options::Options(bool debug) {
        isDebug = debug;
        std::fstream file(Constants::OPTIONS_FILE_NAME, std::ios::in);
        if (!file.is_open()) {
            file.open(Constants::OPTIONS_FILE_NAME, std::ios::out);
            if (!file.is_open()) {
                Logger logger(Constants::ERROR_FILE_NAME);
                logger.log(LogLevel::CRITICAL, Constants::UNABLE_TO_WRITE_FILE + Constants::OPTIONS_FILE_NAME + '\n');
                std::cout << Constants::UNABLE_TO_WRITE_FILE << Constants::OPTIONS_FILE_NAME << std::endl;
                logger.closeLog();
            }
            file << defaultFrameRate << std::endl;
            file << defaultWindowHeight << std::endl;
            file << defaultWindowWidth << std::endl;
            file << (defaultIsFPSVisible ? "1" : "0") << std::endl;
            file << (defaultIsVsyncEnabled ? "1" : "0") << std::endl;
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
}