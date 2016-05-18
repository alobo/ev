#pragma once

#include "../Physics/RigidBody.h"
#include "../Graphics/DrawableInterface.h"

class Circle : public RigidBody, public DrawableInterface
{
private:
  sf::CircleShape m_base;
  sf::Vertex m_line[2];

public:
    Circle();
    void draw(sf::RenderWindow *window);
    ~Circle();
};
