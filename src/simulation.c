/*
 * File: Simulation.c
 * Description: C-Datei für die Simulation eines Parkhauses.
 */

/* Einbinden der Standardbibliotheken und nötigen Header */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "statistics.h"
#include "simulation.h"

// Einbinden der Variablen für Parkhaus, Warteschlange und Statistik
static ParkingGarage g_garage;
static queue g_queue;
static int g_next_id = 1;
static Stats g_stats;

/**
 * @brief Initialisiert die Simulation.
 */
bool simulation_init(SimulationConfig config)
{
    bool ok = false;

    srand(config.random_seed); //Zufalls-Seed setzen

    ok = initGarage(&g_garage, config.total_spots);
    if (ok == false) {
        printf("Parkhaus konnte nicht initialisiert werden.\n");
        return false;
    }

    queue_init(&g_queue);

    ok = stats_init(&g_stats, "docs/simulation_steps.txt");
    if (ok == false){
        printf("Statistik konnte nicht initialisiert werden.\n");
    }

    g_next_id = 1;
    
    return true;
}

/**
 * @brief Startet die Simulation.
 */
void simulation_run(SimulationConfig config)
{
    
    bool ok = false;

    ok = simulation_init(config); // Simulation initialisieren und prüfen
    if (ok == false){
        printf("Simulation konnte nicht initialisiert werden.\n");
        return;
    }

    for (int step = 0; step < config.simulation_steps; step++){
        simulation_step(config, step);
    }

    stats_print(&g_stats);
    stats_close(&g_stats);

    queue_free(&g_queue);
    freeGarage(&g_garage);
}

/**
 * @brief Führt einen einzelnen Zeitschritt aus.
 */
void simulation_step(SimulationConfig config, int step)
{
    int parked_this_step = 0;
    int departures_this_step = 0;
    int random_value = 0;
    int free_index = -1;
    int ok = 0;

    vehicle new_vehicle;
    vehicle queued_vehicle;
    StepStats step_stats;

    random_value = rand() % 100;
    
    if (random_value < config.arrival_probability){
        new_vehicle = vehicle_create(&g_next_id, config.max_parking_time, step);

        free_index = findFreeSpot(&g_garage);
        if (free_index != -1){
            ok = parkVehicle(&g_garage, new_vehicle);
            if (ok == 1){
                parked_this_step += 1;
            }
        }else {
            ok = queue_enqueue(&g_queue, new_vehicle);
            if (ok ==0){
                printf("Auto konnte nicht in die Queue eingeführt werden.\n");
            }
        }
    }

    processDepartures(&g_garage, &departures_this_step);

    while((findFreeSpot(&g_garage) != -1) && (queue_is_empty(&g_queue) == 0)){
        ok = queue_dequeue(&g_queue, &queued_vehicle);
        if (ok == 1){
            ok = parkVehicle(&g_garage, queued_vehicle);
            if (ok == 1){
                parked_this_step += 1;
            }
        }
    }

    step_stats.step = step;
    step_stats.occupied_spots = g_garage.occupiedCount;
    step_stats.queue_length = queue_get_size(&g_queue);
    step_stats.departures_this_step = departures_this_step;
    step_stats.parked_this_step = parked_this_step;
    if (config.total_spots > 0){
        step_stats.utilization_percent = ((double) g_garage.occupiedCount / config.total_spots) * 100.0;
    }else {
        step_stats.utilization_percent = 0;
    }

    stats_rec_step(&g_stats, &step_stats);
}
