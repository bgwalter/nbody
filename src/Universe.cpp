#include "Universe.h"

/* constructors */

Universe::Universe() {
    setMin(Vector3()); setMax(Vector3());
    setTimeStep(1);
    numBodies = 0;
}

Universe::Universe(const Vector3& min, const Vector3& max, const float dt) {
    setMin(min); setMax(max);
    setTimeStep(dt);
    numBodies = 0;
}


/* getters */

Vector3 Universe::getMin() const { return min; }
Vector3 Universe::getMax() const { return max; }
float Universe::getTimeStep() const { return timestep; }
std::vector<Body*> Universe::getBodies() const { return bodies; }
int Universe::getNumBodies() const { return numBodies; }


/* setters */

bool Universe::setMin(const Vector3& m) { min = m; return true; }
bool Universe::setMax(const Vector3& m) { max = m; return true; }
bool Universe::setTimeStep(const float dt) {
    if (dt > 0) {
        timestep = dt;
        return true;
    }
    return false;
}

void Universe::addBody(Body* b) {
    bodies.push_back(b);
    numBodies++;
}


/* class specific methods */

void Universe::step() const {
    Body *m1, *m2;
    for (unsigned int m=0; m<bodies.size(); m++) {
        m1 = bodies[m];

        for (unsigned int n=0; n<bodies.size(); n++) {
            m2 = bodies[n];
            if (m1 != m2) {
                Vector3 force = m1->calcForce(*m2, timestep);
                m1->setForce(force);
                m1->updatePosition(timestep);
                m1->clearForce();
            }
        }
    }
}
