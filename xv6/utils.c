// A bunch of utils tools needed
// to implement others thing

#include "types.h"
#include "defs.h"

int
pow(int x, int n)
{
    int number = 1;

    for (int i = 0; i < n; ++i)
        number *= x;

    return(number);
}
