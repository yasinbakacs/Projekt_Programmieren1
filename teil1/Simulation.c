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
