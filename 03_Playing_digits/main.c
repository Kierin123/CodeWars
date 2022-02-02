#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *series_sum(const size_t n)
{
    unsigned long val = n;
    float val_f = 0.00f;
    char *res;
    res = malloc(sizeof(char) * 4);

    if (val > 0)
    {
        val_f = 1.00f;
        for (int i = 0; i < val - 1; i++)
        {
            val_f = val_f + (1.00f / (4.00f + 3.00f * (float)i));
        }

        val_f = val_f;
    }

    sprintf(res, "%1.2f", val_f);
    return res;
}

char *series_sum1(const int n) // solution of somebody else
{
  double result = n ? 1. : 0.;
  char *s = (char *)malloc(10 * sizeof(char));

  for (int i = 1; i < n; i++) result += 1. / (3 * i + 1);
  sprintf(s, "%.2lf", result);
  return s;
}

char *series_sum(const size_t n) // solution of somebody else
{
  size_t i;
  int divisor;
  double sum;
  char * result;
  
  for(i = 0, divisor = 1, sum = 0.0; i < n; ++i, divisor += 3)
  {
    sum += 1.0 / (double)divisor;
  }
  
  result = malloc(32);
  
  if(!result)
    return NULL;

  sprintf(result, "%.02f", sum);
  
  return result;
}

void main()
{
    int s;
    scanf("%d", &s);
    char c[4]; //size of the number

    //  sprintf(c, "%1.2f", series_sum(i));
    printf(series_sum(s));
    printf("\n");
}