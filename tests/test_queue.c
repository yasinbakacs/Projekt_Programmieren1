#include <assert.h>
#include <stdio.h>
#include "queue.h"

vehicle create_test_vehicle(int id, int entry_time, int time_remaining)
{
    vehicle v;

    v.id = id;
    v.entry_time = entry_time;
    v.time_remaining = time_remaining;

    return v;
}

void test_queue_init(void)
{

}

void test_queue_enqueue(void)
{

}

void test_queue_dequeue(void)
{

}

void test_queue_get_size(void)
{

}

void test_queue_is_empty(void)
{

}

void test_queue_free(void)
{

}


int main(void)
{
    test_queue_init();
    test_queue_enqueue();
    test_queue_dequeue();
    test_queue_get_size();
    test_queue_is_empty();
    test_queue_free();

    printf("Alle Queue Tests bestanden!\n");

    return 0;
}