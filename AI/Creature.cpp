#include <math.h>
#include <eigen3/Eigen/LU>
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

bool Creature::isPointInFOV(sf::Vector2f point) {
    // Get transformed points of field of view triangle
    sf::Vector2f p1 = m_fov.getTransform().transformPoint(m_fov.getPoint(0));
    sf::Vector2f p2 = m_fov.getTransform().transformPoint(m_fov.getPoint(1));
    sf::Vector2f p3 = m_fov.getTransform().transformPoint(m_fov.getPoint(2));

    // Find barycentric coordinates of point in fov triangle
    Eigen::Matrix3f R;
    R << p1.x, p2.x, p3.x,
         p1.y, p2.y, p3.y,
         1, 1, 1;

    Eigen::Vector3f r;
    r << point.x, point.y, 1;

    // Solve Rλ = r for λ
    Eigen::Vector3f lambda = R.inverse() * r;

    // Point is in triangle if all coordinates are positive
    return lambda[0] > 0 && lambda[1] > 0 && lambda[2] > 0;
}

Creature::~Creature() {
}
