#ifndef VEHICLE_H
#define VEHICLE_H

/*
* File: vehicle.h
* Description: Defines the vehicle structure and related interface functions
*/

#include <stdio.h>

/*
* Structure: vehicle
* Description: Represents a vehicle in the parking simulation
*/

typedef struct vehicle
{
    int id;
    int entry_time;
    int time_remaining;
} vehicle;


#endif