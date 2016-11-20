#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <cmath>

/*
Create a 3D vector
*/
class Vector3 {
  private:
    double x, y, z;

  public:

    /* constructors */

    Vector3();
    Vector3(const double, const double, const double);  // x, y, z


    /* getters */

    double getx() const;
    double gety() const;
    double getz() const;


    /* setters */

    /*
    Assign a value to each member variable. Returns true if the input is valid.
    (Note: for a Vector3, all input values are considered valid. Returning a
    boolean is to keep this class implementation consistent across the program.)
    */
    bool setx(const double);
    bool sety(const double);
    bool setz(const double);
    bool setVector(const double, const double, const double);   // x, y, z


    /* class specific methods */

    /*
    Print the coordinates of the vector
    */
    void print() const;

    /*
    Return the square of the magnitude of the vector
    */
    double getMagnitudeSquared() const;

    /*
    Return the magnitude (length) of the vector
    */
    double getMagnitude() const;

    /*
    Return the normalized version of the vector, otherwise known as a unit
    vector
    */
    Vector3 normalize() const;

    /*
    Return the dot or cross product of self and another vector

    Parameters
    ----------
    v : `Vector3`
        The vector to dot or cross self with

    Returns
    -------
    The resulting product
    */
    double dot(const Vector3&) const;
    Vector3 cross(const Vector3&) const;


    /* operator overloads */

    Vector3 operator+(const Vector3&) const;    // vector addition
    Vector3 operator-(const Vector3&) const;    // vector subration
    Vector3 operator*(const double) const;      // multiply by a scalar
    Vector3 operator/(const double) const;      // divide by a scalar

    void operator=(const Vector3&);
    void operator+=(const Vector3&);
    void operator-=(const Vector3&);
    void operator*=(const double);
    void operator/=(const double);

    bool operator!=(const Vector3&) const;
    bool operator==(const Vector3&) const;

};

#endif
