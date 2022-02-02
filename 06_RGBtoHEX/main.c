#include <stdio.h>
#include <stdlib.h>

int rgb(int r, int g, int b, char *output)
{

   char *temp = (char *)malloc(sizeof(char) * 6);
   char signs[17] = "0123456789ABCDEF";
   char values[6];

   if (r < 0)
      r = 0;
   if (g < 0)
      g = 0;
   if (b < 0)
      b = 0;

   if (r > 255)
      r = 255;
   if (g > 255)
      g = 255;
   if (b > 255)
      b = 255;

   values[0] = (int)(r / 16) + '0';
   if (values[0] > 57)
      values[0] = (int)(r / 16) + ('A' - 10);

   values[2] = (int)(g / 16) + '0';
   if (values[2] > 57)
      values[2] = (int)(g / 16) + ('A' - 10);

   values[4] = (int)(b / 16) + '0';
   if (values[4] > 57)
      values[4] = (int)(b / 16) + ('A' - 10);

   values[1] = (int)(r % 16) + '0';
   if (values[1] > 57)
      values[1] = (int)(r % 16) + ('A' - 10);

   values[3] = (int)(g % 16) + '0';
   if (values[3] > 57)
      values[3] = (int)(g % 16) + ('A' - 10);

   values[5] = (int)(b % 16) + '0';
   if (values[5] > 57)
      values[5] = (int)(b % 16) + ('A' - 10);

   for (int i = 0; i < 6; i++)
   {
      temp[i] = values[i];
      output[i] = temp[i];
   }

   free(temp);
   return 0;
}

//_________________________Somebody else solution
unsigned char wrap(int a)
{
   if(a>255) return 255;
   else if(a<0) return 0;
   else return a;
}
int rgb(int r, int g, int b, char *output)
{
   sprintf(output,"%02X%02X%02X\0",wrap(r),wrap(g),wrap(b));
   return 0; 
}



void main()
{
   int r, g, b;
   char tab[7] = "000000";

   printf("Podaj r, g, b: \n");
   scanf("%d", &r);
   scanf("%d", &g);
   scanf("%d", &b);

   rgb(r, g, b, tab);

   printf("%s\n", tab);
}
