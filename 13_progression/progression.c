#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>




int find_missing(const int * nums, size_t n)
{
    int diff1 = *(nums + 1) - *(nums);
    int diff2 = *(nums + (n - 1)) - *(nums + (n - 2));
    int diff3 = *(nums + (n - 2)) - *(nums + (n - 3));

    

    int diff = diff1;

    if (abs(diff) >= abs(diff2))
    {
        diff = diff2;
    }
    else
    {
        diff = diff;
    }
   if (abs(diff) >= abs(diff3))
   {
        diff = diff3;
    }
    else
    {
        diff = diff;
    }

    int val = *nums;
    for (int i = 0; i < n; i++)
    {
        if (val == *nums)
        {
            val = val + diff;
            nums++;
        }
        else
        {
            return val;
        }
    }
    return val;
}


// Other solution - check the equasion for arythmetic progression
int find_missing1(const int *nums, size_t n)
{
    int sum = (n+1)*(nums[0]+nums[n-1]) / 2;
    for (int i = 0; i < n; ++i)
        sum -= nums[i];
        
    return sum;
}
//_____________________________________________

void main(void)
{
    int tab[6] = {1, 3, 7, 9, 11};
    int tab1[6] = {-1, -3, -7, -9, -11};
    int tab2[6] = {1, 11, 21, 41, 51};
    int tab3[6] = {1, 21, 31, 41, 51};
    int tab4[7] = {-1, -3, -5, -7, -9, -13};

    printf("%d \n", find_missing(tab, 5));
    printf("%d \n", find_missing(tab1, 5));
    printf("%d \n", find_missing(tab2, 5));
    printf("%d \n", find_missing(tab3, 5));
    printf("%d \n", find_missing(tab4, 7));
}