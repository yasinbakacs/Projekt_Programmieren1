/*
 * File: queue.c
 * Beschreibung: Implementiert eine dynamische Warteschlange
 */

#include "queue.h"
#include <stdio.h>


void queue_init(queue *p_queue)
{
    /*
    FUNCTION queue_init(p_queue)

        IF p_queue = NULL THEN
            RETURN
        END IF

        p_queue.p_first ← NULL
        p_queue.p_last ← NULL
        p_queue.size ← 0

    END FUNCTION
    */
}


int queue_enqueue(queue *p_queue,
                  vehicle item)
{
    /*
    FUNCTION queue_enqueue(p_queue, item)

        IF p_queue = NULL THEN
            RETURN 0
        END IF

        p_new_node ← neuen queue_node Speicher reservieren

        IF p_new_node = NULL THEN
            RETURN 0
        END IF

        p_new_node.data ← item
        p_new_node.p_next ← NULL

        IF p_queue.p_first = NULL THEN
            p_queue.p_first ← p_new_node
            p_queue.p_last ← p_new_node
        ELSE
            p_queue.p_last.p_next ← p_new_node
            p_queue.p_last ← p_new_node
        END IF

        p_queue.size ← p_queue.size + 1

        RETURN 1

    END FUNCTION
    */

    return 0;
}


int queue_dequeue(queue *p_queue,
                  vehicle *p_item)
{
    /*
    FUNCTION queue_dequeue(p_queue, p_item)

        IF p_queue = NULL THEN
            RETURN 0
        END IF

        IF p_item = NULL THEN
            RETURN 0
        END IF

        IF p_queue.p_first = NULL THEN
            RETURN 0
        END IF

        p_temp ← p_queue.p_first
        *p_item ← p_temp.data

        p_queue.p_first ← p_temp.p_next

        IF p_queue.p_first = NULL THEN
            p_queue.p_last ← NULL
        END IF

        Speicher von p_temp freigeben

        p_queue.size ← p_queue.size - 1

        RETURN 1

    END FUNCTION
    */

    return 0;
}