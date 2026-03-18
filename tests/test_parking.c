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

static void test_findFreeSpot_full(void)
{
    ParkingGarage garage;
    vehicle v1;
    vehicle v2;
    int index;

    assert(initGarage(&garage, 2) == true);

    v1 = createTestVehicle(1, 0, 3);
    v2 = createTestVehicle(2, 0, 4);

    assert(parkVehicle(&garage, v1) == true);
    assert(parkVehicle(&garage, v2) == true);

    index = findFreeSpot(&garage);
    printf("occupied[0] = %d\n", garage.spots[0].occupied);
printf("occupied[1] = %d\n", garage.spots[1].occupied);
printf("index = %d\n", index);
    assert(index == -1);

    freeGarage(&garage);
}

static void test_parkVehicle_success(void)
{
    ParkingGarage garage;
    vehicle v;
    bool result;

    assert(initGarage(&garage, 2) == true);

    v = createTestVehicle(10, 5, 7);
    result = parkVehicle(&garage, v);

    assert(result == true);
    assert(garage.occupiedCount == 1);
    assert(garage.spots[0].occupied == true);
    assert(garage.spots[0].vehicle != NULL);
    assert(garage.spots[0].vehicle->id == 10);
    assert(garage.spots[0].vehicle->entry_time == 5);
    assert(garage.spots[0].vehicle->time_remaining == 7);

    freeGarage(&garage);
}

static void test_parkVehicle_full(void)
{
    ParkingGarage garage;
    vehicle v1;
    vehicle v2;
    bool result;

    assert(initGarage(&garage, 1) == true);

    v1 = createTestVehicle(1, 0, 2);
    v2 = createTestVehicle(2, 1, 3);

    assert(parkVehicle(&garage, v1) == true);

    result = parkVehicle(&garage, v2);

    assert(result == false);
    assert(garage.occupiedCount == 1);

    freeGarage(&garage);
}

static void test_processDepartures_noDeparture(void)
{
    ParkingGarage garage;
    vehicle v;
    int departuresThisStep;

    assert(initGarage(&garage, 2) == true);

    v = createTestVehicle(1, 0, 3);
    assert(parkVehicle(&garage, v) == true);

    departuresThisStep = -1;
    processDepartures(&garage, &departuresThisStep);

    assert(departuresThisStep == 0);
    assert(garage.occupiedCount == 1);
    assert(garage.spots[0].occupied == true);
    assert(garage.spots[0].vehicle != NULL);
    assert(garage.spots[0].vehicle->time_remaining == 2);

    freeGarage(&garage);
}

static void test_processDepartures_withDeparture(void)
{
    ParkingGarage garage;
    vehicle v;
    int departuresThisStep;

    assert(initGarage(&garage, 2) == true);

    v = createTestVehicle(1, 0, 1);
    assert(parkVehicle(&garage, v) == true);

    departuresThisStep = -1;
    processDepartures(&garage, &departuresThisStep);

    assert(departuresThisStep == 1);
    assert(garage.occupiedCount == 0);
    assert(garage.spots[0].occupied == false);
    assert(garage.spots[0].vehicle == NULL);

    freeGarage(&garage);
}

void run_parking_tests(void)
{
    test_initGarage_valid();
    test_initGarage_invalid();

    test_findFreeSpot_empty();
    test_findFreeSpot_full();

    test_parkVehicle_success();
    test_parkVehicle_full();

    test_processDepartures_noDeparture();
    test_processDepartures_withDeparture();
}
