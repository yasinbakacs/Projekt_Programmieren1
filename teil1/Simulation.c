/*
 * File: Simulation.c
 * Description: C-Datei für die Simulation eines Parkhauses.
 */

/* Einbinden der Standardbibliotheken und Simulation.h */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simulation.h"

// Einbinden der Variablen für Parkhaus, Warteschlange und Statistik
static ParkingGarage g_garage;
static Queue g_queue;
static SimulationStats g_stats;
static int g_next_id = 1;

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
    // QueueInit(&g_queue)
    //

    // Statistikstruktur vorbereiten (noch nicht umgesetzt) 
}

/**
 * @brief Startet die Simulation.
 */
void simulation_run(SimulationConfig config)
{
    simulation_init(config); // Simulation initialisieren 

    // Für jeden Zeitschritt 
    //for (int step = 0; step < config.simulation_steps; step++)
    {
        simulation_step(config, step);
    }

    // Am Ende: Gesamtauswertung ausgeben (noch nicht umgesetzt) 
}

/**
 * @brief Führt einen einzelnen Zeitschritt aus.
 */
void simulation_step(SimulationConfig config, int step)
{
    // PSEUDOCODE:
    // g_stats.current_step <- step
    //
    // Prüfen ob neues Fahrzeug ankommt:
    // r <- RANDOM_NUMBER(0..99)
    // IF r < config.arrival_probability THEN
    //     Fahrzeug erzeugen (abhängig von vehicle.h)
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
    //             g_stats.cars_parked <- g_stats.cars_parked + 1
    //         END IF
    //     ELSE
    //         QueueEnqueue(&g_queue, v)   // Name abhängig von queue.h
    //     END IF
    // END IF
    //
    // Abfahrten verarbeiten:
    // departures_this_step <- 0
    // processDepartures(&g_garage, &departures_this_step)
    //
    // Warteschlange nachrücken lassen:
    // WHILE findFreeSpot(&g_garage) != -1 AND QueueIsEmpty(&g_queue) == false DO
    //     next <- QueueDequeue(&g_queue)
    //     ok <- parkVehicle(&g_garage, next)
    // END WHILE

    //Statistiken aktualisieren + ausgeben (noch nicht umgesetzt)
}

/**
 * @brief Aktualisiert die Statistikwerte.
 */
void simulation_update_stats(SimulationStats *p_stats, ParkingGarage *p_garage, Queue *p_queue)
{
    // Statistiken aktualisieren
}

/**
 * @brief Gibt Statistiken aus.
 */
void simulation_print_stats(SimulationStats stats)
{
    // Statistiken ausgeben
} 