# hw-probe – ESP32-Info-Sketch (Phase 0)

Liest Chipmodell, Revision, Flashgröße und eine verkürzte MAC-Adresse aus und gibt sie seriell aus. Damit lassen sich die vier Boards eindeutig erfassen, **bevor** Board-Definition, Pins oder Funkfrequenzen festgelegt werden.

| Macht der Sketch | Macht der Sketch nicht |
|---|---|
| Chipdaten seriell ausgeben, alle 5 s wiederholen | GPIOs schalten (keine LED, kein OLED) |
| | LoRa, WLAN oder Bluetooth nutzen – es wird **nichts gesendet** |

Trotzdem gilt: **Antenne vor dem Einschalten anschließen**, kein Akku, kein Taster, kein Motor (siehe [Hardware-Inventur](../../docs/hardware-inventory.md#sicherheitshinweise-vor-dem-ersten-anschließen)).

## Einrichtung (einmalig)

1. **Arduino IDE 2** installieren: <https://www.arduino.cc/en/software>
2. *Arduino IDE → Einstellungen → Zusätzliche Boardverwalter-URLs*:
   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
3. *Werkzeuge → Board → Boardverwalter*: **„esp32“ von Espressif Systems** installieren. Installierte Version notieren.

Ein Heltec-spezifisches Board-Paket ist für diesen Sketch **nicht** nötig. Welche Board-Definition später verwendet wird, entscheiden wir erst nach der Inventur.

## Flashen und auslesen – je Board

1. Board per **Micro-USB-Datenkabel** anschließen.
2. *Werkzeuge → Port*: neuen Eintrag wählen (z. B. `/dev/cu.usbserial-…` oder `/dev/cu.wchusbserial-…`). Portnamen notieren.
   - **Kein neuer Port?** Anderes Kabel probieren. Dann den USB-UART-Chip auf dem Board ablesen und den passenden macOS-Treiber prüfen (Silicon Labs für CP210x, WCH für CH34x/CH9102). Treiber nur von der Herstellerseite installieren.
3. *Werkzeuge → Board*: **ESP32 Dev Module**.
4. `hw-probe.ino` öffnen und **Hochladen**.
   - Im Ausgabefenster steht bereits eine Zeile wie `Chip is …` bzw. `Chip type: …` – diese Zeile **mit notieren**.
   - Meldet das Hochladen einen anderen Chiptyp als ESP32 (z. B. ESP32-S3), ist das ein Ergebnis, kein Fehler: Zeile notieren, nicht weiter probieren.
   - Bei `Failed to connect`: während „Connecting…“ die Taste **PRG/BOOT** am Board gedrückt halten (falls vorhanden).
5. *Werkzeuge → Serieller Monitor*, **115200 Baud**. Nach Bedarf die Taste **RST** drücken.
6. Ausgabe in [`docs/hardware-inventory.md`](../../docs/hardware-inventory.md) beim jeweiligen Board (B1–B4) eintragen.

## Erwartete Ausgabe (Format)

Werte hier nur als Platzhalter – die echten Werte stammen von deinen Boards:

```text
=== NotfallbuttonLoRa hw-probe ===
Chipmodell:      <z. B. ESP32-D0WDQ6>
Chip-Revision:   <Zahl>
CPU-Kerne:       <Zahl>
CPU-Takt:        <MHz>
Flashgroesse:    <MB>
Flashtakt:       <MHz>
PSRAM:           <KB>
MAC (letzte 3):  XX:XX:XX
Reset-Grund:     <z. B. POWERON>
ESP-IDF/SDK:     <Version>
Arduino-Core:    <Version>
Laufzeit:        <s>
==================================
```

Die vollständige MAC-Adresse bitte **nicht** ins Repository übernehmen – die letzten drei Bytes reichen zur Unterscheidung.

## Status

- Sketch geschrieben, **noch nicht kompiliert und nicht auf Hardware getestet** (`OFFEN / ZU TESTEN`).
