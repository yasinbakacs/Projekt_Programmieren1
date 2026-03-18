# Dokumentation – Parkhaus-Simulation in C

## 1. Vorgehensweise zur Lösung der Aufgabenstellung

Zuerst wurde die Aufgabenstellung, in C eine Simulation für ein Parkhaus mit Zeitschritten zu erstellen, analysiert. Diese war grundsätzlich schon in zwei Teile aufgeteilt, was den Anfang erleichterte. Für den ersten Teil bestand die Aufgabe darin, eine strukturierte Planung und ein Grundgerüst für die Parkhaus-Simulation zu entwickeln.

Um zu beginnen, befassten wir uns mit den Vorgaben bezüglich des Abgabeumfangs und der Strukturen und erstellten dementsprechend das gewünschte Repository. Im Anschluss wurde der verlangte Abgabeinhalt analysiert und in Issues im Kanban-Board eingetragen, welche daraufhin gleichmäßig im Team zugewiesen wurden. Die c-Dateien wurden anschließend in Pseudocode erstellt, während die h-Dateien direkt implementiert wurden.

Die erarbeitete Lösungslogik ist folgende:

Im groben Ablauf unseres Programms kommen Fahrzeuge zufällig und versuchen, in dem Parkhaus zu parken. Dabei wird überprüft, ob das Parkhaus freie Plätze hat. Ist ein freier Platz vorhanden, wird das Fahrzeug direkt eingeparkt und erhält eine zufällig generierte Parkdauer. Sind hingegen alle Stellplätze belegt, wird das Fahrzeug in eine Warteschlange eingereiht.

Sobald ein Parkplatz frei wird, wird das nächste Fahrzeug aus der Warteschlange in das Parkhaus übernommen.

Während der Simulation wird für jedes Fahrzeug die verbleibende Parkdauer reduziert. Sobald diese den Wert null erreicht, verlässt das Fahrzeug das Parkhaus, wodurch ein Stellplatz wieder frei wird. Dieser kann anschließend entweder von einem neuen Fahrzeug oder einem wartenden Fahrzeug aus der Warteschlange belegt werden.

Die relevanten Parameter der Simulation, wie beispielsweise die Anzahl der Stellplätze, die maximale Parkdauer oder die Ankunftswahrscheinlichkeit, sind zur Laufzeit konfigurierbar. Dadurch kann das Verhalten der Simulation flexibel angepasst und analysiert werden.

---

## 2. Modularisierung des Programms

Die unterschiedlichen Abläufe werden in mehreren Dateien formuliert, welche in der Main-Datei aufgegriffen werden. Dabei sind die Abläufe in folgende Module gegliedert:

- `parking.c/h` → Verwaltung der Stellplätze (Einparken/Ausparken)
- `queue.c/h` → Warteschlange (dynamische Speicherverwaltung)
- `vehicle.c/h` → Fahrzeugstruktur und Erstellung
- `simulation.c/h` → Steuerung der Simulation
- `statistics.c/h` → Erfassung und Ausgabe von Statistiken

Jede Datei übernimmt eine klar definierte Aufgabe. Dadurch konnte eine übersichtliche und erweiterbare Architektur geschaffen werden. Änderungen oder Erweiterungen können so gezielt in einzelnen Modulen vorgenommen werden, ohne das gesamte System zu beeinflussen.

Diese Vorgehensweise entspricht auch den Anforderungen an Modularisierung und saubere Strukturierung aus der Aufgabenstellung :contentReference[oaicite:0]{index=0} sowie den grundlegenden Coding-Guidelines zur Trennung von `.c`- und `.h`-Dateien :contentReference[oaicite:1]{index=1}.

---

## 3. Implementierung (Teil II)

Im zweiten Teil der Aufgabenstellung wurden die zuvor geplanten C-Dateien vollständig implementiert. Dies erfolgte ebenfalls durch eine gleichmäßige Aufteilung im Team.

Zusätzlich wurden Unit-Tests sowie eine Dokumentation erstellt, wie in der Aufgabenstellung gefordert :contentReference[oaicite:2]{index=2}.

Die Aufteilung der Dateien entstand durch Diskussionen im Team, insbesondere hinsichtlich der Frage, wie viele Module sinnvoll sind. Beispielsweise war die Funktionalität der Fahrzeuge anfangs Teil der Simulation, wurde später jedoch in ein eigenes Modul ausgelagert, um die Übersichtlichkeit zu verbessern.

---

## 4. Statistiken

Die Wahl der Statistiken wurde im Team diskutiert, da diese selbst definiert werden mussten. Wir haben uns für folgende Kennzahlen entschieden:

- Step (Zeitschritt)
- Occupied Spots (belegte Stellplätze)
- Utilization Percent (Auslastung)
- Queue Length (Länge der Warteschlange)
- Departures / Parked this Step

Diese liefern eine gute Grundlage zur Analyse der Auslastung und des Verhaltens der Simulation. Weitere mögliche Statistiken wären beispielsweise gewesen:

- Anzahl der vollständigen Belegungen
- Durchschnittliche Wartezeit
- Maximale Warteschlangenlänge

Diese wurden jedoch nicht umgesetzt, da die gewählten Statistiken bereits eine ausreichende Informationsbasis bieten.

---

## 5. Unit-Tests

Für jede Funktion (außer `main`) wurden mindestens zwei Unit-Tests mit der Bibliothek `assert.h` implementiert, wie in der Aufgabenstellung gefordert :contentReference[oaicite:3]{index=3}.

### Vorgehensweise:

- Für jedes Modul wurde eine eigene Testdatei erstellt (z. B. `test_vehicle.c`)
- Funktionen wurden gezielt mit gültigen und ungültigen Eingaben getestet
- Rückgabewerte und Zustände wurden mit `assert()` überprüft

## 6. Kompilieren und Ausführen (mit CMake)

### Build-Verzeichnis erstellen

```bash
mkdir build
cd build
```

### Projekt konfigurieren

```bash
cmake ..
```

### Projekt kompilieren

```bash
cmake --build .
```

---

### Programm ausführen

```bash
./simulation
```

Danach werden die Eingaben im Terminal abgefragt (z. B. Anzahl Stellplätze, Parkdauer usw.).

---

## 7. Tests kompilieren und ausführen

Falls die Tests ebenfalls im CMake-Projekt integriert sind:

```bash
cmake --build .
```

### Tests ausführen

```bash
./tests
```

Wenn alle Tests erfolgreich sind, erscheint:

```
Alle Tests bestanden!
```

---

## 8. Teamarbeit

Die Teamarbeit verlief effizient und strukturiert. Aufgaben wurden gleichmäßig verteilt und regelmäßig über das Repository überprüft. Pull Requests wurden schnell bearbeitet, wodurch kontinuierlich Feedback eingeholt und umgesetzt werden konnte.

---

## 9. Fazit

Die Aufgabenstellung wurde durch eine klare Struktur, Modularisierung und schrittweise Implementierung erfolgreich umgesetzt. Durch Unit-Tests und Teamarbeit konnte ein stabiles und erweiterbares Programm entwickelt werden.