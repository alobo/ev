#pragma once

#include <SFML/Graphics.hpp>

class DrawableInterface {
    public:
        virtual ~DrawableInterface() {}
        virtual void draw(sf::RenderWindow *window) = 0;
};
