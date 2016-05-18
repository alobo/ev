#include "Creature.h"

class Mutator
{
private:
    Creature *m_target;

public:
    Mutator();
    void setTarget(Creature *target);
    void mutate(Creature *c);
    ~Mutator();
};
