/*
 * File: statistics.c
 * Description: Pseudocode für die Statistik-Funktionen
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

#include "statistics.h"


bool stats_init(Stats *p_stats, const char *filename) {
    // Pseudocode:
    // 1) IF p_stats == NULL OR filename == NULL THEN
    //        -> Fehlermeldung
    //    END IF
    // 2) Werte auf 0 setzen:
    //    p_stats->total_steps = 0;
    //    p_stats->total_departures = 0;
    //    p_stats->total_parked = 0;
    //    p_stats->sum_occupied = 0;
    //    p_stats->sum_queue = 0;
    // 3) Datei öffnen:
    //    p_stats->p_file = fopen(filename, "w");
    //    IF p_stats->p_file == NULL THEN
    //        -> Fehlermeldung
    //    END IF
    // 4) Header für Datei schreiben (evtl. mit extra Funktion)
    return false; // Platzhalter Rückgabewert
}


void stats_rec_step(Stats *p_stats, const StepStats *p_step){
    // Pseudocode:
    // 1) IF p_stats == NULL OR p_step == NULL THEN
    //        -> Fehlermeldung
    //    END IF
    // 2) Daten aus dem jeweiligen Step in allgemeine Stats übertragen:
    //    p_stats->total_steps++;
    //    p_stats->total_departures += p_step->departures_this_step;
    //    p_stats->total_parked += p_step->parked_this_step;
    //    p_stats->sum_occupied += p_step->occupied_spots;
    //    p_stats->sum_queue += p_step->queue_length;
    // 3) Ausgabe auf Konsole (evtl. mit extra Funktion)
    // 4) Daten in Datei schreiben (evtl. mit extra Funktion)
    //
}

void stats_print(Stats *p_stats, int total_steps) {
    // Pseudocode:
    // 
}
