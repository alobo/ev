#pragma once

#include <eigen3/Eigen/Core>

class RigidBody {
public:
    float mass;
    Eigen::Vector2f position;
    Eigen::Vector2f velocity;
    Eigen::Vector2f acceleration;
};
