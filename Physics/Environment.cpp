#include <cstdio>
#include "Environment.h"

Eigen::Vector2f rightWallNormal = Eigen::Vector2f(-1.0, 0.0);

Environment::Environment(int width, int height) {
    m_width = width;
    m_height = height;
}

void Environment::addObject(RigidBody* body) {
    m_objects.push_back(body);
}
void Environment::step(float timeStep) {
    for(std::vector<RigidBody*>::iterator it = m_objects.begin(); it != m_objects.end(); ++it) {
        (*it)->position += (*it)->velocity * timeStep;
        (*it)->velocity += (*it)->acceleration * timeStep;

        // Handle bounds collisions
        if ((*it)->position[0] < 0) {
            (*it)->velocity[0] *= -1;
        } else if ((*it)->position[1] < 0) {
            (*it)->velocity[1] *= -1;
        } else if ((*it)->position[0] + (*it)->size[0] > m_width) {
            (*it)->velocity[0] *= -1;
        } else if ((*it)->position[1] + (*it)->size[1] > m_height) {
            (*it)->velocity[1] *= -1;
        }
    }
}
