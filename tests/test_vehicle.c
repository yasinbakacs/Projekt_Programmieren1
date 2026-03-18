#include <assert.h>
#include <stdio.h>
#include "vehicle.h"

void test_vehicle_create_basic()
{
    int next_id = 1;
    int max_duration = 10;
    int current_time = 5;

    vehicle v = vehicle_create(&next_id, max_duration, current_time);

    assert(v.id == 1);
    assert(v.entry_time == current_time);
    assert(v.time_remaining >= 1 && v.time_remaining <= max_duration);
    assert(next_id == 2);
}

void test_vehicle_create_id()
{

}


int main()
{
    test_vehicle_create_basic();
    test_vehicle_create_id();

    printf("Alle Vehicle Tests bestanden!\n");

    return 0;
}
