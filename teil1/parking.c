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
    // 1) Prüfen: garage != NULL und capacity > 0
    // 2) garage->capacity = capacity; (Eingegebene Größe zuweisen)
    // 3) garage->occupiedCount = 0; (Start Belegung = 0)
    // 4) Alle Stellplatze:
    //    occupied = false; (Alle Plätze frei)
    //    vehicle = NULL; (Keine Fahrzeuge auf den Plätzen)
    // 5) Rückgabe: 
    //    true bei Erfolg, false bei Fehler (z.B. ungültige Kapazität oder Speicherfehler)
    return false; // Platzhalter Rückgabewert
}

