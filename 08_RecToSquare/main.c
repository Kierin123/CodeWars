#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C returns a structure named Data.
// array is the returned array.
// sz is array size.
// If from the beginning square length == square width
// return a Data with sz = 0.

typedef struct Data Data;
struct Data
{
    int *array;
    int sz;
};

Data *sqInRect(int lng, int wdth)
{
    int DataElements = 0;
    Data *Rect = (Data *)malloc(sizeof(Data));
    int Area = lng * wdth;

    if (lng == wdth)
    {
        Rect->sz = DataElements;
        Rect->array = &lng;
        return Rect;
    }

    while ((lng > 0))
    {
        if (lng >= wdth)
        {

            Area = Area - (wdth * wdth);
            lng = lng - wdth;
            Rect->array = &wdth;
        }
        else
        {
            Area = Area - (lng * lng);
            wdth = wdth - lng;
            Rect->array = &lng;
        }
        DataElements++;
        Rect->sz = DataElements;
        Rect = realloc(Rect, sizeof(Data) + (DataElements*sizeof(Data)));
    }

    return Rect;
}

void main(void)
{

    Data *a = sqInRect(5, 3);

    for (int i = 0; i < a->sz; i++)
    {
        printf("%d  \n", a->array[i]);
    }
}