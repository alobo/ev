#pragma once

#include "../Physics/RigidBody.h"
#include "../Graphics/DrawableInterface.h"

class Creature : public RigidBody, public DrawableInterface
{
private:
    float m_rotation;
    sf::CircleShape m_base;
    sf::CircleShape m_eye;
    sf::Vertex m_left_fov_line[2];
    sf::Vertex m_right_fov_line[2];

public:
    Creature();
    void draw(sf::RenderWindow *window);
    ~Creature();
};
