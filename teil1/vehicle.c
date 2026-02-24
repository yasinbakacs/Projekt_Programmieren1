/*
 * File: vehicle.c
 * Beschreibung: Implementiert fahrzeugbezogene Funktionen
 */

#include "vehicle.h"
#include <stdio.h>

vehicle vehicle_create(int *p_next_id, int max_duration, int current_time)
{
    vehicle new_vehicle;

    /*
     * PSEUDOCODE:
     *
     * Falls p_next_id NULL ist:
     *     spätere Fehlerbehandlung
     *
     * Falls max_duration <= 0:
     *     spätere Fehlerbehandlung
     * 
     * new_vehicle.id = *p_next_id
     * *p_next_id um 1 erhöhen
     *
     * new_vehicle.entry_time = current_time
     * 
     * new_vehicle.time_remaining = Zufallszahl im Bereich [1 ... max_duration]
     *
     * Fahrzeug zurückgeben
     */

    new_vehicle.id = 0;
    new_vehicle.entry_time = 0;
    new_vehicle.time_remaining = 0;

    return new_vehicle;
}