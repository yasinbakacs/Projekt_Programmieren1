#ifndef QUEUE_H
#define QUEUE_H

#include "vehicle.h"

/*
 * Struktur: queue_node
 * Beschreibung: Ein Knoten der Warteschlange (dynamisch)
 */
typedef struct queue_node
{
    vehicle data;
    struct queue_node *p_next;
} queue_node;


/*
 * Struktur: queue
 * Beschreibung: Warteschlange für Fahrzeuge vor dem Parkhaus
 */
typedef struct queue
{
    queue_node *p_first;
    queue_node *p_last;
    int size;
} queue;


/**
 * @brief Initialisiert eine leere Warteschlange
 *
 * @param[in,out] p_queue Zeiger auf die Warteschlange
 */
void queue_init(queue *p_queue);


/**
 * @brief Fügt ein Fahrzeug hinten an die Warteschlange an
 *
 * @param[in,out] p_queue   Zeiger auf die Warteschlange
 * @param[in]     new_item  Fahrzeug, das eingefügt werden soll
 * @return                 1 bei Erfolg, 0 bei Fehler (z.B. malloc fehlgeschlagen)
 */
int queue_enqueue(queue *p_queue, vehicle new_item);


/**
 * @brief Entfernt das vorderste Fahrzeug aus der Warteschlange
 *
 * @param[in,out] p_queue   Zeiger auf die Warteschlange
 * @param[out]    p_item    Zeiger auf Ausgabe-Fahrzeug
 * @return                 1 wenn ein Element entfernt wurde, sonst 0 (leer oder Fehler)
 */
int queue_dequeue(queue *p_queue, vehicle *p_item);


#endif