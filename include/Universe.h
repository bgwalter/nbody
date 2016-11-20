#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>

#include "Vector3.h"
#include "Body.h"


/*
Create the universe in which all bodies reside

The universe has a set size, a set timestep, and holds every object (`Body`) in
the universe in a std::vector.
*/
class Universe {
  private:
      Vector3 min, max;     // size of universe
      float timestep;       // size of time step (in seconds)
      std::vector<Body*> bodies; // vector containing all bodies in the universe
      int numBodies;        // length of bodies

  public:

      /* constructors */

      Universe();
      Universe(const Vector3&, const Vector3&,  // min, max
               const float);                    // timestep


      /* getters */

      Vector3 getMin() const;
      Vector3 getMax() const;
      float getTimeStep() const;
      std::vector<Body*> getBodies() const;
      int getNumBodies() const;


      /* setters */

      /*
      Set the minimum and maxium size of the universe, as well as the size of
      each timestep (in seconds). Returns true if the input is valid (in this
      case, if the values are positive and the maximum and timestep are not 0.)
      */
      bool setMin(const Vector3&);
      bool setMax(const Vector3&);
      bool setTimeStep(const float);

      /*
      Add a new body to the universe
      */
      void addBody(Body*);


      /* class specific methods */

      /*
      Step the program forward in time by the size of timestep
      */
      void step() const;

};

#endif
