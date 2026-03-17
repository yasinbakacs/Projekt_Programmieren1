# Projekt_Programmieren1

---

## Parkhaus-Simulation – Programmieren I (Teil 1)

Dieses Projekt wurde im Rahmen des Moduls **Programmieren I** erstellt.  
Ziel ist die Entwicklung einer Simulation eines Parkhauses.

Das Projekt besteht aus zwei Teilen:

- **Teil 1:** Programmentwurf mit Pseudocode und Strukturplanung  
- **Teil 2:** Vollständige Implementierung in C

---

## Ziel der Simulation

Die Simulation bildet ein Parkhaus mit folgenden Eigenschaften ab:

- Feste Anzahl an Stellplätzen  
- Fahrzeuge kommen mit einer bestimmten Wahrscheinlichkeit an  
- Bei vollem Parkhaus wird eine Warteschlange verwendet  
- Fahrzeuge verlassen das Parkhaus nach Ablauf ihrer Parkdauer  
- Statistische Auswertung über die gesamte Laufzeit

---

## Projektstruktur

- /include
   - vehicle.h
   - queue.h
   - parking.h
   - simulation.h
   - statistics.h

- /src
   - vehicle.c
   - queue.c
   - parking.c
   - simulation.c
   - statistics.c
   - main.c

- /src_pseudo
   - pseudo_vehicle.c
   - pseudo_queue.c
   - pseudo_parking.c
   - pseudo_simulation.c
   - pseudo_statistics.c
   - pseudo_main.c

- /tests
   - test_vehicle.c
   - test_queue.c
   - test_parking.c
   - test_statistics.c

- /docs
   - statistics_uebersicht.md
   - Ausgabe_step_Konsole.txt
   - Ausgabe_gesamt_Konsole.txt
   - flowcharts/
      - simulation_step_flowchart.drawio.png
      - parkingVehicle_flowchart.drawio.png
      - processDepartures_flowchart.drawio.png

---

## Modulübersicht

### vehicle
Repräsentiert ein einzelnes Fahrzeug
Enthält:
- ID
- Einfahrtszeit
- Verbleibende Parkdauer

---

### queue
Dynamische Warteschlange
Verwaltet Fahrzeuge, wenn das Parkhaus voll ist.

---

### parking
Verwaltet das Parkhaus:
- Initialisierung der Stellplätze
- Einparken von Fahrzeugen
- Verarbeitung von Abfahrten
- Verwaltung der belegten Plätze

---

### simulation
Steuert den gesamten Ablauf:
- Initialisierung
- Zeitschleife
- Fahrzeugankünfte
- Warteschlangen-Logik
- Statistikaktualisierung

---

### statistics
Das statistics-Modul übernimmt die analytische Auswertung der Simulation.  
Es sammelt Zustandsdaten pro Zeitschritt, berechnet aggregierte Kennzahlen
über die gesamte Laufzeit und stellt diese strukturiert für Konsole und Datei bereit.

---

## Programmentwurf (Teil 1)

- Modularer Aufbau  
- Klare Trennung von Verantwortlichkeiten  
- Verwendung von Header- und C-Dateien  
- Algorithmen in strukturiertem Pseudocode  
- Verwendung der vorgegebenen Schlüsselwörter:
  - FUNCTION  
  - IF ... THEN  
  - FOR ... DO  
  - WHILE ... DO  
  - RETURN  
  - OUTPUT  
  - ←

---

## Geplante Statistiken

- Anzahl belegter Stellplätze (pro Zeitschritt und gesamt Durchschnitt)
- Länge der Warteschlange (pro Zeitschritt und gesamt Durchschnitt)
- Anzahl Ankünfte (pro Zeitschritt und gesamt)
- Anzahl Abfahrten (pro Zeitschritt und gesamt)
- Auslastung in Prozent (pro Zeitschritt und gesamt Durchschnitt)

---

## Flussdiagramme

Drei zentrale Funktionen wurden als Flussdiagramme modelliert:

- simulation_step
- parkingVehicle
- processDepartures

---

## Teammitglieder

- Batu Özdemir
- Yasin Bakacs
- Sefa Yilmaz

---

## Entwicklungsumgebung

- Programmiersprache: C  
- Entwicklung in Visual Studio Code  
- Arbeitsverwaltung mit GitHub