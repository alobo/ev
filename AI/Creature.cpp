#include "Creature.h"

const double PI = std::atan(1.0)*4;

Creature::Creature() {
    m_rotation = 0;
    radius = 25.0;
    setRotation(20);
    size = Eigen::Vector2f(radius * 2, radius * 2);
    m_base = sf::CircleShape(radius);
    m_base.setFillColor(sf::Color::Red);
    m_eye = sf::CircleShape(radius / 4);
    m_eye.setFillColor(sf::Color::Green);
    m_left_fov_line = sf::RectangleShape(sf::Vector2f(150, 2));
    m_right_fov_line = sf::RectangleShape(sf::Vector2f(150, 2));
}

void Creature::draw(sf::RenderWindow *window) {
    m_base.setPosition(position[0], position[1]);
    m_eye.setPosition(position[0] + 0.75 * radius, position[1]);
    m_left_fov_line.setPosition(position[0] + radius, position[1]);
    m_right_fov_line.setPosition(position[0] + radius, position[1]);

    m_left_fov_line.setRotation(-135);
    m_right_fov_line.setRotation(-45);

    window->draw(m_base);
    window->draw(m_eye);
    window->draw(m_left_fov_line);
    window->draw(m_right_fov_line);
}

void Creature::setRotation(float degrees) {
    m_rotation = degrees;
}

Creature::~Creature() {
}
