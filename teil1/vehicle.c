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
    FUNCTION vehicle_create(p_next_id, max_duration, current_time)

        IF p_next_id = NULL THEN
            RETURN leeres_vehicle
        END IF

        IF max_duration <= 0 THEN
            RETURN leeres_vehicle
        END IF

        id ← *p_next_id
        *p_next_id ← *p_next_id + 1

        r ← Zufallszahl zwischen 0 und max_duration - 1
        remaining ← r + 1

        entry_time ← current_time

        RETURN vehicle(id, remaining, entry_time)

    END FUNCTION
    */


    new_vehicle.id = 0;                //Platzhalter
    new_vehicle.entry_time = 0;        //Platzhalter
    new_vehicle.time_remaining = 0;    //Platzhalter

    return new_vehicle;
}


    void vehicle_print(const vehicle *p_vehicle)
{
    /*
    FUNCTION vehicle_print(p_vehicle)

        IF p_vehicle = NULL THEN
            RETURN
        END IF

        OUTPUT p_vehicle.id
        OUTPUT p_vehicle.remaining
        OUTPUT p_vehicle.entry_time

    END FUNCTION
    */
}
