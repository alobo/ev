#pragma once

#include <iostream>
#include <eigen3/Eigen/Core>

class NeuralNetwork
{
friend class Mutator;
private:
    Eigen::MatrixXd w1;
    Eigen::MatrixXd wh; // Hidden layer
    Eigen::MatrixXd wh2; // Hidden layer
    Eigen::MatrixXd w2;

public:
    NeuralNetwork();
    Eigen::MatrixXd process(Eigen::MatrixXd input);
    ~NeuralNetwork();

    friend std::ostream& operator<< (std::ostream &out, const NeuralNetwork &brain);
};
