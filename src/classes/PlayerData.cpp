//
// Created by gavin on 1/8/2026.
//

#include "PlayerData.h"

#include <cmath>

#include "Logger.h"

namespace NMGP {
    PlayerData::~PlayerData() {
        saveData();
    }

    PlayerData::PlayerData() {
        loadData();
    }

    void PlayerData::updateScore() {

    }
    void PlayerData::saveData() {
        std::ofstream file(Constants::SAVE_FILE_NAME, std::ios::binary | std::ios::out);
        if (!file.is_open()) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::CRITICAL, Constants::UNABLE_TO_WRITE_FILE + Constants::OPTIONS_FILE_NAME + '\n');
            std::cout << Constants::UNABLE_TO_WRITE_FILE << Constants::OPTIONS_FILE_NAME << std::endl;
            logger.closeLog();
        }
        file.write(std::to_string(score).c_str(), sizeof(MAX_SCORE));
        file.close();
    }
    void PlayerData::loadData(int fileLoadCount) {
        fileLoadCount++;
        if (fileLoadCount >= 4) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::CRITICAL, Constants::FAILED_TO_REBUILD_SAVE_FILE);
            logger.closeLog();

            exit(-1);
        }
        try {
            std::ifstream file(Constants::SAVE_FILE_NAME, std::ios::binary | std::ios::in);
            if (!file.is_open()) {
                throw std::invalid_argument(Constants::ERROR_FILE_NAME);
            }
            char* input = new char[32] {'0'};
            file.read(input, sizeof(MAX_SCORE));
            std::string s = input;
            score = std::stoi(s);
            std::cout << score << std::endl;
            delete[] input;
            input = nullptr;
            file.close();
        }
        catch (std::invalid_argument&) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::ERROR, Constants::REBUILDING_SAVE_FILE);
            logger.closeLog();

            buildSaveData();
            loadData(fileLoadCount);
        }
        catch (std::exception&) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::ERROR, Constants::REBUILDING_SAVE_FILE);
            logger.closeLog();

            buildSaveData();
            loadData(fileLoadCount);
        }
    }
    void PlayerData::buildSaveData() {
        std::ofstream file(Constants::SAVE_FILE_NAME, std::ios::binary | std::ios::out);
        score = 0;
        std::string s = std::to_string(score);
        if (!file.is_open()) {
            Logger logger(Constants::ERROR_FILE_NAME);
            logger.log(LogLevel::CRITICAL, Constants::UNABLE_TO_WRITE_FILE + Constants::OPTIONS_FILE_NAME + '\n');
            std::cout << Constants::UNABLE_TO_WRITE_FILE << Constants::OPTIONS_FILE_NAME << std::endl;
            logger.closeLog();
        }
        file.write(s.c_str(), s.length());
        file.close();
    }
}
