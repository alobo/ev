#pragma once

#include <vector>
#include <eigen3/Eigen/Core>

#include "RigidBody.h"

class Environment {
private:
    int m_width;
    int m_height;
    std::vector<RigidBody> m_objects;

public:
    Environment(int width, int height);
    void addObject(RigidBody body);
    void step(float timeStep);
};
