//
// Created by gavin on 11/10/2025.
//

#ifndef SFMLCODINGPROJECT_CONSTANTS_H
#define SFMLCODINGPROJECT_CONSTANTS_H
#include <string>

namespace Constants {
    // Error strings
    static const std::string UNABLE_TO_WRITE_FILE = "Unable to write file : ";
    // Default strings
    static const std::string DEFAULT_FONT = "../resources/fonts/EvilEmpire.otf";
    static const std::string PLAY_BUTTON = "../resources/buttons/play_2.png";
    static const std::string OPTIONS_FILE_NAME = "options.cfg";
    static const std::string ERROR_FILE_NAME = "error.log";
    static const std::string WINDOW_TITLE = "My Window";
    // Magic Numbers
    static const float PIXEL_RATIO = 8.f;
    // Codes
    static const std::string DEBUG_CODE = "DEBUG";
}

#endif //SFMLCODINGPROJECT_CONSTANTS_H