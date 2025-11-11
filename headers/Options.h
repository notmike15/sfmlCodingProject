//
// Created by gavin on 11/10/2025.

#ifndef SFMLCODINGPROJECT_OPTIONS_H
#define SFMLCODINGPROJECT_OPTIONS_H
#include "Constants.h"
#include <string>


/**
 * Options class - Manages the options file and parsing options set by user
 */
class Options {
private:
    int frameRate;
    unsigned windowHeight;
    unsigned windowWidth;
    bool showFPS;
    bool isVSync;
public:
    Options();
    ~Options();
    int getFrameRate() const;
    unsigned getWindowHeight() const;
    unsigned getWindowWidth() const;
    bool isFPSVisible() const;
    bool isVSyncEnabled() const;
private:
    const char* defaultFrameRate = "-1";
    const char* defaultWindowHeight = "1080";
    const char* defaultWindowWidth = "1920";
    const char* defaultIsFPSVisible = "0";
    const char* defaultIsVsyncEnabled = "1";
};


#endif //SFMLCODINGPROJECT_OPTIONS_H