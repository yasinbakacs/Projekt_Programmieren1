/*
 * File: main.c
 * Beschreibung: Liest Parameter ein und startet die Simulation.
 */

#include <stdio.h>
#include "simulation.h"


static int read_int(const char *p_prompt, int *p_value)
{
    int result = 0;

    if (p_prompt == NULL)
    {
        return 0;
    }

    if (p_value == NULL)
    {
        return 0;
    }

    printf("%s", p_prompt);

    result = scanf("%d", p_value);
    if (result != 1)
    {
        return 0;
    }

    return 1;
}


int main(void)
{
    
}