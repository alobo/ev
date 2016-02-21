#pragma once

#include <eigen3/Eigen/Core>

class NeuralNetwork
{
private:
    Eigen::MatrixXd w1;
    Eigen::MatrixXd w2;

public:
    NeuralNetwork();
    Eigen::MatrixXd process(Eigen::MatrixXd input);
    ~NeuralNetwork();
};
