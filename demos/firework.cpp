#include "../concrete/concrete.h"

#include <stdio.h>

class Firework : public concrete::Particle
{
    public:
        /* We use this as a fuze. The age slowly decreases as time goes on */
        concrete::real age;

        /* Updates the fireworks on the given duration of time. 
            Returns true if the firework has reached the end of
            it's life and needs to be removed */
        bool update(concrete::real duration)
        {
            /* Update our physical state */
            integrate(duration);

            /* Work backwards from our age to zero */
            age -= duration;
            return (age < 0);

        }

};

/* The firework's rules control the fuze time along with characteristics like the particles it evolves into */
struct FireworkRule
{

    /* The type of firework */
    unsigned type;

    /* Minimum length of fuze */
    concrete::real minAge;

    /* Maximum length of fuze */
    concrete::real maxAge;

    /* Min relative veloicty of the firework */
    concrete::Vector3 minVelocity;

    /* Max relative veloicty of the firework */
    concrete::Vector3 maxVelocity;

    /* The damping of the firework type */
    concrete::real damping;

    /* Payload is the new firework type to create once the fuze is over (when the firework ignites) */
    struct Payload
    {

        /* Type of the new particle to create */
        unsigned type;

        /* The amount of particles to create */
        unsigned count;

    };

    /* Number of payloads for this firework type */
    unsigned payloadCount;

    /* Set of payloads */
    Payload *payloads;

    void create(Firework *firework, const Firework *parent = NULL) const
    {

    }

};

void FireworksDemo::initFireworkRules()
{
    rule[0].setParameters(
        1,                                  // type
        3, 5,                               // age range (min length, max length)
        concrete::Vector3(-5, -5, -5),      // min velocity
        concrete::Vector3(5, 5, 5),         // max velocity
        0.1                                 // damping
    );

    /* TODO: create more firework instances */

}
