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

    /*
    FUNCTION main()

        INPUT total_spots
        INPUT max_parking_time
        INPUT simulation_steps
        INPUT arrival_probability
        INPUT random_seed

        IF eine Eingabe ist ungültig THEN
            OUTPUT "Ungueltige Eingabe"
            RETURN 1
        END IF

        config.total_spots ← total_spots
        config.max_parking_time ← max_parking_time
        config.simulation_steps ← simulation_steps
        config.arrival_probability ← arrival_probability
        config.random_seed ← random_seed

        simulation_run(config)

        RETURN 0

    END FUNCTION
    */

    config.total_spots = 0;
    config.max_parking_time = 0;
    config.simulation_steps = 0;
    config.arrival_probability = 0;
    config.random_seed = 0;
}