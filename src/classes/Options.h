//
// Created by gavin on 11/10/2025.

#ifndef SFMLCODINGPROJECT_OPTIONS_H
#define SFMLCODINGPROJECT_OPTIONS_H
#include <string>


/**
 * Options class - Manages the options file and parsing options set by user
 */
namespace NMGP {
    class Options {
    private:
        int frameRate;
        unsigned windowHeight;
        unsigned windowWidth;
        bool showFPS;
        bool isVSync;
        bool isDebug;
    public:
        explicit Options(bool debug);
        Options() : Options(false) {}
        ~Options();
        // Used if the options file doesn't exist
        static void buildDefaultOptionsFile();
        // Pulls options from the file if it exists
        void fetchOptionsFromFile();
        [[nodiscard]] int getFrameRate() const;
        [[nodiscard]] unsigned getWindowHeight() const;
        [[nodiscard]] unsigned getWindowWidth() const;
        [[nodiscard]] float getWindowHeightFloat() const;
        [[nodiscard]] float getWindowWidthFloat() const;
        [[nodiscard]] bool isFPSVisible() const;
        [[nodiscard]] bool isVSyncEnabled() const;
    private:
        int fileLoadCount = 0;
    };
}
#endif //SFMLCODINGPROJECT_OPTIONS_H