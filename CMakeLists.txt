cmake_minimum_required(VERSION 3.10)

project(ParkhausSimulation C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(simulation
    src/main.c
    src/simulation.c
    src/parking.c
    src/queue.c
    src/vehicle.c
    src/statistics.c
)

add_executable(tests
    tests/test_main.c
    tests/test_queue.c
    tests/test_vehicle.c
    tests/test_parking.c
    tests/test_statistics.c
    tests/test_simulation.c
    src/simulation.c
    src/parking.c
    src/queue.c
    src/vehicle.c
    src/statistics.c
)