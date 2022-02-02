#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  choose a text in capital letters including or not digits and non alphabetic characters,
//
//      shift each letter by a given number but the transformed letter must be a letter (circular shift),
//      replace each digit by its complement to 9,
//      keep such as non alphabetic and non digit characters,
//      downcase each letter in odd position, upcase each letter in even position (the first character is in position 0),
//      reverse the whole result.

const char *characters[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
const char *numeric[11] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int isChar(char cSigntoCheck)
{
    if ((cSigntoCheck >= 65) && (cSigntoCheck <= 90))
        return 1;
    else
        return 0;
}

int isDigit(char cSigntoCheck)
{
    if ((cSigntoCheck >= 48) && (cSigntoCheck <= 57))
        return 1;
    else
        return 0;
}

char *playPass(char *s, int n)
{
    char *output = (char *)calloc(strlen(s), 1);
    char *output1 = (char *)calloc(strlen(s), 1);
    

    for (int i = 0; i < (int)strlen(s); i++)
    {
        if (isChar(s[i]))
        {
            for (int j = 0; j < 25; j++)
            {
                if (s[i] == *characters[j])
                {
                    output[i] = *characters[j] + n;
                    if (output[i] > 90)
                    {
                        output[i] = (64 + (output[i] - 90));
                    }
                    break;
                }
            }
        }
        else if (isDigit(s[i]))
        {
            for (int j = 0; j < 11; j++)
            {
                if (s[i] == *numeric[j])
                {
                    output[i] = *numeric[j] + 9;
                    if (output[i] > 57)
                    {
                        output[i] = (47 + (output[i] - 57));
                    }
                    break;
                }
            }
        }
        else
            output[i] = s[i];
    }
    int d = (int) strlen(s);
    for (int i = 0; i < (int)strlen(s); i++)
    {
        output1[d - 1] = output[i];
        d--;
    }

    for (int i = 0; i < (int)strlen(s); i++)
    {
        if ((isChar(output1[i])) && (i % 2))
        {
            output1[i] += 32;
        }
    }

    return output1;
}

void main(void)
{
    char *origin = "I LOVE YOU!!!";
    char *reversed;

    printf("Origin: %s \r\n", origin);
    reversed = playPass(origin, 1);

    printf("Reversed: %s \r\n", reversed);

origin = "AAABBCCY";
      printf("Origin: %s \r\n", origin);
    reversed = playPass(origin, 1);

    printf("Reversed: %s \r\n", reversed);

    origin = "MY GRANMA CAME FROM NY ON THE 23RD OF APRIL 2015";
      printf("Origin: %s \r\n", origin);
    reversed = playPass(origin, 2);

    printf("Reversed: %s \r\n", reversed);
}
