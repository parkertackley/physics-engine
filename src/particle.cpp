#include <assert.h>
#include "../concrete/particle.h"

using namespace concrete;

void Particle::integrate(real duration)
{

    assert(duration > 0.0);

    /* Update linear position */
    position.addScaledVector(velocity, duration);

    /* Workout acceleration from force */
    Vector3 resultingAccel = acceleration;
    resultingAccel.addScaledVector(forceAccum, inverseMass);

    /* Update linear velocity from the acceleration */
    velocity.addScaledVector(resultingAccel, duration);

    /* Impose drag/damping */
    velocity *= real_pow(damping, duration);

}
