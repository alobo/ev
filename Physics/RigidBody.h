#pragma once

#include <eigen3/Eigen/Core>

class RigidBody {
public:
    float mass;
    float radius;
    Eigen::Vector2f size;
    Eigen::Vector2f position;
    Eigen::Vector2f velocity;
    Eigen::Vector2f acceleration;
};
