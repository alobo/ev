#include <cstdio>
#include "Environment.h"

Environment::Environment(int width, int height) {
    m_width = width;
    m_height = height;
}

void Environment::addObject(RigidBody* body) {
    m_objects.push_back(body);
}
void Environment::step(float timeStep) {
    for(std::vector<RigidBody*>::iterator it = m_objects.begin(); it != m_objects.end(); ++it) {
        (*it)->position[0] += 0.1;
        printf("%f\n", (*it)->position[0]);
    }
}
