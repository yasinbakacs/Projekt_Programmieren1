#ifndef QUEUE_H
#define QUEUE_H

#include "vehicle.h"

/*
 * Struktur: queue_node
 * Beschreibung: Ein Knoten der Warteschlange
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
 * @return                  1 bei Erfolg, 0 bei Fehler
 */
int queue_enqueue(queue *p_queue, vehicle new_item);


/**
 * @brief Entfernt das vorderste Fahrzeug aus der Warteschlange
 *
 * @param[in,out] p_queue   Zeiger auf die Warteschlange
 * @param[out]    p_item    Zeiger auf Ausgabe-Fahrzeug
 * @return                  1 wenn ein Fahrzeug entfernt wurde, sonst 0
 */
int queue_dequeue(queue *p_queue, vehicle *p_item);


/**
 * @brief Gibt die Anzahl der Fahrzeuge in der Warteschlange zurück
 *
 * @param[in] p_queue Zeiger auf die Warteschlange
 * @return            Anzahl der Fahrzeuge
 */
int queue_get_size(const queue *p_queue);


/**
 * @brief Prüft, ob die Warteschlange leer ist
 *
 * @param[in] p_queue Zeiger auf die Warteschlange
 * @return            1 wenn leer, sonst 0
 */
int queue_is_empty(const queue *p_queue);


/**
 * @brief Gibt den Speicher der Warteschlange vollständig frei
 *
 * @param[in,out] p_queue Zeiger auf die Warteschlange
 */
void queue_free(queue *p_queue);

#endif