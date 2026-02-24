/*
 * ================================================================
 * File:        parking.h
 * Description: Header-Datei für Parkhaus Funktionen
 * ================================================================
 */
#ifndef PARKING_H
#define PARKING_H

#include <stdio.h>
#include <stdbool.h>
#include "vehicle.h"

// Struktur eines einzelnen Stellplatzes
typedef struct {
    bool occupied;   //wenn true, dann ist der Parkplatz besetzt
    vehicle *vehicle; //zeigt auf Fahrzeug, das auf diesem Parkplatz steht (definiert in vehicle.h)
} ParkingSpot;

//Struktur des Parkhauses
typedef struct {
    int capacity; //Anzahl der Parkplätze
    ParkingSpot *spots; //Array von Parkplätzen
    int occupiedCount; //Anzahl der besetzten Parkplätze
} ParkingGarage;

//Jetzt folgen die Funktionsprototypen


/**
 * @brief Initialisiert das Parkhaus mit einer festen Anzahl an Stellplätzen.
 *
 * Es wird ein Array von Stellplätzen erstellt und alle Plätze
 * werden als frei markiert. Der Belegungszähler wird auf 0 gesetzt.
 *
 * @param[out] garage Zeiger auf das Parkhaus, das initialisiert werden soll
 * @param[in] capacity Anzahl der Stellplätze (muss > 0 sein)
 *
 * @return true bei erfolgreicher Initialisierung
 * @return false bei Speicherfehler oder ungültiger Kapazität
 */
bool initGarage(ParkingGarage *garage, int capacity);



/**
 * @brief Sucht einen freien Stellplatz im Parkhaus.
 *
 * Die Funktion durchläuft alle Stellplätze und gibt den
 * Index des ersten freien Platzes zurück.
 *
 * @param[in] garage Zeiger auf das Parkhaus (wird nicht verändert)
 *
 * @return Index des freien Platzes (0 bis capacity-1)
 * @return -1 wenn kein freier Platz vorhanden ist
 */
int findFreeSpot(const ParkingGarage *garage);


/**
 * @brief Parkt ein Fahrzeug in einen freien Stellplatz ein.
 *
 * Falls ein freier Stellplatz existiert, wird das Fahrzeug
 * dort gespeichert und der Belegungszähler erhöht.
 *
 * @param[in,out] garage Zeiger auf das Parkhaus
 * @param[in] v Das Fahrzeug, das eingeparkt werden soll
 *
 * @return true wenn das Fahrzeug erfolgreich eingeparkt wurde
 * @return false wenn kein freier Stellplatz vorhanden ist
 */
bool parkVehicle(ParkingGarage *garage, vehicle v);


/**
 * @brief Verarbeitet alle Abfahrten im aktuellen Zeitschritt.
 *
 * Die verbleibende Parkdauer aller parkenden Fahrzeuge wird
 * reduziert. Fahrzeuge mit Parkdauer 0 verlassen das Parkhaus.
 *
 * @param[in,out] garage Zeiger auf das Parkhaus
 * @param[out] departuresThisStep Anzahl der Fahrzeuge,
 *                                die in diesem Schritt ausgefahren sind
 */
void processDepartures(ParkingGarage *garage, int *departuresThisStep);

#endif // PARKING_H