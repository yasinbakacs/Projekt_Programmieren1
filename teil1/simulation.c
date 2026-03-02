/*
 * File: Simulation.c
 * Description: C-Datei für die Simulation eines Parkhauses.
 */

/* Einbinden der Standardbibliotheken und Simulation.h */
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
void simulation_init(SimulationConfig config)
{
    srand(config.random_seed); //Zufalls-Seed setzen

    //Parkhaus initialisieren
    // PSEUDOCODE:
    // ok <- initGarage(&g_garage, config.total_spots)
    // IF ok == false THEN
    //     OUTPUT "Fehler: Parkhaus konnte nicht initialisiert werden"
    //     STOP PROGRAM
    // END IF
    //

    // Warteschlange initialisieren
    // PSEUDOCODE:
    // ok <- queue_init(&g_queue)
    //IF ok == false THEN
    //     OUTPUT "Fehler: Warteschlange konnte nicht initialisiert werden"
    //     STOP PROGRAM
    // END IF

    // Statistikstruktur initialisieren
    // PSEUDOCODE:
    // ok <- stats_init(&g_stats, "simulation_stats.txt")
    // IF ok == false THEN
    //     OUTPUT "Fehler: Statistik konnte nicht initialisiert werden"
    //     STOP PROGRAM
    // END IF
    // g_stats.total_steps <- config.simulation_steps
}

/**
 * @brief Startet die Simulation.
 */
void simulation_run(SimulationConfig config)
{
    simulation_init(config); // Simulation initialisieren

    // Für jeden Zeitschritt
    // FOR step ← 0 TO config.simulation_steps - 1 DO
    //     simulation_step(config, step)
    // END FOR

    // Gesamtauswertung ausgeben:
    // stats_print(&g_stats)
    // stats_close(&g_stats)
}

/**
 * @brief Führt einen einzelnen Zeitschritt aus.
 */
void simulation_step(SimulationConfig config, int step)
{
    // PSEUDOCODE:
    // parked_this_step <- 0
    //
    // Prüfen ob neues Fahrzeug ankommt:
    // r <- RANDOM_NUMBER(0..99)
    // IF r < config.arrival_probability THEN
    //     v ← vehicle_create(&g_next_id, config.max_parking_time, step)
    //     v.id <- g_next_id
    //     g_next_id <- g_next_id + 1
    //     v.time_remaining <- RANDOM_NUMBER(1..config.max_parking_time)
    //     v.entry_time <- step
    //
    //     Einparken oder warten?
    //     free_index <- findFreeSpot(&g_garage)
    //     IF free_index != -1 THEN
    //         ok <- parkVehicle(&g_garage, v)
    //         IF ok == true THEN
    //             parked_this_step <- parked_this_step + 1
    //         END IF
    //     ELSE
    //         queue_enqueue(&g_queue, v)
    //     END IF
    // END IF
    //
    // Abfahrten verarbeiten:
    // departures_this_step <- 0
    // processDepartures(&g_garage, &departures_this_step)
    //
    // Warteschlange nachrücken lassen:
    // WHILE findFreeSpot(&g_garage) != -1 AND queue_is_empty(&g_queue) == false DO
    //     next <- queue_dequeue(&g_queue)
    //     ok <- parkVehicle(&g_garage, next)
    // END WHILE
    //
    //Statistiken aktualisieren + ausgeben:
    StepStats step_stats;
    // PSEUDOCODE:
    // step_stats.step <- step
    // step_stats.occupied_spots <- g_garage.occupiedCount
    // step_stats.queue_length <- queue_get_size(&g_queue)
    // step_stats.departures_this_step <- departures_this_step
    // step_stats.parked_this_step <- parked_this_step
    // stats_rec_step(&g_stats)
}
