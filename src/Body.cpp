#include "Body.h"

bool Body::seeded = false;

double Body::randNum(const double min, const double max) const {
    return min + (double)rand() / RAND_MAX * (max - min);
}

Vector3 Body::randVec(const double min, const double max) const {
    return Vector3(randNum(min, max), randNum(min, max), randNum(min, max));
}

/* constructors */

Body::Body() {
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }

    Vector3 empty;
    setBody(empty, empty, empty, 0);
}

Body::Body(const Vector3& p, const Vector3& v,
           const Vector3& f, const double m) {
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }

    setBody(p, v, f, m);
}


/* getters */

Vector3 Body::getPosition() const { return position; }
Vector3 Body::getVelocity() const { return velocity; }
Vector3 Body::getForce() const { return force; }
double Body::getMass() const { return mass; }


/* setters */

bool Body::setPosition(const Vector3& p) { position = p; return true; }
bool Body::setVelocity(const Vector3& v) { velocity = v; return true; }
bool Body::setForce(const Vector3& f) { force = f; return true; }
bool Body::setMass(const double m) {
    if (m > 0) {
        mass = m;
        return true;
    }
    return false;
}
bool Body::setBody(const Vector3& p, const Vector3& v,
                   const Vector3& f, const double m) {

    if (setPosition(p) && setVelocity(v) && setForce(f) && setMass(m))
        return true;
    return false;
}

bool Body::setRandomPosition(const double min, const double max) {
    if (setPosition(randVec(min, max)))
        return true;
    return false;
}

bool Body::setRandomVelocity(const double min, const double max) {
    if (setVelocity(randVec(min, max)))
        return true;
    return false;
}

bool Body::setRandomMass(const double min, const double max) {
    if (setMass(randNum(min, max)))
        return true;
    return false;
}


/* class specific methods */

void Body::print() {
    std::cout<< "Position: "; position.print();
    std::cout<< "Velocity: "; velocity.print();
    std::cout<< "Force:    "; force.print();
    std::cout<< "Mass:     " << mass <<std::endl;
    std::cout<<std::endl;
}

double Body::getDistance(const Body& b) const {
    return (b.getPosition() - getPosition()).getMagnitude();
}

Vector3 Body::calcForce(const Body& b, const float dt) const {
    double G = 6.67408E-11; // m^3 kg^-1 s^-2
    double epsilon = 3E4;   // softening factor to avoid singularities
    double fg = (G * getMass() * b.getMass()) /
                (pow(getDistance(b), 2) + pow(epsilon, 2));
    Vector3 f = (b.getPosition() - getPosition()).normalize() * fg;
    return f;
}

void Body::updatePosition(const float dt) {
    velocity += force / mass * dt;
    position += velocity * dt;
}

void Body::clearForce() {
    setForce(Vector3());
}
