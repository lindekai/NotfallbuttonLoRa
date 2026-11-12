# Hardware-Inventur (Phase 0)

> Status: **Erfassungsbogen – noch nicht ausgefüllt.**  
> Alle Werte gelten erst als belegt, wenn sie durch Aufdruck, Foto, Verpackung oder serielle Ausgabe nachgewiesen sind. Bis dahin: `OFFEN`.

## Sicherheitshinweise vor dem ersten Anschließen

- **Niemals mit LoRa senden ohne angeschlossene Antenne** – das kann den Funkchip beschädigen. Der Info-Sketch aus Schritt 3 sendet nicht; trotzdem Antenne grundsätzlich vor dem Einschalten anschließen.
- Zunächst **kein Akku, kein Taster, kein Motor** anschließen. Nur Micro-USB an den Rechner.
- Abschirmblech (Metalldeckel) über dem Funkchip **nicht entfernen**.
- Datenkabel verwenden (reine Ladekabel werden vom Rechner nicht als serieller Port erkannt).

## Identifikationshinweise

Die folgenden Hinweise sind **Orientierung, keine Festlegung**. Entscheidend ist, was auf dem jeweiligen Board steht.

| Merkmal | Wo nachsehen | Warum relevant |
|---|---|---|
| Revisionsaufdruck (z. B. „V2“, „V2.1“, „V3“) | Platinenunterseite, Siebdruck neben Logo | Bestimmt Board-Definition und Pinbelegung |
| Frequenzangabe (z. B. „868“, „915“, „433“, „470–510“) | Aufkleber auf Board oder Antistatikbeutel, Bestellunterlagen, Antenne | Nur eine **EU-868-Variante** darf in Deutschland betrieben werden |
| Bauform USB-Buchse | Board | Micro-USB passt zu älteren Revisionen; bestätigt allein aber keine Revision |
| USB-UART-Chip (Beschriftung, z. B. „CP2102“, „CH9102“) | kleiner Chip nahe der USB-Buchse, Lupe/Handykamera | Bestimmt den nötigen USB-Treiber unter macOS |
| Antennenanschluss (U.FL/IPEX-Buchse, SMA, Pigtail) | Board und mitgelieferte Antenne | Passende Antenne je Frequenzband |
| Antennenbeschriftung / Länge | Antenne | Antenne muss zum Frequenzband passen |
| Display-Auflösung | Datenblatt / Aufdruck, später per OLED-Test | Layout der Statusanzeigen |

## Fotos

Je Board mindestens: Oberseite, Unterseite (Siebdruck lesbar), Nahaufnahme USB-UART-Chip, Antennenanschluss, ggf. Aufkleber/Verpackung.  
Fotos **nicht** ins Repository legen, wenn Seriennummern, Bestelldaten oder Adressen erkennbar sind. Ablage: lokal, Referenz hier nur als Dateiname.

## Erfassung je Board

Die Zuordnung zu den Rollen (`SOS-01`, `GW-PRAXIS`, `GW-HOME`, `TEST-04`) erfolgt erst nach der Inventur. Boards physisch mit Etikett **B1–B4** markieren.

| Feld | B1 | B2 | B3 | B4 |
|---|---|---|---|---|
| Revisionsaufdruck | OFFEN | OFFEN | OFFEN | OFFEN |
| Frequenzangabe (Quelle?) | OFFEN | OFFEN | OFFEN | OFFEN |
| LoRa-Chip (falls ablesbar/bekannt) | OFFEN | OFFEN | OFFEN | OFFEN |
| USB-UART-Chip | OFFEN | OFFEN | OFFEN | OFFEN |
| Antennenanschluss | OFFEN | OFFEN | OFFEN | OFFEN |
| Antenne (Beschriftung/Band) | OFFEN | OFFEN | OFFEN | OFFEN |
| Sichtbare Schäden / Besonderheiten | OFFEN | OFFEN | OFFEN | OFFEN |
| Foto-Dateinamen | OFFEN | OFFEN | OFFEN | OFFEN |
| macOS erkennt seriellen Port (Name) | OFFEN | OFFEN | OFFEN | OFFEN |
| **Info-Sketch (Schritt 3):** Chipmodell | OFFEN | OFFEN | OFFEN | OFFEN |
| **Info-Sketch:** Chip-Revision | OFFEN | OFFEN | OFFEN | OFFEN |
| **Info-Sketch:** Flashgröße | OFFEN | OFFEN | OFFEN | OFFEN |
| **Info-Sketch:** MAC (nur letzte 3 Bytes eintragen) | OFFEN | OFFEN | OFFEN | OFFEN |
| Vorgesehene Rolle | OFFEN | OFFEN | OFFEN | OFFEN |

## Weitere Komponenten

| Komponente | Status | Notizen |
|---|---|---|
| LiPo-Akku (neu) | OFFEN – noch nicht beschafft/geprüft | Kapazität, Schutzschaltung, Steckertyp und **Polarität** vor Anschluss prüfen |
| SOS-Taster | OFFEN | Typ, Größe, Schließer/Öffner |
| ERM-Vibrationsmotor (iPhone 4 GSM) | OFFEN – Spannung/Strom ZU MESSEN | Nur über MOSFET/Treiber mit Freilaufdiode, nie direkt am GPIO |
| Arduino IDE (Version) | OFFEN | |
| ESP32-Board-Paket / Heltec-Paket (Version) | OFFEN – erst nach Identifikation festlegen | |

## Ergebnis Phase 0

OFFEN – wird nach Auswertung (Plan-Schritt 5) als ADR unter `docs/decisions/` festgehalten.
