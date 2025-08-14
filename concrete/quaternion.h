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

            /* Default constructor creates a Quaternion represtening a 0 rotation */
            Quaternion() : r(1), i(0), j(0), k(0){}

            /* Explicit constructor creates a Quaternion with the given components
            
                - r is the real component of the rigid body's orientation quaternion

                - i, j, k are the first, second, third (respectively) complex
                    component of the rigid body's orientation quaternion
            */
            Quaternion(const real r, const real i, const real j, const real k)
                : r(r), i(i), j(j), k(k) {}


            /* Normalises the Quaternion to unit length, making it a valid orientation quaternion */
            void normalise()
            {
                real d = r*r + i*i + j*j + k*k;

                if(d < real_epsilon)
                {
                    r = 1;
                    return;
                }

                d = ((real)1.0)/ real_sqrt(d);
                r *= d;
                i *= d;
                j *= d;
                k *= d;

            }

            /* Mulitplies the quaternion by the given quaternion */
            void operator *=(const Quaternion &multiplier)
            {
                Quaternion q = *this;

                r = q.r*multiplier.r - q.i*multiplier.i - q.j*multiplier.j - q.k*multiplier.k;

                i = q.r*multiplier.i + q.i*multiplier.r + q.j*multiplier.k - q.k*multiplier.j;

                j = q.r*multiplier.j - q.i*multiplier.k + q.j*multiplier.r + q.k*multiplier.i;

                k = q.r*multiplier.k + q.i*multiplier.j - q.j*multiplier.i + q.k*multiplier.r;

            }

            /* Adds a given vector to this, scaled by a given amount
                This is used to update the orientation quaternion 
                by a rotation and time */
            void addScaledVector(const Vector3& v, real scale)
            {
                Quaternion q(0, 
                    v.x * scale,
                    v.y * scale,
                    v.z * scale);

                q *= *this;
                r += q.r * ((real)0.5);
                i += q.i * ((real)0.5);
                j += q.j * ((real)0.5);
                k += q.k * ((real)0.5);

            }

            /* Rotates the orientatin quaternion by the given vector */
            void rotateByVector(const Vector3& v)
            {
                Quaternion q(0, v.x, v.y, v.z);
                (*this) *= q;
            }

    };
}

#endif
