#pragma once

#include <vector>
#include <eigen3/Eigen/Core>

#include "RigidBody.h"

class Environment {
private:
    int m_width;
    int m_height;
    float m_coeff_friction;
    std::vector<RigidBody*> m_objects;
    bool circleVsCircle(RigidBody* a, RigidBody* b);

public:
    Environment(int width, int height, float coeff_friction);
    void addObject(RigidBody* body);
    void step(float timeStep);
};
