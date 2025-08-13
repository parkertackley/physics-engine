#pragma once

#include <math.h>

#ifndef CONCRETE_CORE_H
#define CONCRETE_CORE_H

#include "precision.h"

namespace concrete 
{
    
    /* Holds a vector in 3 dimensions, 4 members allocated to ensure alignment in array */
    class Vector3
    {
        public:
            /* Holds x, y, z positions on the repective axes */
            real x;

            real y;

            real z;

        private:
            /* Padding to ensure 4 word alignment */
            real pad;

        public:
            /* Default contructor creates a zero vector */
            Vector3() : x(0), y(0), z(0) {}

            /* Explicit constructor creates vector with given components */
            Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

            /* Flips all components of the vector */
            void invert()
            {
                x = -x;
                y = -y;
                z = -z;
            }

            /* Gets magnitude of the vector aka distance between point a and b */
            real magnitude() const
            {
                return real_sqrt(x*x + y*y + z*z);
            }

            /* Gets the squared magnitude of the vector, well use this later, 
                it saves the call to sqrtf which can be slow on some machines */
            real squareMagnitude() const
            {
                return x*x + y*y + z*z;
            }

            /* Turns a non-zero vector into a vector unit of length */
            void normalize()
            {
                real l = magnitude();

                if(l > 0)
                {
                    (*this) *= ((real)1) / l;
                }
            }

            /* Multiplies this vector by the given scalar */
            void operator*=(const real value)
            {
                x *= value;
                y *= value;
                z *= value;
            }

            /* Returns a copy of this vector scaled to the given value */
            Vector3 operator*(const real value) const
            {
                return Vector3(x*value, y*value, z*value);
            }

            /* Adds the given vector to this */
            void operator+=(const Vector3& v)
            {
                x += v.x;
                y += v.y;
                z += v.z;
            }

            /* Returns the value of the given vector added to this */
            Vector3 operator+(const Vector3& v) const
            {
                return Vector3(x+v.x, y+v.y, z+v.z);
            }

            /* Subtract the given vector from this */
            void operator-=(const Vector3& v)
            {
                x -= v.x;
                y -= v.y;
                z -= v.z;
            }

            /* Returns the value of the given vector subtracted from this */
            Vector3 operator-(const Vector3& v) const
            {
                return Vector3(x-v.x, y-v.y, z-v.z);
            }

            /* Adds given vector to this, scaled by a certain amount */
            void addScaledVector(const Vector3& v, real scale)
            {
                x += v.x * scale;
                y += v.y * scale;
                z += v.z * scale;
            }

            /* Calculates and returns a component-wise product of
                 this vector with the given vector */
            Vector3 componentProduct(Vector3& v) const
            {
                return Vector3(x*v.x, y*v.y, z*v.z);
            }

            /* Performs a component-wise product with the given vector
                and sets this vector to the result */
            void componentProductUpdate(const Vector3& v)
            {
                x *= v.x;
                y *= v.y;
                z *= v.z;
            }

            /* Calculates and returns the scalar product of this vector
                and the given vector */
            real scalarProduct(const Vector3& v) const
            {
                return x*v.x + y*v.y + z*v.z;
            }
            /************** These are very similar, just for ease of use in case of short/long hand preference ***************/
            /* Calculates and returns the scalar product of this vector
                and the given vector */
            real operator *(const Vector3& v) const
            {
                return x*v.x + y*v.y + z*v.z; 
            }

            /* Calculates and returns the vector product
                of this vector and the given vector */
            Vector3 vectorProduct(const Vector3& v) const
            {
                return Vector3(y*v.z - z*v.y,
                            z*v.x - x*v.z,
                            x*v.y - y*v.x);
            }

            /* Updates this vector with the product of its current
                values and the given value */
            void operator %=(const Vector3& v)
            {
                *this = vectorProduct(v);
            }

            /* Calculates and returns the vector product
                of this vector and the given vector */
            Vector3 operator %(const Vector3& v) const
            {
                return Vector3(y*v.z - z*v.y,
                    z*v.x - x*v.z,
                    x*v.y - y*v.x);
            }

    };

}

#endif
