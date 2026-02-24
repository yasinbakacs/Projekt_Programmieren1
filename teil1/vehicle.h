#ifndef VEHICLE_H
#define VEHICLE_H

/*
* File: vehicle.h
* Description: Definiert die Fahrzeugstruktur und zugehörige Schnittstellenfunktionen
*/

#include <stdio.h>

/*
* Structure: vehicle
* Description: Repräsentiert ein Fahrzeug in der Parkhaus-Simulation
*/

typedef struct vehicle
{
    int id;
    int entry_time;
    int time_remaining;
} vehicle;


/**
 * @brief Erstellt ein neues Fahrzeug mit zufälliger Parkdauer
 *
 * @param[in,out] p_next_id    Pointer auf die nächste verfügbare ID
 * @param[in]     max_duration Maximale Parkdauer
 * @param[in]     current_time Aktueller Simulationszeitpunkt
 * @return                    Initialisiertes Fahrzeug
 */
vehicle vehicle_create(int *p_next_id, int max_duration, int current_time);


/**
 * @brief Gibt die Informationen eines Fahrzeugs aus
 *
 * @param[in] p_vehicle Pointer auf das Fahrzeug
 */
void vehicle_print(const vehicle *p_vehicle);

#endif