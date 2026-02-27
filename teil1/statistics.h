/*
 * ================================================================
 * File:        statistics.h
 * Description: Header-Datei für Statistik-Funktionen
 * ================================================================
 */

#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdio.h>
#include <stdbool.h>


//Statistikwerte pro Zeitschritt
typedef struct {
    int step; //aktueller Zeitschritt
    int occupied_spots; //Anzahl der besetzten Parkplätze
    int queue_length; //Länge Warteschlange
    int departures_this_step; //Anzahl der Abfahrten in diesem Zeitschritt
    int parked_this_step; //Anzahl der Fahrzeuge, die in diesem Zeitschritt einparken
} StepStats;

//Gesamtstatistik über die gesamte Simulation
typedef struct {
    void *p_file; //Datei-Handle für die Statistik-Ausgabedatei

    int total_steps; //Gesamtzahl der Zeitschritte
    int total_departures; //Gesamtzahl der Abfahrten
    int total_parked; //Gesamtzahl geparkte Fahrzeuge
    long sum_occupied; //Durchschnitt belegter Plätze
    long sum_queue; //Durchschnitt Warteschlangenlänge
}Stats;



//Funktionsprototypen

/**
 * @brief Initialisiert die Statistik-Struktur und öffnet die Ausgabedatei.
 *
 * @param[out] p_stats Zeiger auf die zu initialisierende Statistik-Struktur
 * @param[in] filename Name der Ausgabedatei (muss gültig sein)
 *
 * @return true bei erfolgreicher Initialisierung und Dateieröffnung
 * @return false bei Fehler (z.B. ungültiger Dateiname oder Speicherfehler)
 */

bool stats_init(Stats *p_stats, const char *filename);

/**
 * @brief Schreibt die gesammelten Statistikdaten in die Ausgabedatei und schließt sie.
 *
 * @param[in] p_stats Zeiger auf die zu finalisierende Statistik-Struktur
 * @param[in] p_step Zeiger auf StepStats
 *
 * @return true bei erfolgreichem Schreiben und Schließen der Datei
 * @return false bei Fehler (z.B. ungültiger Zeiger oder Dateifehler)
 */

void stats_rec_step(Stats *p_stats, const StepStats *p_step);


/**
 * @brief Schreibt die Endstatistik in die Ausgabedatei.
 *
 * @param[in] p_stats Zeiger auf die Statistik-Struktur
 * @param[in] total_steps Gesamtzahl der Zeitschritte der Simulation
 *
 * @return true bei erfolgreichem Schreiben der Endstatistik
 * @return false bei Fehler 
 */
void stats_print(Stats *p_stats, int total_steps);

/**
 * @brief Schließt die Statistik-Ausgabedatei
 *
 * @param[in] p_stats Zeiger auf die zu finalisierende Statistik-Struktur
 *
 * @return true bei erfolgreichem Schließen der Datei
 * @return false bei Fehler 
 */

void stats_close(Stats *p_stats);

#endif

