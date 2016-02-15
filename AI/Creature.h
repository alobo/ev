#pragma once

#include <eigen3/Eigen/Core>
#include "../Physics/RigidBody.h"
#include "../Graphics/DrawableInterface.h"

class Creature : public RigidBody, public DrawableInterface
{
private:
    float m_rotation_angle;
    sf::CircleShape m_base;
    sf::CircleShape m_eye;
    sf::CircleShape m_fov;

public:
    Creature();
    void draw(sf::RenderWindow *window);
    float getRotation();
    void setRotation(float degrees);
    bool isPointInFOV(sf::Vector2f point);
    ~Creature();
};
