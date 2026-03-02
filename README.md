# Projekt_Programmieren1

---

## Parkhaus-Simulation – Programmieren I (Teil 1)

Dieses Projekt wurde im Rahmen des Moduls **Programmieren I** erstellt.  
Ziel ist die Planung und Strukturierung einer Simulation eines Parkhauses.

In **Teil 1** wird das Programm konzipiert.  
Die Algorithmen werden in strukturiertem **Pseudocode** beschrieben.  
Die vollständige Implementierung erfolgt in Teil 2.

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
Erfasst und speichert:
- Belegte Stellplätze
- Warteschlangenlänge
- Anzahl Abfahrten
- Anzahl Einparkvorgänge
- Durchschnittswerte

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

- Anzahl belegter Stellplätze
- Länge der Warteschlange
- Anzahl Ankünfte
- Anzahl Abfahrten
- Durchschnittliche Auslastung

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