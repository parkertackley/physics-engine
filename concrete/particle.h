#pragma once

/* A particle is the simplest object to be simulated in a physics engine */
#ifndef CONCRETE_PARTICLE_H
#define CONCRETE_PARTICLE_H

#include "core.h"

namespace concrete {

    class Particle {
        public:
            /* Holds linear position of the particle */
            Vector3 position;

            /* Holds linear velocity of the particle */
            Vector3 velocity;

            /* Holds acceleration of the particle.
                Can be used to set acceleration due to gravity */
            Vector3 acceleration;

            /* Holds damping/drag for linear motion.
                Required to remove energy added through numerical instability */
            real damping;

            /* Holds the accumulated force to be applied at the next
                simulation iteration only. This value is zeroed at each
                integration step */
            Vector3 forceAccum;

            /* Holds the inverse of the mass of the particle */
            real inverseMass;

            /* Integrates the particle forward in time by the given amount.
                This function uses a Newton-Euler integration method, which is a
                linear approximation of the correct integral. For this reason it
                may be inaccurate in some cases. */
            void integrate(real duration);

    };
}

#endif
