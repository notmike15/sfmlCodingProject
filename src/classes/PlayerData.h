//
// Created by gavin on 1/8/2026.
//

#ifndef SFMLCODINGPROJECT_PLAYERDATA_H
#define SFMLCODINGPROJECT_PLAYERDATA_H
#include "Label.h"

namespace NMGP {
    class PlayerData {
    private:
        Label scoreDisplay;
        const std::int64_t MAX_SCORE = 99999999;
        std::int32_t score = 0;
    public:
        PlayerData();
        ~PlayerData();
        void updateScore();
        void saveData();
        void loadData(int fileLoadCount = 0);
        void buildSaveData();
    };
}

#endif //SFMLCODINGPROJECT_PLAYERDATA_H