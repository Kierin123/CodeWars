#include <stdio.h>

char *create_phone_number(char phnum[15], const unsigned char nums[10])
{
  int j = 0;
  for (int i = 0; i < 14; i++)
  {
    switch (i)
    {
    case 0:
    {
      phnum[i] = '(';
    }
    break;
    case 4:
    {
      phnum[i] = ')';
    }
    break;
    case 5:
    {
      phnum[i] = ' ';
    }
    break;
    case 9:
    {
      phnum[i] = '-';
    }
    break;

    default:

    {
      phnum[i] = nums[j] + 48;
      j++;
    }
    break;
    }
  }

  return phnum;
}

void main()
{
  char tab[15];
  const unsigned char number[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

  printf(create_phone_number(tab, number));
}