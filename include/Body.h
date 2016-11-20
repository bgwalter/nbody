#ifndef BODY_H
#define BODY_H

#include <iostream>
#include <cstdlib>

#include "Vector3.h"

/*
Create a body within 3D space

The position, velocity, and total forces acting on the body are represented by
3D vectors (`Vector3`) while the mass of the object is represented by a double.
*/
class Body {
  private:
    Vector3 position;
    Vector3 velocity;
    Vector3 force;
    double mass;

    static bool seeded;     // boolean to check if a seed has been generated

    /*
    Generate a random number
    */
    double randNum(const double, const double) const;

    /*
    Generate a random vector
    */
    Vector3 randVec(const double, const double) const;

  public:

    /* constructors */

    Body();
    Body(const Vector3&, const Vector3&,    // position, velocity,
         const Vector3&, const double);     // force, mass


    /* getters */

    Vector3 getPosition() const;
    Vector3 getVelocity() const;
    Vector3 getForce() const;
    double getMass() const;


    /* setters */

    /*
    Assign a value to each member variable. Returns true if the input is valid (ex: mass cannot be a negative value.)
    */
    bool setPosition(const Vector3&);
    bool setVelocity(const Vector3&);
    bool setForce(const Vector3&);
    bool setMass(const double);
    bool setBody(const Vector3&, const Vector3&,    // position, velocity,
                 const Vector3&, const double);     // force, mass

    /*
    Assign a random value to each member variable within the given range

    Ex: To

    Parameters
    ----------
    min : double
        The minimum value for the generated number
    max : double
        The maximum value for the generated number

    Returns
    -------
    True if the value is successfully assigned
    */
    bool setRandomPosition(const double, const double);
    bool setRandomVelocity(const double, const double);
    bool setRandomMass(const double, const double);


    /* class specific methods */

    /*
    Print the position, velocity, total acting forces, and mass of the body
    */
    void print();

    /*
    Calculate the distance between self and another body

    Parameters
    ----------
    b : `Body`
        the body to calculate the distance from

    Returns
    -------
    The distance as a double
    */
    double getDistance(const Body&) const;

    /*
    Calculate the gravitational force acting on self from another body

    Parameters
    ----------
    b : `Body`
        the body acting on self
    dt : float
        time step in seconds used in calculations

    Returns
    -------
    The resulting force acting on self as a Vector3
    */
    Vector3 calcForce(const Body&, const float) const;

    /*
    Update the position and the velocity vectors of the body using current
    force vectors

    Parameters
    ----------
    dt : float
        time step in seconds used in calculations
    */
    void updatePosition(const float);


    /*
    Reset the force vector for self to <0, 0, 0>.
    This should be called after every time step.
    */
    void clearForce();

};

#endif
