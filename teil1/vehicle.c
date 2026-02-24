/*
 * File: vehicle.c
 * Beschreibung: Implementiert fahrzeugbezogene Funktionen
 */

#include "vehicle.h"
#include <stdio.h>

vehicle vehicle_create(int *p_next_id, int max_duration, int current_time)
{
    vehicle new_vehicle;
    new_vehicle.id = 0;
    new_vehicle.entry_time = 0;
    new_vehicle.time_remaining = 0;

    return new_vehicle;
}