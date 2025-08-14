#include "../concrete/concrete.h"

#include <ctime>
#include <cstdlib>

using namespace concrete;

Random::Random()
{
    seed(0);
}

Random::Random(unsigned seed)
{
    Random::seed(seed);
}

void Random::seed(unsigned s)
{
    if(s == 0)
    {
        s = (unsigned)clock();
    }

    /* Fill the buffer with some random numbers */
    for(unsigned i = 0; i < 17; i++)
    {
        s = s * 2891336453 + 1;
        buffer[i] = s;
    }

    /* Initialize pointers into the buffer */
    p1 = 0;
    p2 = 10;

}

unsigned Random::rotl(unsigned n, unsigned r)
{
    return (n << r) | (n >> 32 - r);
}

unsigned Random::rotr(unsigned n, unsigned r)
{
    return (n >> r) | (n << 32 - r);
}
