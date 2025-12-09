//
// Created by gavin-lp on 12/9/2025.
//

#ifndef SFMLCODINGPROJECT_ANIMATEDOBJECT_H
#define SFMLCODINGPROJECT_ANIMATEDOBJECT_H
#include "TexturedObject.h"

namespace NMGP {
    class AnimatedObject : public NMGP::TexturedObject{
    protected:
        const int TEXTURE_WIDTH = 32;
        const int TEXTURE_HEIGHT = 32;
        sf::IntRect textureRect = sf::IntRect({0, 0}, {TEXTURE_WIDTH, TEXTURE_HEIGHT});
        int numberOfSprites;
        int currentSprite;
    public:
        sf::IntRect getTextureRect(){ return textureRect; }
        void setSpriteCountInSpriteSheet(int newSpritePosition);
    };
}


#endif //SFMLCODINGPROJECT_ANIMATEDOBJECT_H