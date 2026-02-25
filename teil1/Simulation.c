/*
 * File: Simulation.c
 * Description: C-Datei für die Simulation eines Parkhauses.
 */
// Einbinden der 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "simulation.h"

/**
 * @brief Initialisiert die Simulation.
 */
void simulation_init(SimulationConfig config)
{
    // PSEUDOCODE:
    srand(config.random_seed); // Zufalls-Seed setzen
    // 2. Parkhaus initialisierenx
    // 3. Warteschlange initialisieren
    // 4. Statistikstruktur vorbereiten

    
}


/**
 * @brief Startet die Simulation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "simulation.h"

/**
 * @brief Initialisiert die Simulation.
 */
void simulation_init(SimulationConfig config)
{
    // PSEUDOCODE:
    // 1. Zufalls-Seed setzen
    // 2. Parkhaus initialisieren
    // 3. Warteschlange initialisieren
    // 4. Statistikstruktur vorbereiten

    srand(config.random_seed);
}


/**
 * @brief Startet die Simulation.
 */
void simulation_run(SimulationConfig config)
{
    // PSEUDOCODE:
    // 1. simulation_init(config)
    // 2. Für jeden Zeitschritt:
    //      simulation_step(config, step)
    // 3. Am Ende: Gesamtauswertung ausgeben

    simulation_init(config);

    for(int step = 0; step < config.simulation_steps; step++)
    {
        simulation_step(config, step);
    }
}


/**
 * @brief Führt einen einzelnen Zeitschritt aus.
 */
void simulation_step(SimulationConfig config, int step)
{
    // PSEUDOCODE:

    // 1. Prüfen ob neues Fahrzeug ankommt
    //      -> Zufallszahl 0–99
    //      -> Wenn < arrival_probability:
    //              Fahrzeug erzeugen
    //              Wenn freier Stellplatz:
    //                     einparken
    //              Sonst:
    //                     in Warteschlange stellen

    // 2. Parkdauer aller Fahrzeuge reduzieren

    // 3. Fahrzeuge entfernen deren Parkdauer == 0

    // 4. Fahrzeuge aus Warteschlange nachrücken lassen

    // 5. Statistiken aktualisieren

}


/**
 * @brief Aktualisiert die Statistikwerte.
 */
void simulation_update_stats(SimulationStats* stats, ParkingLot* parking, Queue* queue)
{
    // PSEUDOCODE:
    // stats->cars_waiting = queue_size(queue);
    // stats->occupancy_rate = belegte_plätze / gesamtplätze * 100;
}


/**
 * @brief Gibt Statistiken aus.
 */
void simulation_print_stats(SimulationStats stats)
{
    printf("Zeitschritt: %d\n", stats.current_step);
    printf("Angekommen: %d\n", stats.cars_arrived);
    printf("Geparkt: %d\n", stats.cars_parked);
    printf("Verlassen: %d\n", stats.cars_departed);
    printf("Wartend: %d\n", stats.cars_waiting);
    printf("Auslastung: %.2f%%\n", stats.occupancy_rate);

    // PSEUDOCODE:
    // Zusätzlich in Datei schreiben
}