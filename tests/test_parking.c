/*
*File: test_parking.c
*Beschreibung: Unit-Tests fuer parking.c
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "parking.h"
#include "vehicle.h"

void freeGarage(ParkingGarage *garage);

static vehicle createTestVehicle(int id, int entry_time, int time_remaining)
{
    vehicle v;

    v.id = id;
    v.entry_time = entry_time;
    v.time_remaining = time_remaining;

    return v;
}

static void test_initGarage_valid(void)
{
    ParkingGarage garage;
    bool result;

    garage.capacity = 0;
    garage.spots = NULL;
    garage.occupiedCount = 0;

    result = initGarage(&garage, 3);

    assert(result == true);
    assert(garage.capacity == 3);
    assert(garage.spots != NULL);
    assert(garage.occupiedCount == 0);

    for (int i = 0; i < garage.capacity; i++)
    {
        assert(garage.spots[i].occupied == false);
        assert(garage.spots[i].vehicle == NULL);
    }

    freeGarage(&garage);
}

static void test_initGarage_invalid(void)
{
    ParkingGarage garage;
    bool result;

    garage.capacity = 0;
    garage.spots = NULL;
    garage.occupiedCount = 0;

    result = initGarage(&garage, 0);

    assert(result == false);
    assert(garage.spots == NULL);
    assert(garage.capacity == 0);
    assert(garage.occupiedCount == 0);
}

static void test_findFreeSpot_empty(void)
{
    ParkingGarage garage;
    int index;

    assert(initGarage(&garage, 2) == true);

    index = findFreeSpot(&garage);

    assert(index == 0);

    freeGarage(&garage);
}
