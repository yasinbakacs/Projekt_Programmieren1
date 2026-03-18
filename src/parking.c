/*
 * ================================================================
 * File:        parking.c
 * Description: Pseudo-Code für Parkhaus Funktionen
 * ================================================================
 */

#include "parking.h"

#include <stdlib.h>
#include <stdio.h>

bool initGarage(ParkingGarage *garage, int capacity) {
    if (garage == NULL || capacity <= 0){
        printf("Parkhaus konnte nicht initialisiert werden.\n");
        return false;
    }

    garage->spots = malloc(sizeof(ParkingSpot) * capacity);
    if (garage->spots == NULL){
        printf("Speicher allokation fehlgeschlagen.\n");
        return false;
    }

    garage->capacity = capacity;
    garage->occupiedCount = 0;

    for (int i = 0; i < capacity; i++){
        garage->spots[i].occupied = false;
        garage->spots[i].vehicle = NULL;
    }

    return true;
}

int findFreeSpot(const ParkingGarage *garage) {
    if (garage == NULL){
        printf("Parkhaus ist NULL.\n");
        return -1;
    }  

    for (int i = 0; i <= garage->capacity; i++){
        if (garage->spots[i].occupied == false){
            return i;
        }
    }
    return -1; // Wenn kein freier Parkplatz gefunden wird
}

bool parkVehicle(ParkingGarage *garage, vehicle v) {
    if (garage == NULL){
        printf("Parkhaus ist NULL.\n");
        return false;
    }
    int freierPlatz = findFreeSpot(garage);
    
    if (freierPlatz == -1){
        return false;
    }


    garage->spots[freierPlatz].occupied = true;

    garage->spots[freierPlatz].vehicle = malloc(sizeof(vehicle));
    if (garage->spots[freierPlatz].vehicle == NULL){
        printf("Speicher allokation fehlgeschlagen");
        return false;
    }
    *garage->spots[freierPlatz].vehicle = v;
    garage->occupiedCount++;

    return true;
}

void processDepartures(ParkingGarage *garage, int *departuresThisStep) {
    if (garage == NULL || departuresThisStep == NULL){
        printf("Ungültige Parameter processDep.\n");
        return;
    }

    *departuresThisStep = 0;

    for (int i = 0; i < garage->capacity; i++){
        if (garage->spots[i].occupied == true){
            garage->spots[i].vehicle->time_remaining--; // Falls Parkplatz belegt, wird Zeit um einen step runtergezählt 
            if (garage->spots[i].vehicle->time_remaining <= 0){
                garage->spots[i].occupied = false; // Falls Zeit 0 wird Auto aus PArkhaus gefahren
                free(garage->spots[i].vehicle);
                garage->spots[i].vehicle = NULL;

                garage->occupiedCount--;
                (*departuresThisStep)++;
            }
        }
    }
    }

    void freeGarage(ParkingGarage *garage){
        if (garage == NULL){
            printf("Parkhaus ist NULL.\n");
            return;
        }

        for (int i = 0; i < garage->capacity; i++){
            if (garage->spots[i].vehicle != NULL){
                free(garage->spots[i].vehicle);
                garage->spots[i].vehicle = NULL;
            }
            garage->spots[i].occupied = false;
        }
        free(garage->spots);
        garage->spots = NULL;
        garage->capacity = 0;
        garage->occupiedCount = 0;
    }