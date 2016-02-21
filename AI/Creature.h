#pragma once

#include <eigen3/Eigen/Core>
#include "../Physics/RigidBody.h"
#include "../Graphics/DrawableInterface.h"
#include "NeuralNetwork.h"

class Creature : public RigidBody, public DrawableInterface
{
private:
    float energy = 0.0;
    float m_rotation_angle;
    NeuralNetwork m_network;
    sf::CircleShape m_base;
    sf::CircleShape m_eye;
    sf::CircleShape m_fov;

public:
    Creature();
    void draw(sf::RenderWindow *window);
    float getRotation();
    void setRotation(float degrees);
    void moveForward();
    bool isPointInFOV(sf::Vector2f point);
    float distanceToPoint(sf::Vector2f point);
    void process(std::vector<sf::CircleShape>* food);
    NeuralNetwork getNeuralNetwork();
    ~Creature();
};
