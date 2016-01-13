#pragma once

#include "Physics/RigidBody.h"
#include "Graphics/DrawableInterface.h"

class Circle : public RigidBody, public DrawableInterface
{
private:
  const float BASE_RADIUS = 50.f;
  sf::CircleShape m_base;
  sf::Vertex m_line[2];

public:
    Circle();
    void draw(sf::RenderWindow *window);
    ~Circle();
};
