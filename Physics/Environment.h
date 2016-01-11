#pragma once

#include <vector>
#include <eigen3/Eigen/Core>

#include "RigidBody.h"

class Environment {
private:
    int width_;
    int height_;
    std::vector<RigidBody> objects_;

public:
    Environment(int width, int height);
    void addObject(RigidBody body);
    void step(float timeStep);
};
