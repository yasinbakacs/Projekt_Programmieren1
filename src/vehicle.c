/*
 * File: vehicle.c
 * Beschreibung: Implementiert fahrzeugbezogene Funktionen
 */

#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h>

vehicle vehicle_create(int *p_next_id, int max_duration, int current_time)
{
    vehicle new_vehicle;

    new_vehicle.id = 0;
    new_vehicle.entry_time = 0;
    new_vehicle.time_remaining = 0;

    if (p_next_id == NULL)
    {
        return new_vehicle;
    }

    if (max_duration <= 0)
    {
        return new_vehicle;
    }

    new_vehicle.id = *p_next_id;
    *p_next_id = *p_next_id + 1;

    int r = rand() % max_duration;
    new_vehicle.time_remaining = r + 1;

    new_vehicle.entry_time = current_time;

    return new_vehicle;
}

void vehicle_print(const vehicle *p_vehicle)
{
    if (p_vehicle == NULL)
    {
        return;
    }

    printf(
        "Vehicle ID: %d | Remaining time: %d | Entry time: %d\n",
        p_vehicle->id,
        p_vehicle->time_remaining,
        p_vehicle->entry_time
    );
}