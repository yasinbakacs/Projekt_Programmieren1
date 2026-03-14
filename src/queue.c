/*
 * File: queue.c
 * Beschreibung: Implementiert eine dynamische Warteschlange
 */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


void queue_init(queue *p_queue)
{
    if (p_queue == NULL)
    {
        return;
    }

    p_queue->p_first = NULL;
    p_queue->p_last = NULL;
    p_queue->size = 0;
}


int queue_enqueue(queue *p_queue, vehicle new_item)
{
    queue_node *p_new_node = NULL;

    if (p_queue == NULL)
    {
        return 0;
    }

    p_new_node = malloc(sizeof(queue_node));
    if (p_new_node == NULL)
    {
        return 0;
    }

    p_new_node->data = new_item;
    p_new_node->p_next = NULL;

    if (p_queue->p_first == NULL)
    {
        p_queue->p_first = p_new_node;
        p_queue->p_last = p_new_node;
    }
    else
    {
        p_queue->p_last->p_next = p_new_node;
        p_queue->p_last = p_new_node;
    }

    p_queue->size = p_queue->size + 1;

    return 1;
}


int queue_dequeue(queue *p_queue, vehicle *p_item)
{
     queue_node *p_temp = NULL;

    if (p_queue == NULL)
    {
        return 0;
    }

    if (p_item == NULL)
    {
        return 0;
    }

    if (p_queue->p_first == NULL)
    {
        return 0;
    }

    p_temp = p_queue->p_first;
    *p_item = p_temp->data;

    p_queue->p_first = p_temp->p_next;

    if (p_queue->p_first == NULL)
    {
        p_queue->p_last = NULL;
    }

    free(p_temp);
    p_queue->size = p_queue->size - 1;

    return 1;
}


int queue_get_size(const queue *p_queue)
{
    if (p_queue == NULL)
    {
        return 0;
    }

    return p_queue->size;
}


int queue_is_empty(const queue *p_queue)
{
    if (p_queue == NULL)
    {
        return 1;
    }

    if (p_queue->size == 0)
    {
        return 1;
    }

    return 0;
}


void queue_free(queue *p_queue)
{
    queue_node *p_temp = NULL;

    if (p_queue == NULL)
    {
        return;
    }

    while (p_queue->p_first != NULL)
    {
        p_temp = p_queue->p_first;
        p_queue->p_first = p_queue->p_first->p_next;
        free(p_temp);
    }

    p_queue->p_last = NULL;
    p_queue->size = 0;
}