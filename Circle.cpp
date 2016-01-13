#include "Circle.h"

Circle::Circle() {
    m_base = sf::CircleShape(BASE_RADIUS);
    m_base.setFillColor(sf::Color::Red);
    m_line[0] = sf::Vertex(sf::Vector2f(position[0] + BASE_RADIUS, position[1]));
    m_line[1] = sf::Vertex(sf::Vector2f(position[0] + BASE_RADIUS, position[1] + BASE_RADIUS));
}

void Circle::draw(sf::RenderWindow *window) {
    // Update the vertex positions
    m_line[0].position = sf::Vector2f(position[0] + BASE_RADIUS, position[1]);
    m_line[1].position = sf::Vector2f(position[0] + BASE_RADIUS, position[1] + BASE_RADIUS);

    m_base.setPosition(position[0], position[1]);
    window->draw(m_base);
    window->draw(m_line, 2, sf::Lines);
}

Circle::~Circle() {
}
