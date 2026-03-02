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
    return -1; // Platzhalter Rückgabewert
}

bool parkVehicle(ParkingGarage *garage, vehicle v) {
    // Pseudocode:
    // 1) IF garage == NULL THEN
    //       OUTPUT "Fehler: Garage ist NULL"
    //       RETURN false (Fehler)
    //    END IF
    // 2) freien Platz suchen (mit findFreeSpot - Funktion)
    // 3 Wenn kein freier Platz gefunden:
    //      -> Rückgabe false (kein Platz frei)
    // 4) Wenn freien Platz gefunden:
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

