#include <math.h>
#include "Creature.h"

Creature::Creature() {
    radius = 25.0;
    size = Eigen::Vector2f(radius * 2, radius * 2); // Setup size for physics

    m_base = sf::CircleShape(radius);
    m_eye = sf::CircleShape(radius / 4);
    m_fov = sf::CircleShape(40, 3); // Triangle

    // Set the eye and fov origin to the center of the base
    m_eye.setOrigin(radius / 4, -radius * 0.65);
    m_fov.setOrigin(40, -radius);

    m_base.setFillColor(sf::Color::Red);
    m_eye.setFillColor(sf::Color::Green);
    m_fov.setFillColor(sf::Color::White);
}

void Creature::draw(sf::RenderWindow *window) {

    m_base.setPosition(position[0], position[1]);

    // Origin is at center, so set at center of base
    m_eye.setPosition(position[0] + radius, position[1] + radius);
    m_fov.setPosition(position[0] + radius, position[1] + radius);

    window->draw(m_base);
    window->draw(m_fov);
    window->draw(m_eye);
}

void Creature::setRotation(float degrees) {
    m_rotation_angle = degrees;
    if (m_rotation_angle >= 360) m_rotation_angle = 0;
    m_eye.setRotation(m_rotation_angle);
    m_fov.setRotation(m_rotation_angle);
}

Creature::~Creature() {
}
