//
// Created by gavin on 11/10/2025.
//

#ifndef SFMLCODINGPROJECT_CONSTANTS_H
#define SFMLCODINGPROJECT_CONSTANTS_H
#include <string>

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Texture.hpp"

// Holds constants used across the system
namespace Constants {
    // Used by the system to determine which button is pressed
    // and process accordingly
    enum ButtonClicks {
        PLAY_BUTTON_PRESSED = 1001,
        MAIN_MENU_PRESSED = 1002,
        OPTIONS_PRESSED = 1003
    };
    // Error strings
    static const std::string UNABLE_TO_WRITE_FILE = "Unable to write file : ";
    static const std::string REBUILDING_OPTIONS_FILE = "Unable to pull options file, re-building...\n";
    static const std::string FAILED_TO_REBUILD_OPTIONS_FILE = "Failed to rebuild options file, closing\n";
    // Default strings
    static const std::string DEFAULT_FONT_FILE = "../resources/fonts/EvilEmpire.otf";
    static const std::string PLAY_BUTTON = "../resources/buttons/play_2.png";
    static const std::string BG_TEXTURE_DEBUG_LOCATION = "../resources/bg/background_debug_16xScale.png";
    static const std::string DICE_TEXTURE = "../resources/objects/dice_sheet.png";
    static const std::string OPTIONS_FILE_NAME = "options.cfg";
    static const std::string ERROR_FILE_NAME = "error.log";
    static const std::string WINDOW_TITLE = "My Window";
    static const std::string DEFAULT_OBJECT_NAME = "TEST";
    // Magic Numbers
    static const float PIXEL_RATIO = 8.f;
    static const char* DEFAULT_FRAME_RATE = "-1";
    static const char* DEFAULT_WINDOW_HEIGHT = "1080";
    static const char* DEFAULT_WINDOW_WIDTH = "1920";
    static const char* DEFAULT_IS_FPS_VISIBLE = "0";
    static const char* DEFAULT_IS_VSYNC_ENABLED = "1";
    static const std::int32_t NUMBER_OF_LEVELS = 3;
    // Codes
    static const std::string DEBUG_CODE = "DEBUG";
    static std::int32_t ERROR_OBJECT_ID = -999;
    // Objects
    static auto DEFAULT_TEXTURE = sf::Texture(PLAY_BUTTON);
    static auto DEFAULT_FONT = sf::Font(DEFAULT_FONT_FILE);
}

#endif //SFMLCODINGPROJECT_CONSTANTS_H