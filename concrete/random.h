#pragma once

#ifndef CONCRETE_RANDOM_H
#define CONCRETE_RANDOM_H

#include "concrete.h"
#include <time.h>


namespace concrete
{

    /* Keeps track of one random stream; ie a seed and its output
        This is used to get random numbers. Rather than a function,
        this allows there to be multiple streams of random numbers.
        Uses RandRotB algorithm */
    class Random
    {
        public:

            /* Left bitwise rotation */
            unsigned rotl(unsigned n, unsigned r);

            /* Right bitwise rotation */
            unsigned rotr(unsigned n, unsigned r);

            /* Creates a new random number stream with a seed based on timing data */
            Random();

            /* Creates a new random stream with the given seed */
            Random(unsigned seed);

            /* Sets the seed value for the random stream */
            void seed(unsigned seed);

            /* Returns the next random bitstream from the seed */
            unsigned RandomBits();

            /* Returns a real floating point number between 0 and scale */
            real randomReal(real scale);

            /* Returns a real floating point number between min and max */
            real randomReal(real min, real max);

            /* Returns a random integer less than the given value */
            unsigned randomInt(unsigned max);

            /* Returns a random binomially distributed number between -scale and +scale */
            real randomBinomial(real scale);

            /* Returns a random vector where each component is binomially
                distributed in the range (-scale to scale) [mean = 0.0f] */
            Vector3 randomVector(real scale);

            /* Returns a random vector where each component is binomially
                distributed in the range (-scale to scale) [mean = 0.0f].
                Where scale is the corresponding component of the given vector*/
            Vector3 randomVector(const Vector3 &scale);

            /* Returns a random vector in the cube defined by the given
                minumum and maximum vectors. The probability is uniformly
                distributed in the region */
            Vector3 randomXZVector(const Vector3 &min, const Vector3 &max);

            /* Returns a random orientation [ie normalized] quaternion */
            Quaternion randomQuaternion();

        private:
            /* Internal Mechanics */
            int p1, p2;
            unsigned buffer[17];

    };

}

#endif
