#include <stdio.h>

void run_queue_tests(void);
void run_vehicle_tests(void);
void run_parking_tests(void);
void run_statistics_tests(void);
void run_simulation_tests(void);

int main(void)
{
    run_queue_tests();
    run_vehicle_tests();
    run_parking_tests();
    run_statistics_tests();
    run_simulation_tests();

    printf("Alle Tests bestanden!\n");
    
    return 0;
}