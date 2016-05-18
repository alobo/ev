#include <math.h>
#include <iostream>
#include <eigen3/Eigen/LU>
#include <eigen3/Eigen/Dense>
#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork() {
    w1 = Eigen::MatrixXd::Random(4,3);
    wh = Eigen::MatrixXd::Random(4,4);
    wh2 = Eigen::MatrixXd::Random(4,4);
    w2 = Eigen::MatrixXd::Random(2,4);
}

Eigen::MatrixXd NeuralNetwork::process(Eigen::MatrixXd p) {
    // Feed forward through hidden layer and get output
    return w2 * wh2 * wh * (w1*p);
}

NeuralNetwork::~NeuralNetwork() {
}

std::ostream& operator<< (std::ostream &out, const NeuralNetwork &network) {
    out << "w1:" << std::endl << network.w1 << std::endl;
    out << "wh:" << std::endl << network.wh << std::endl;
    out << "w2:" << std::endl << network.w2 << std::endl;
    return out;
}
