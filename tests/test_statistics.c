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

static void test_stats_rec_step_multiple_steps(void)
{
    Stats stats;
    StepStats step1;
    StepStats step2;
    bool ok = false;

    ok = stats_init(&stats, "test_stats_rec_step_multiple_steps.txt");
    assert(ok == true);

    step1.step = 0;
    step1.occupied_spots = 2;
    step1.queue_length = 1;
    step1.departures_this_step = 0;
    step1.parked_this_step = 2;
    step1.utilization_percent = 40;

    step2.step = 1;
    step2.occupied_spots = 4;
    step2.queue_length = 3;
    step2.departures_this_step = 1;
    step2.parked_this_step = 1;
    step2.utilization_percent = 80;

    stats_rec_step(&stats, &step1);
    stats_rec_step(&stats, &step2);

    assert(stats.total_steps == 2);
    assert(stats.total_departures == 1);
    assert(stats.total_parked == 3);
    assert(stats.sum_occupied == 6);
    assert(stats.sum_queue == 4);

    stats_close(&stats);
    remove("test_stats_rec_step_multiple_steps.txt");
}

static void test_stats_print_keeps_values_consistent(void)
{
    Stats stats;
    StepStats step;
    bool ok = false;

    ok = stats_init(&stats, "test_stats_print_keeps_values_consistent.txt");
    assert(ok == true);

    step.step = 0;
    step.occupied_spots = 6;
    step.queue_length = 2;
    step.departures_this_step = 1;
    step.parked_this_step = 3;
    step.utilization_percent = 75;

    stats_rec_step(&stats, &step);
    stats_print(&stats);

    assert(stats.total_steps == 1);
    assert(stats.total_departures == 1);
    assert(stats.total_parked == 3);
    assert(stats.sum_occupied == 6);
    assert(stats.sum_queue == 2);

    stats_close(&stats);
    remove("test_stats_print_keeps_values_consistent.txt");
}

static void test_stats_close_sets_file_to_null(void)
{
    Stats stats;
    bool ok = false;

    ok = stats_init(&stats, "test_stats_close_sets_file_to_null.txt");
    assert(ok == true);
    assert(stats.p_file != NULL);

    stats_close(&stats);

    assert(stats.p_file == NULL);

    remove("test_stats_close_sets_file_to_null.txt");
}

void run_statistics_tests(void)
{
    test_stats_init_valid();
    test_stats_init_invalid();
    test_stats_rec_step_updates_values();
    test_stats_rec_step_multiple_steps();
    test_stats_print_keeps_values_consistent();
    test_stats_close_sets_file_to_null();

    printf("Alle Statistics-Tests bestanden!\n");
}