# Statistik-Übersicht - Parkhaus-Simulation

## 1. Ziel der Statistiken

Die statistiken dienen dazu, die Leistung und Effizienz des Parkhauses
über die gesamte Simulationsdauer zu bewerten. 

## 2. Erfasste Statistiken pro Zeitschritt

- Step
- Occupied Spots: Die Anzahl der aktuell besetzten Parkplätze.
- Utilization Percent
- Queue Length
- Departures this Step
- Parked this Step

### Step

Beschreibung:
Der aktuelle Zeitschritt der Simulation. Er beginnt bei 0 und wird in jedem Simulationszyklus um 1 erhöht.

Begründung:
Der Zeitschritt ermöglicht es, die Entwicklung der anderen Statistiken im Zeitverlauf zu verfolgen.

### Occupied Spots
Beschreibung:
Die Anzahl der Parkplätze, die zu einem bestimmten Zeitschritt besetzt sind.

Begründung:
Diese Statistik gibt Aufschluss über die Auslastung des Parkhauses und hilft, über Ausbauten oder Anpassungen zu entscheiden.

### Utilization Percent
Beschreibung:
Die prozentuale Auslastung des Parkhauses, berechnet als (besetzte Parkplätze / Gesamtparkplätze) * 100.

Begründung:
Diese Metrik bietet eine leicht verständliche Darstellung der Effizienz des Parkhauses.

### Queue Length
Beschreibung:
Die Anzahl der Fahrzeuge, die in der Warteschlange stehen, um einen Parkplatz zu erhalten.

Begründung:
Die Länge der Warteschlange zeigt, wie gut das Parkhaus mit der Nachfrage (Ankunftsrate) umgehen kann.

### Departures this Step
Beschreibung:
Die Anzahl der Fahrzeuge, die in einem bestimmten Zeitschritt das Parkhaus verlassen.

Begründung:
Diese Statistik hilft, die Änderungen in der Belegung des Parkhauses zu verstehen.

### Parked this Step
Beschreibung:
Die Anzahl der Fahrzeuge, die in einem bestimmten Zeitschritt aus der Warteschlange einfahren und auf einem Parkplatz einparken können.

Begründung:
Diese Statistik hilft, die Effizienz des Parkhauses bei der Bearbeitung der Warteschlange zu bewerten.

## 3. Erfassung der Endstatistiken
Am Ende der Simulation werden folgende Statistiken erfasst:

- Total Steps
- Total Departures
- Total Parked
- Sum Occupied (Später Avg Occupied)
- Sum Queue (Später Avg Queue)

### Total Steps
Beschreibung:
Die Gesamtzahl der Zeitschritte, die während der gesamten Simulationsdauer durchlaufen wurden.

Begründung:
Diese Statistik gibt Aufschluss über die Länge der Simulation und ermöglicht es, die anderen Statistiken im Kontext der Simulationsdauer zu interpretieren.

### Total Departures
Beschreibung:
Die Gesamtzahl der Fahrzeuge, die während der gesamten Simulationsdauer das Parkhaus verlassen haben.

Begründung:
Diese Statistik zeigt, wie viele Fahrzeuge das Parkhaus erfolgreich nutzen konnten.

### Total Parked
Beschreibung:
Die Gesamtzahl der Fahrzeuge, die während der gesamten Simulationsdauer im Parkhaus angekommen sind.

Begründung:
Diese Statistik gibt Aufschluss über die Gesamtbelastung des Parkhauses.

### Average Occupied
Beschreibung:
Die durchschnittliche Anzahl der besetzten Parkplätze über die gesamte Simulationsdauer,
berechnet als die Summe der besetzten Parkplätze pro Zeitschritt geteilt durch die 
Anzahl der Zeitschritte.

Begründung:
Diese Statistik gibt Aufschluss darüber, wie stark das Parkhaus im Durchschnitt ausgelastet ist.

### Average Queue 
Beschreibung:
Die durchschnittliche Länge der Warteschlange über die gesamte Simulationsdauer, 
berechnet als die Summe der Warteschlangenlängen pro Zeitschritt geteilt durch 
die Anzahl der Zeitschritte.

Begründung:
Diese Statistik gibt Aufschluss darüber, wie oft bzw wie lange Fahrzeuge warten 
müssen, um einen Parkplatz zu erhalten.

## 4. Nutzung der Statistiken
Die gesammelten Statistiken werden dann jeweils in die Konsole ausgegeben, um die Leistung 
des Parkhauses direkt nach der Simulation zu bewerten. Sie werden außerdem auch in einer Datei
gespeichert, um eine spätere Analyse und Vergleichbarkeit mit anderen Simulationen zu ermöglichen.
