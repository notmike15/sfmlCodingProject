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

        void buildDefaultOptionsFile() const;
        void fetchOptionsFromFile();
        int getFrameRate() const;
        unsigned getWindowHeight() const;
        unsigned getWindowWidth() const;
        bool isFPSVisible() const;
        bool isVSyncEnabled() const;
    private:
        int fileLoadCount = 0;
    };
}
#endif //SFMLCODINGPROJECT_OPTIONS_H