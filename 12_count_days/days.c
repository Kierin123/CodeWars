#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ErrorHandler(int er)
{
    switch (er)
    {
    case 1:
    {
        printf("Wrong value in days\n");
        break;
    }

    case 2:
    {
        printf("Wrong value in months\n");
        break;
    }
    case 3:
    {
        printf("Wrong value in year\n");
        break;
    }

    default:
        break;
    }
}

int tab[2][12] =
    {{0,
      31,
      31 + 28,
      31 + 28 + 31,
      31 + 28 + 31 + 30,
      31 + 28 + 31 + 30 + 31,
      31 + 28 + 31 + 30 + 31 + 30,
      31 + 28 + 31 + 30 + 31 + 30 + 31,
      31 + 28 + 31 + 30 + 31 + 30 + 31 + 30,
      31 + 28 + 31 + 30 + 31 + 30 + 31 + 30 + 31,
      31 + 28 + 31 + 30 + 31 + 30 + 31 + 30 + 31 + 30,
      31 + 28 + 31 + 30 + 31 + 30 + 31 + 30 + 31 + 30 + 31},
     {0,
      31 ,
      31 + 29,
      31 + 29 + 31,
      31 + 29 + 31 + 30,
      31 + 29 + 31 + 30 + 31,
      31 + 29 + 31 + 30 + 31 + 30,
      31 + 29 + 31 + 30 + 31 + 30 + 31,
      31 + 29 + 31 + 30 + 31 + 30 + 31 + 30 ,
      31 + 29 + 31 + 30 + 31 + 30 + 31 + 30 + 31 ,
      31 + 29 + 31 + 30 + 31 + 30 + 31 + 30 + 31 + 30 ,
      31 + 29 + 31 + 30 + 31 + 30 + 31 + 30 + 31 + 30 + 31 }};

int Countdays(const int d, const int m, const int y)
{
    int r;
    if (y % 4 == 0)
    {
        r = 1;
    }
    else r = 0;
    return (tab[r][m-1]) + d;
}

int main(void)
{
    system("clear");
    int dd, mm, yyyy;
    printf("Write actual date(dd.mm.yyyy): ");
    scanf("%2d.%2d.%4d", &dd, &mm, &yyyy);
    if ((dd > 31) || (dd <= 0))
    {
        ErrorHandler(1);
        return -1;
    }
    if ((mm > 12) || (mm <= 0))
    {
        ErrorHandler(2);
        return -1;
    }
    if ((yyyy > 9999) || (yyyy <= 0))
    {
        ErrorHandler(3);
        return -1;
    }
    printf("\nDate: %d.%d.%d \r\n", dd, mm, yyyy);
    printf("\nDays from the begining of the year: %d\r\n", Countdays(dd,mm,yyyy));

    return 0;
}