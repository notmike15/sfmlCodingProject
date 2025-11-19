//
// Created by gavin on 11/10/2025.
//

#include "Options.h"
#include <fstream>
#include <string>
#include "Logger.h"
#include "Constants.h"

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

    void Options::buildDefaultOptionsFile() const {
        std::fstream file(Constants::OPTIONS_FILE_NAME, std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::CRITICAL, Constants::UNABLE_TO_WRITE_FILE + Constants::OPTIONS_FILE_NAME + '\n');
            std::cout << Constants::UNABLE_TO_WRITE_FILE << Constants::OPTIONS_FILE_NAME << std::endl;
            logger.closeLog();
        }
        file << Constants::DEFAULT_FRAME_RATE << std::endl;
        file << Constants::DEFAULT_WINDOW_HEIGHT << std::endl;
        file << Constants::DEFAULT_WINDOW_WIDTH << std::endl;
        file << (Constants::DEFAULT_IS_FPS_VISIBLE ? "1" : "0") << std::endl;
        file << (Constants::DEFAULT_IS_VSYNC_ENABLED ? "1" : "0") << std::endl;
        file.close();
        file.open(Constants::OPTIONS_FILE_NAME, std::ios::in);
        if (!file.is_open()) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::CRITICAL, Constants::UNABLE_TO_WRITE_FILE + Constants::OPTIONS_FILE_NAME + '\n');
            std::cout << Constants::UNABLE_TO_WRITE_FILE << Constants::OPTIONS_FILE_NAME << std::endl;
            logger.closeLog();
        }
        file.close();
    }

    void Options::fetchOptionsFromFile() {
        fileLoadCount++;
        if (fileLoadCount >= 4) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::CRITICAL, Constants::FAILED_TO_REBUILD_OPTIONS_FILE);
            logger.closeLog();

            exit(-1);
        }
        try {
            std::fstream file(Constants::OPTIONS_FILE_NAME, std::ios::in);
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
            file.close();
        }
        catch (std::invalid_argument& e) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::ERROR, Constants::REBUILDING_OPTIONS_FILE);
            logger.closeLog();

            buildDefaultOptionsFile();
            fetchOptionsFromFile();
        }
        catch (std::exception& e) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::ERROR, Constants::REBUILDING_OPTIONS_FILE);
            logger.closeLog();

            buildDefaultOptionsFile();
            fetchOptionsFromFile();
        }
    }

    Options::Options(bool debug) {
        isDebug = debug;
        std::fstream file(Constants::OPTIONS_FILE_NAME, std::ios::in);
        if (!file.is_open()) {
            buildDefaultOptionsFile();
        }
        file.close();
        fetchOptionsFromFile();
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