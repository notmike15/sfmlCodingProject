//
// Created by gavin on 11/10/2025.
//

#ifndef SFMLCODINGPROJECT_OPTIONS_H
#define SFMLCODINGPROJECT_OPTIONS_H


class Options {
private:
    int frameRate;
    int windowHeight;
    int windowWidth;
    bool showFPS;
    bool isVSync;
public:
    Options(char fileName[32]);
    Options();
    int getFrameRate() const;
    int getWindowHeight() const;
    int getWindowWidth() const;
    bool isFPSVisible() const;
    bool isVSyncEnabled() const;
};


#endif //SFMLCODINGPROJECT_OPTIONS_H