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

- /.vscode  
- /build  
- /build-linux  

- /docs  
   - /Dokumente  
      - /Teil_1  
         - /flowcharts  
            - parkingVehicle_flowchart.drawio.png  
            - processDepartures_flowchart.drawio.png  
            - simulation_step_flowchart.drawio.png  
         - Ausgabe_gesamt_Konsole.txt  
         - Ausgabe_step_Konsole.txt  
         - statistics_uebersicht.md  
      - /Teil_2  
         - Dokumentation.md  
   - simulation_steps.txt  

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
   - test_simulation.c  
   - test_statistics.c  
   - test_main.c  

- CMakeLists.txt  
- README.md  

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

## Implementierung (Teil 2)

In Teil 2 wurde der Programmentwurf vollständig in C umgesetzt.  
Alle Module wurden implementiert und miteinander integriert.

Zusätzlich wurden für jede Funktion mindestens zwei Unit-Tests erstellt.

---

## Unit-Tests

Für die wichtigsten Funktionen wurden Unit-Tests implementiert, 
um die Korrektheit der Implementierung sicherzustellen.

Die Tests befinden sich im Ordner:

tests/

---

## Programmausführung

Nach dem Start werden folgende Eingaben abgefragt:

- Anzahl Stellplätze
- Maximale Parkdauer
- Anzahl Zeitschritte
- Ankunftswahrscheinlichkeit
- Zufalls-Seed

Anschließend wird die Simulation durchgeführt und die Ergebnisse werden auf der Konsole sowie in einer Datei ausgegeben.

---

## Statistiken

Details zu den berechneten Kennzahlen befinden sich in:

docs/statistics_uebersicht.md

---

## Flussdiagramme

Drei zentrale Funktionen wurden als Flussdiagramme modelliert:

- simulation_step
- parkingVehicle
- processDepartures

Diese befinden sich im Ordner:
docs/flowcharts

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
- Kompilierung  mit CMake