#include <cstdio>
#include "Environment.h"

Eigen::Vector2f rightWallNormal = Eigen::Vector2f(-1.0, 0.0);

Environment::Environment(int width, int height, float coeff_friction) {
    m_width = width;
    m_height = height;
    m_coeff_friction = coeff_friction;
}

void Environment::addObject(RigidBody* body) {
    m_objects.push_back(body);
}
void Environment::step(float timeStep) {
    for(std::vector<RigidBody*>::iterator it = m_objects.begin(); it != m_objects.end(); ++it) {
        (*it)->position += (*it)->velocity * timeStep;
        (*it)->velocity += ((*it)->acceleration + (-1 * (*it)->velocity) * m_coeff_friction) * timeStep;

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

        // Handle object-object collisions
        for(std::vector<RigidBody*>::iterator it2 = it; it2 != m_objects.end(); ++it2) {
            if (*it2 == *it) continue;
            if (circleVsCircle(*it, *it2)) {
                // Collision occured, resolve as elastic
                std::swap((*it)->velocity, (*it2)->velocity);
                (*it)->acceleration *= 0;
                (*it2)->acceleration *= 0;
            }
        }
    }
}

bool Environment::circleVsCircle(RigidBody* a, RigidBody* b) {
    float r = pow(a->radius + b->radius, 2);
    float distance = pow(a->position[0] - b->position[0], 2) + pow(a->position[1] - b->position[1], 2);
    return distance < r;
}
