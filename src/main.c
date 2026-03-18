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
    SimulationConfig config;

    int total_spots = 0;
    int max_parking_time = 0;
    int simulation_steps = 0;
    int arrival_probability = 0;
    int random_seed = 0;

    if (read_int("Anzahl Stellplaetze: ", &total_spots) == 0)
    {
        printf("Ungueltige Eingabe\n");
        return 1;
    }

    if (read_int("Maximale Parkdauer: ", &max_parking_time) == 0)
    {
        printf("Ungueltige Eingabe\n");
        return 1;
    }

    if (read_int("Anzahl Zeitschritte: ", &simulation_steps) == 0)
    {
        printf("Ungueltige Eingabe\n");
        return 1;
    }

    if (read_int("Ankunftswahrscheinlichkeit (0-100): ", &arrival_probability) == 0)
    {
        printf("Ungueltige Eingabe\n");
        return 1;
    }

    if (read_int("Zufalls-Seed: ", &random_seed) == 0)
    {
        printf("Ungueltige Eingabe\n");
        return 1;
    }

    if (total_spots <= 0)
    {
        printf("Ungueltige Eingabe\n");
        return 1;
    }

    if (max_parking_time <= 0)
    {
        printf("Ungueltige Eingabe\n");
        return 1;
    }

    if (simulation_steps <= 0)
    {
        printf("Ungueltige Eingabe\n");
        return 1;
    }

    if ((arrival_probability < 0) || (arrival_probability > 100))
    {
        printf("Ungueltige Eingabe\n");
        return 1;
    }

    config.total_spots = total_spots;
    config.max_parking_time = max_parking_time;
    config.simulation_steps = simulation_steps;
    config.arrival_probability = arrival_probability;
    config.random_seed = random_seed;

    simulation_run(config);

    return 0;
}