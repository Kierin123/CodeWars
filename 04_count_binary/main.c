#include <stdio.h>
#include <stdlib.h>

size_t countBits(unsigned value)
{
    int count = 0;
    for (; value; value >>= 1)
    {
        if (value & 1)
        {
            count++;
        }
    }

    return count;

    /*
   // int tab[32] = {0};
    int div_n = value;
    int mod_n = 0;
    size_t count = 0;
    for (int i = 0; i < 32; i++)
    {
        mod_n = div_n % 2;
        div_n = div_n / 2;
  //      tab[i] = mod_n;
        if (mod_n > 0)
        {
            count++;
        }
    }

    return count;

    */
}

size_t countBits1(unsigned value) // somebody else solution
{
    size_t count = 0;
    for (; value; value >>= 1)
        if (value & 1)
            count++;
    return count;
}

void main()
{
    size_t x;
    scanf("%d", &x);
    printf("%d", countBits(x));
}