//
// Created by gavin-lp on 12/9/2025.
//
#include "AnimatedObject.h"

namespace NMGP {
    void AnimatedObject::setSpriteCountInSpriteSheet(int newSpritePosition) {
        if (newSpritePosition >= 0 && newSpritePosition < numberOfSprites) {
            currentSprite = newSpritePosition;
        }
    }
}
