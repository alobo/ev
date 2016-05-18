#include "Mutator.h"

Mutator::Mutator(){
}

void Mutator::setTarget(Creature *target){
    m_target = target;
}

void Mutator::mutate(Creature *c){

    Eigen::MatrixXd mutation = Eigen::MatrixXd::Random(
        m_target->m_network.w1.rows(),
        m_target->m_network.w1.cols()
    );
    mutation *= 0.1;
    c->m_network.w1 = m_target->m_network.w1.cwiseProduct(mutation);

    mutation = Eigen::MatrixXd::Random(
        m_target->m_network.w2.rows(),
        m_target->m_network.w2.cols()
    );
    mutation *= 0.1;
    c->m_network.w2 = m_target->m_network.w2.cwiseProduct(mutation);
}

Mutator::~Mutator(){
}
