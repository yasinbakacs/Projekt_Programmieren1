/*
 * File: test_statistics.c
 * Beschreibung: Testet die Funktionen aus statistics.c
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "statistics.h"

static void test_stats_init_valid(void)
{
    Stats stats;
    bool ok = false;

    ok = stats_init(&stats, "test_stats_init_valid.txt");

    assert(ok == true);
    assert(stats.total_steps == 0);
    assert(stats.total_departures == 0);
    assert(stats.total_parked == 0);
    assert(stats.sum_occupied == 0);
    assert(stats.sum_queue == 0);
    assert(stats.p_file != NULL);

    stats_close(&stats);
    remove("test_stats_init_valid.txt");
}

static void test_stats_init_invalid(void)
{
    Stats stats;
    bool ok = false;

    ok = stats_init(NULL, "test_stats_init_invalid.txt");
    assert(ok == false);

    ok = stats_init(&stats, NULL);
    assert(ok == false);
}

static void test_stats_rec_step_updates_values(void)
{
    Stats stats;
    StepStats step;
    bool ok = false;

    ok = stats_init(&stats, "test_stats_rec_step_updates_values.txt");
    assert(ok == true);

    step.step = 0;
    step.occupied_spots = 3;
    step.queue_length = 2;
    step.departures_this_step = 1;
    step.parked_this_step = 4;
    step.utilization_percent = 60;

    stats_rec_step(&stats, &step);

    assert(stats.total_steps == 1);
    assert(stats.total_departures == 1);
    assert(stats.total_parked == 4);
    assert(stats.sum_occupied == 3);
    assert(stats.sum_queue == 2);

    stats_close(&stats);
    remove("test_stats_rec_step_updates_values.txt");
}

