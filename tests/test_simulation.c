/*
*File: test_simulation.c
*Beschreibungen: Testet die Funktionen von simulation.c
*/

#include <assert.h>
#include <stdio.h>

#include "simulation.h"

static void test_simulation_init_valid_(void){
    SimulationConfig config;

    config.total_spots = 5;
    config.max_parking_time = 10;
    config.simulation_steps = 10;
    config.arrival_probability = 50;
    config.random_seed = 1;

    assert(simulation_init(config) == true);
}


void test_simulation_init_small_values(void)
{
    SimulationConfig config;

    config.total_spots = 1;
    config.max_parking_time = 1;
    config.simulation_steps = 1;
    config.arrival_probability = 0;
    config.random_seed = 1;

    assert(simulation_init(config) == true);
}


//Sammelfunktion

void run_simulation_tests(void){
    test_simulation_init_valid_();
    test_simulation_init_small_values();
}
