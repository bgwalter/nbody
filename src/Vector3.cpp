#include "Vector3.h"

/* constructors */

Vector3::Vector3() { setVector(0, 0, 0); }
Vector3::Vector3(const double x, const double y, const double z) {
    setVector(x, y, z);
}


/* getters */

double Vector3::getx() const { return x; }
double Vector3::gety() const { return y; }
double Vector3::getz() const { return z; }


/* setters */

bool Vector3::setx(const double x) { this->x = x; return true; }
bool Vector3::sety(const double y) { this->y = y; return true; }
bool Vector3::setz(const double z) { this->z = z; return true; }

bool Vector3::setVector(const double x, const double y, const double z) {
    if (setx(x) && sety(y) && setz(z))
        return true;
    return false;
}

/* class specific methods */

void Vector3::print() const {
    std::cout<< "<" << x << ", " << y << ", " << z << ">" <<std::endl;
}

double Vector3::getMagnitudeSquared() const {
    return pow(x, 2) + pow(y, 2) + pow(z, 2);
}

double Vector3::getMagnitude() const {
    return sqrt(getMagnitudeSquared());
}

Vector3 Vector3::normalize() const {
    return *this/getMagnitude();
}

double Vector3::dot(const Vector3& v) const {
   return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::cross(const Vector3& v) const {
    Vector3 u(
        y * v.z - z * v.y,
       -x * v.z + z * v.x,
        x * v.y - y * v.x
    );

    return u;
}

/* operator overloads */

Vector3 Vector3::operator+(const Vector3& v) const {
    Vector3 u(
        x + v.x,
        y + v.y,
        z + v.z
    );

    return u;
}

Vector3 Vector3::operator-(const Vector3& v) const {
    Vector3 u(
        x - v.x,
        y - v.y,
        z - v.z
    );

    return u;
}

Vector3 Vector3::operator*(const double d) const {
    Vector3 u(x*d, y*d, z*d);
    return u;
}

Vector3 Vector3::operator/(const double d) const {
    Vector3 u(x/d, y/d, z/d);
    return u;
}

void Vector3::operator=(const Vector3& v) {
    setVector(v.x, v.y, v.z); }

void Vector3::operator+=(const Vector3& v) {
    setVector(x + v.x, y + v.y, z + v.z);
}

void Vector3::operator-=(const Vector3& v) {
    setVector(x - v.x, y - v.y, z - v.z);
}

void Vector3::operator*=(const double d) {
    setVector(x*d, y*d, z*d);
}
void Vector3::operator/=(const double d) {
    setVector(x/d, y/d, z/d);
}

bool Vector3::operator!=(const Vector3& v) const {
    if ( x != v.x && y != v.y && z != v.z) return true;
    return false;
}

bool Vector3::operator==(const Vector3& v) const {
    if ( x == v.x && y == v.y && z == v.z) return true;
    return false;

}
