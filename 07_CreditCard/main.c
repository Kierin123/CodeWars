#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool validate1(long digits)
{
    long dig, sum = 0;
    for (int i = 0; i < 16; i++)
    {
        dig = digits % 10;
        digits = digits / 10;

        if (i % 2)
        {
            dig *= 2;
            if (dig >= 10)
            {
                dig = (dig / 10) + (dig % 10);
            }
        }

        sum += dig;
    }

    return ((sum%10) == 0);
}

// ______________________________________________
bool validate(long digits)
{
    int *buffer = (int *)malloc(sizeof(int) * 16);

    long number = digits;
    int sum = 0;
    bool out;

    for (int i = 0; i < 16; i++)
    {
        buffer[i] = number % 10;
        number = number / 10;
    }

    for (int i = 0; i < 16; i++)
    {
        if (i % 2)
        {
            buffer[i] *= 2;
            if (buffer[i] >= 10)
            {
                buffer[i] = ((buffer[i] / 10) + (buffer[i] % 10));
            }
        }
    }

    for (int i = 0; i < 16; i++)
    {
        sum += buffer[i];
    }

    printf("%d", buffer[0]);
    printf("%d", buffer[1]);
    printf("%d", buffer[2]);
    printf("%d", buffer[3]);
    printf("%d  ", buffer[4]);

    printf("Sum is:  %d \n", sum);
    sum %= 10;

    if (sum == 0)
    {
        out = true;
    }
    else
    {
        out = false;
    }

    printf("OUT is:  %d \n", out);

    return true;
}

void main(void)
{

    validate(2121212121212121);
}