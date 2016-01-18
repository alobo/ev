#include <math.h>
#include "Creature.h"

const double PI = std::atan(1.0)*4;

Creature::Creature() {
    m_rotation = 0;
    radius = 25.0;
    size = Eigen::Vector2f(radius * 2, radius * 2);
    m_base = sf::CircleShape(radius);
    m_base.setFillColor(sf::Color::Red);
    m_eye = sf::CircleShape(radius / 4);
    m_eye.setFillColor(sf::Color::Green);
    m_left_fov_line[0] = sf::Vertex(sf::Vector2f(position[0] + radius, position[1]));
    m_left_fov_line[1] = sf::Vertex(sf::Vector2f(position[0] + radius, position[1] + radius));
    m_right_fov_line[0] = sf::Vertex(sf::Vector2f(position[0] + radius, position[1]));
    m_right_fov_line[1] = sf::Vertex(sf::Vector2f(position[0] + radius, position[1] + radius));
}

void Creature::draw(sf::RenderWindow *window) {
    m_base.setPosition(position[0], position[1]);
    m_eye.setPosition(position[0] + 0.75 * radius, position[1]);

    window->draw(m_base);
    window->draw(m_eye);
    window->draw(m_left_fov_line, 2, sf::Lines);
    // window->draw(m_right_fov_line, 2, sf::Lines);

    // window->draw(m_line, 2, sf::Lines);
}

Creature::~Creature() {
}
