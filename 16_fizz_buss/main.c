#include <stdio.h>

void main(void)
{
	
    for (int i = 1; i < 101; i++)
    {
        if (((i % 5) == 0) && ((i % 3) == 0))
        {
            printf("fizzbuss\n");
        } else if (i % 3 == 0)
        {
            printf("fizz\n");
        } else if (i % 5 == 0)
        {
            printf("buss\n");
        } else
        printf("%d \n", i);
    }
}
