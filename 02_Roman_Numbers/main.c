#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <string.h>

enum
{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000,
};

char *solution(const int n)
{
    int divider[7] = {1000, 500, 100, 50, 10, 5, 1};
    char signs[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    char result[100];

    int index = 0;
    int sign_index = 0;

    int _div_value = 0;
    int _mod_value = 1;
    int value = n;

    while (sign_index < 7)
    {
        _div_value = value / divider[sign_index];
        value = value % divider[sign_index];
        if (_div_value >= 4)
        {
            result[index] = signs[sign_index +1 ];
            result[index+1] = signs[sign_index];
            index += 2;
            sign_index++;
            continue;
        }
        while (_div_value <= 0)
        {
            result[index] = signs[sign_index];
            index++;
            
        }
        sign_index++;
    }

    return result;
}

void main()
{
    int licz = 0;
    

    printf("Podaj liczbe: ");
    scanf("%d", &licz);
   
    printf("Liczba rzymska: %s", solution(licz));
}
