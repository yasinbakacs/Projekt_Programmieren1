/*
 * File: statistics.c
 * Description: Statistikfunktionen für die Statistik-Funktionen
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

#include "statistics.h"


bool stats_init(Stats *p_stats, const char *filename) 
{
    if (p_stats == NULL || filename == NULL)
    {
        return false;
    }

    p_stats->total_steps = 0;
    p_stats->total_departures = 0;
    p_stats->total_parked = 0;

    p_stats->sum_occupied = 0;
    p_stats->sum_queue = 0;

    p_stats->p_file = fopen(filename, "w");
    if (p_stats->p_file == NULL)
    {
        return false;
    }

    return true;
}


void stats_rec_step(Stats *p_stats, const StepStats *p_step)
{
    if (p_stats == NULL || p_step == NULL)
    {
        return;
    }

    p_stats->total_steps = p_stats->total_steps + 1;
    p_stats->total_departures = p_stats->total_departures + p_step->departures_this_step;
    p_stats->total_parked = p_stats->total_parked + p_step->parked_this_step;
    p_stats->sum_occupied = p_stats->sum_occupied + p_step->occupied_spots;
    p_stats->sum_queue = p_stats->sum_queue + p_step->queue_length;

    printf("Step: %d\n", p_step->step);
    printf("Belegte Plaetze: %d\n", p_step->occupied_spots);
    printf("Warteschlange: %d\n", p_step->queue_length);
    printf("Abfahrten: %d\n", p_step->departures_this_step);
    printf("Eingeparkt: %d\n", p_step->parked_this_step);
    printf("-----------------------------\n");

    if (p_stats->p_file != NULL)
    {
        fprintf(p_stats->p_file, "Step: %d\n", p_step->step);
        fprintf(p_stats->p_file, "Belegte Plaetze: %d\n", p_step->occupied_spots);
        fprintf(p_stats->p_file, "Warteschlange: %d\n", p_step->queue_length);
        fprintf(p_stats->p_file, "Abfahrten: %d\n", p_step->departures_this_step);
        fprintf(p_stats->p_file, "Eingeparkt: %d\n", p_step->parked_this_step);
        fprintf(p_stats->p_file, "-----------------------------\n");
    }
}

void stats_print(Stats *p_stats) 
{
    double avg_occupied = 0.0;
    double avg_queue = 0.0;

    if (p_stats == NULL)
    {
        return;
    }

    if (p_stats->total_steps > 0)
    {
        avg_occupied = (double)p_stats->sum_occupied / p_stats->total_steps;
        avg_queue = (double)p_stats->sum_queue / p_stats->total_steps;
    }

    printf("\n=== Gesamtstatistik ===\n");
    printf("Zeitschritte: %d\n", p_stats->total_steps);
    printf("Gesamte Abfahrten: %d\n", p_stats->total_departures);
    printf("Gesamt eingeparkt: %d\n", p_stats->total_parked);
    printf("Durchschnitt belegte Plaetze: %.2f\n", avg_occupied);
    printf("Durchschnitt Warteschlange: %.2f\n", avg_queue);

    if (p_stats->p_file != NULL)
    {
        fprintf(p_stats->p_file, "\n=== Gesamtstatistik ===\n");
        fprintf(p_stats->p_file, "Zeitschritte: %d\n", p_stats->total_steps);
        fprintf(p_stats->p_file, "Gesamte Abfahrten: %d\n", p_stats->total_departures);
        fprintf(p_stats->p_file, "Gesamt eingeparkt: %d\n", p_stats->total_parked);
        fprintf(p_stats->p_file, "Durchschnitt belegte Plaetze: %.2f\n", avg_occupied);
        fprintf(p_stats->p_file, "Durchschnitt Warteschlange: %.2f\n", avg_queue);
    }
}

void stats_close(Stats *p_stats) 
{
    if (p_stats == NULL)
    {
        return;
    }

    if (p_stats->p_file != NULL)
    {
        fclose(p_stats->p_file);
        p_stats->p_file = NULL;
    }
}