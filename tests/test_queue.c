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

}

void test_queue_enqueue_add_multiple(void)
{

}

void test_queue_dequeue_remove(void)
{

}

void test_queue_dequeue_empty(void)
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