#include "Circle.h"

Circle::Circle() {
    radius = 15.0;
    size = Eigen::Vector2f(radius * 2, radius * 2);
    m_base = sf::CircleShape(radius);
    m_base.setFillColor(sf::Color::Red);
    m_line[0] = sf::Vertex(sf::Vector2f(position[0] + radius, position[1]));
    m_line[1] = sf::Vertex(sf::Vector2f(position[0] + radius, position[1] + radius));
}

void Circle::draw(sf::RenderWindow *window) {
    // Update the vertex positions
    m_line[0].position = sf::Vector2f(position[0] + radius, position[1]);
    m_line[1].position = sf::Vector2f(position[0] + radius, position[1] + radius);

    m_base.setPosition(position[0], position[1]);
    window->draw(m_base);
    window->draw(m_line, 2, sf::Lines);
}

Circle::~Circle() {
}
