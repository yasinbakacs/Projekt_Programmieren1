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
        return false
    }

    garage->capacity = capacity;
    garage->occupiedCount = 0;

    for (int  = 0; i < capacity; i++){
        garage->spots[i].occupied = false;
        garage->spots[i].vehicle = NULL;
    }

    return true;
    // Pseudocode:
    // 1) IF garage == NULL || capacity > 0 THEN
    //       OUTPUT "Fehler: Ungültige Parameter für initGarage"
    //       RETURN false (Fehler)
    //    END IF
    // 2) garage->capacity = capacity; (Eingegebene Größe zuweisen)
    // 3) garage->occupiedCount = 0; (Start Belegung = 0)
    // 4) Alle Stellplatze:
    //    occupied <- false; (Alle Plätze frei)
    //    vehicle <- NULL; (Keine Fahrzeuge auf den Plätzen)
    // 5) Rückgabe: 
    //    true bei Erfolg, false bei Fehler (z.B. ungültige Kapazität oder Speicherfehler)
    return false; // Platzhalter Rückgabewert
}

int findFreeSpot(const ParkingGarage *garage) {
    if (garage == NULL){
        printf("Parkhaus ist NULL.\n");
        return -1;
    }  

    for (int i = 0; i < garage->capacity; i++){
        if (garage->spots[i].occupied = false){
            return i;
        }
    }
    return -1; // Wenn kein freier Parkplatz gefunden wird
    // Pseudocode:
    // 1) IF garage == NULL THEN
    //       OUTPUT "Fehler: Garage ist NULL"
    //       RETURN -1 (Fehler)
    //    END IF
    // 2) FOR i <- 0 TO capacity - 1 DO
    //      - Wenn garage->spots[i].occupied == false:
    //          -> Rückgabe von i (Index des freien Platzes)
    //      - Wenn kein Platz frei
    //          -> Rückgabe -1
    //    END FOR
 
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
    // Pseudocode:
    // 1) IF garage == NULL THEN
    //       OUTPUT "Fehler: Garage ist NULL"
    //       RETURN false (Fehler)
    //    END IF
    // 2) free index <- findFreeSpot(garage)
    // 3) IF free index == -1 THEN
    //      RETURN false
    //    END IF
    // 4) Platz belegen:
    //     - garage->spots[freierPlatz].occupied = true; (Platz belegen)
    //     - garage->spots[freierPlatz].vehicle = &v; (Fahrzeug zuweisen)
    //     - garage->occupiedCount++; (Belegungszähler erhöhen)
    //     -> Rückgabe true (Fahrzeug erfolgreich eingeparkt)
    return false; // Platzhalter Rückgabewert
}

void processDepartures(ParkingGarage *garage, int *departuresThisStep) {
    // Pseudocode:
    // 1) IF garage == NULL || departuresThisStep == NULL THEN
    //       OUTPUT "Fehler: Ungültige Parameter für processDepartures"
    //       RETURN
    //    END IF
    // 2) departuresThisStep auf 0 setzen (Anzahl der Abfahrten dieses Schritts zurücksetzen)
    // 3) FOR i = 0 TO capacity - 1 DO
    //      - IF garage->spots[i].occupied == true THEN:
    //          - garage->spots[i].vehicle->time_remaining -- ; (Verbleibende Zeit des Fahrzeugs verringern)
    //          - IF garage->spots[i].vehicle->time_remaining <= 0 THEN:
    //              -> Fahrzeug verlässt den Platz
    //              -> garage->spots[i].occupied = false; (Platz freigeben)
    //              -> garage->spots[i].vehicle = NULL; (Fahrzeug entfernen)
    //              -> garage->occupiedCount--; (Belegungszähler verringern)
    //              -> departuresThisStep++; (Abfahrten dieses Schritts erhöhen)
    //          END IF
    //      END IF
    }

