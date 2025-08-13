#pragma once

#ifndef CONCRETE_QUATERNION_H
#define CONCRETE_QUATERNION_H

#include "concrete.h"

namespace concrete
{
    class Quaternion
    {
        public:
            union
            {
                struct
                {
                    /* Holds the real component of the quaternion */
                    real r;

                    /* Holds the first complex component of the quaternion */
                    real i;

                    /* Holds the second complex component of the quaternion */
                    real j;

                    /* Holds the third complex component of the quaternion */
                    real k;
                };

                /* Holds the quaternion data in array form */
                real data[4];

            };
    };
}

#endif
