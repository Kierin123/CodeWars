#include <stdbool.h>
#include <stdio.h>

void the_true()
{
    printf("true - wydrukowane z funkcji\n");
}

void the_false()
{
    printf("false - wydrukowane z funkcji\n");
}

void _if(bool value, void (*func1)(), void (*func2)())
{
    if (value == true)
    {
        func1();
        return;
    }
    else
    {
        func2();
        return;
    }
}

void main()
{
    int we = 0;
    bool func_value = false;
    printf("Podaj prawda (1) lub fałsz (0): ");
    scanf("%d", &we);

    if (we > 0)
    {
        func_value = true;
        _if(func_value, the_true, the_false);
    }
    else
    {
        func_value = false;
        _if(func_value, the_true, the_false);
    }
}