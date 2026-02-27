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
 * @brief Statistiken der Simulation.
 */
typedef struct {
    int current_step;
    int cars_arrived;
    int cars_parked;
    int cars_departed;
    int cars_waiting;
    float occupancy_rate;
} SimulationStats;


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


/**
 * @brief Berechnet Statistiken für einen Zeitschritt.
 *
 * @param p_stats   Statistikstruktur
 * @param p_garage  Parkhaus
 * @param p_queue   Warteschlange
 */
void simulation_update_stats(SimulationStats *p_stats, ParkingGarage *p_garage, queue *p_queue);


/**
 * @brief Gibt Statistiken auf Konsole und Datei aus.
 *
 * @param stats Statistikdaten
 */
void simulation_print_stats(SimulationStats stats);

#endif