#include <stdio.h>
#include <string.h>

int test(int, int, int);

void main(void)
{

    char str1[27] = "ADCBEFGHIJKOLMNUPRSTUVWXYZ";
    char str2[27] = "ADRCBEFGITJKHLNOUPSUVWMXYZ";
    char search = ' ';

    printf("Length od string: %d\r\n", strlen(str1));
    printf("Length od string: %d\r\n", strlen(str2));
    printf("String compare: %d\r\n", strcmp(str1, str2));
    printf("Write the sign what you want to find: ");
    scanf("%c", &search);

    char *place1 = (char *)memchr(&str1, search, strlen(str1));
    char *place2 = (char *)memchr(&str2, search, strlen(str2));

    printf("%c in str1 is locate: %d\r\n",search,  place1 - str1);
    printf("%c in str2 is locate: %d\r\n",search, place2 - str2);

    printf("Test function: %d\r\n", test(1, 4, 4));
}

int test(int a, int b, int c)
{
}