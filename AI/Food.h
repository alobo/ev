#pragma once

#include <SFML/Graphics.hpp>

class Food : public sf::CircleShape
{
private:
    bool consumed;

public:
    Food();
    void reset(int frame_width, int frame_height);
    void consume();
    bool isConsumed();
    ~Food();
};
