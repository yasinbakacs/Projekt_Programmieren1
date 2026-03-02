/*
 * File: Simulation.h
 * Description: Header-Datei für die Simulation eines Parkhauses.
 */
#ifndef SIMULATION_H
#define SIMULATION_H

// Einbindung der Modul-Header
#include "parking.h"
#include "vehicle.h"
#include "queue.h"

/**
 * @brief Konfigurationsdaten für die Simulation.
 */
typedef struct {
    int total_spots;              // Anzahl Stellplätze
    int max_parking_time;         // Maximale Parkdauer
    int simulation_steps;         // Anzahl Zeitschritte
    int arrival_probability;      // Ankunftswahrscheinlichkeit in %
    int random_seed;              // Seed für Zufall
} SimulationConfig;




/**
 * @brief Initialisiert die Simulation.
 *
 * Setzt Zufalls-Seed und bereitet Strukturen vor.
 *
 * @param config Konfigurationsdaten
 */
void simulation_init(SimulationConfig config);


/**
 * @brief Führt die Simulation vollständig aus.
 *
 * Durchläuft alle Zeitschritte.
 *
 * @param config Konfigurationsdaten
 */
void simulation_run(SimulationConfig config);


/**
 * @brief Führt einen einzelnen Zeitschritt aus.
 *
 * @param config Konfigurationsdaten
 * @param step Aktueller Zeitschritt
 */
void simulation_step(SimulationConfig config, int step);

#endif