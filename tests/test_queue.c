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
    queue q;

    queue_init(&q);

    assert(q.p_first == NULL);
    assert(q.p_last == NULL);
    assert(q.size == 0);
    assert(queue_is_empty(&q) == 1);
    assert(queue_get_size(&q) == 0);
}

void test_queue_enqueue_add(void)
{
    queue q;
    vehicle v1 = create_test_vehicle(1, 0, 5);

    queue_init(&q);

    assert(queue_enqueue(&q, v1) == 1);

    assert(q.p_first != NULL);
    assert(q.p_last != NULL);
    assert(q.p_first == q.p_last);
    assert(q.size == 1);
    assert(queue_is_empty(&q) == 0);
    assert(queue_get_size(&q) == 1);
    assert(q.p_first->data.id == 1);

    queue_free(&q);
}

void test_queue_enqueue_add_multiple(void)
{
    queue q;
    vehicle v1 = create_test_vehicle(1, 0, 5);
    vehicle v2 = create_test_vehicle(2, 1, 4);

    queue_init(&q);

    assert(queue_enqueue(&q, v1) == 1);
    assert(queue_enqueue(&q, v2) == 1);

    assert(q.size == 2);
    assert(q.p_first != NULL);
    assert(q.p_last != NULL);
    assert(q.p_first->data.id == 1);
    assert(q.p_last->data.id == 2);
    assert(q.p_first->p_next == q.p_last);

    queue_free(&q);
}

void test_queue_dequeue_remove(void)
{
    queue q;
    vehicle v1 = create_test_vehicle(1, 0, 5);
    vehicle v2 = create_test_vehicle(2, 1, 4);
    vehicle out_vehicle;

    queue_init(&q);

    assert(queue_enqueue(&q, v1) == 1);
    assert(queue_enqueue(&q, v2) == 1);
    assert(queue_dequeue(&q, &out_vehicle) == 1);

    assert(out_vehicle.id == 1);
    assert(q.size == 1);
    assert(q.p_first != NULL);
    assert(q.p_first->data.id == 2);
    assert(q.p_last != NULL);
    assert(q.p_last->data.id == 2);

    queue_free(&q);
}

void test_queue_dequeue_empty(void)
{
    queue q;
    vehicle out_vehicle;

    queue_init(&q);

    assert(queue_dequeue(&q, &out_vehicle) == 0);
    assert(queue_is_empty(&q) == 1);
    assert(queue_get_size(&q) == 0);

    queue_free(&q);
}

void test_queue_get_size(void)
{
    queue q;
    vehicle v1 = create_test_vehicle(1, 0, 5);
    vehicle v2 = create_test_vehicle(2, 1, 4);

    queue_init(&q);

    assert(queue_get_size(&q) == 0);

    assert(queue_enqueue(&q, v1) == 1);
    assert(queue_get_size(&q) == 1);

    assert(queue_enqueue(&q, v2) == 1);
    assert(queue_get_size(&q) == 2);

    queue_free(&q);
}

void test_queue_is_empty(void)
{
    queue q;
    vehicle v1 = create_test_vehicle(1, 0, 5);
    vehicle out_vehicle;

    queue_init(&q);

    assert(queue_is_empty(&q) == 1);

    assert(queue_enqueue(&q, v1) == 1);
    assert(queue_is_empty(&q) == 0);

    assert(queue_dequeue(&q, &out_vehicle) == 1);
    assert(queue_is_empty(&q) == 1);

    queue_free(&q);
}

void test_queue_free(void)
{
    queue q;
    vehicle v1 = create_test_vehicle(1, 0, 5);
    vehicle v2 = create_test_vehicle(2, 1, 4);

    queue_init(&q);

    assert(queue_enqueue(&q, v1) == 1);
    assert(queue_enqueue(&q, v2) == 1);

    queue_free(&q);

    assert(q.p_first == NULL);
    assert(q.p_last == NULL);
    assert(q.size == 0);
    assert(queue_is_empty(&q) == 1);
}


int main(void)
{
    test_queue_init();
    test_queue_enqueue_add();
    test_queue_enqueue_add_multiple();
    test_queue_dequeue_remove();
    test_queue_dequeue_empty();
    test_queue_get_size();
    test_queue_is_empty();
    test_queue_free();

    printf("Alle Queue Tests bestanden!\n");

    return 0;
}