//
// Created by gavin on 11/13/2025.
//

#ifndef SFMLCODINGPROJECT_CLICKABLE_H
#define SFMLCODINGPROJECT_CLICKABLE_H
#include "SFML/Window/Window.hpp"

namespace NMGP {
    class Clickable {
    public:
        virtual ~Clickable() = default;

        virtual int onClick() = 0;
        virtual int onHover() = 0;
        virtual int offHover() = 0;
    };
}

#endif //SFMLCODINGPROJECT_CLICKABLE_H