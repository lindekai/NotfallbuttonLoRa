# Arbeitsplan

Freigegebener Plan für **Phase 0 (Hardware verifizieren)** und den Einstieg in **Phase 1 (LoRa-Funklabor)**. Jeder Schritt endet mit einem Commit und einer kurzen Abstimmung, bevor der nächste beginnt.

Legende: ✅ erledigt · 🟡 in Arbeit / wartet · ⚪ offen

| # | Schritt | Wer | Ergebnis | Stand |
|---|---|---|---|---|
| 1 | Repo-Grundgerüst: `README.md`, `.gitignore`, `CHANGELOG.md`, Projektauftrag als `CODE.md` | Entwicklung | sauberer Ausgangsstand | ✅ |
| 2 | Erfassungsbogen [`docs/hardware-inventory.md`](hardware-inventory.md) mit Checkliste je Board | Entwicklung | Erfassungsbogen | ✅ |
| 2a | Grafiken unter `docs/images/`, README-Gestaltung, Gehäuse und MIT-Lizenz aufgenommen | Entwicklung | gestaltetes Repository | ✅ |
| 2b | Gerüst der [Nachbau-Anleitung](anleitung/README.md) für das gesamte System, Kapitel 00 | Entwicklung | Anleitungsstruktur | ✅ |
| 3 | Board-unabhängiger ESP32-Info-Sketch [`firmware/hw-probe/`](../firmware/hw-probe/README.md) – keine GPIOs, kein Funk | Entwicklung | Info-Sketch (noch nicht kompiliert/getestet) | ✅ |
| 4 | Boards B1–B4 beschriften, fotografieren, Info-Sketch flashen, Ausgaben und Aufdrucke erfassen | Projektinhaber | ausgefüllte Inventur | 🟡 wartet |
| 5 | Auswertung: ADR zu Board-Definition, Library-Versionen und Pinbelegung; OLED-Init-Test; Anleitung Kapitel 01 und 02 | Entwicklung | gepinnte Toolchain | ⚪ |
| 6 | `docs/radio-test-plan.md` mit EU-868-Funkrecht (Duty Cycle, ERP – vom Projektinhaber zu verifizieren), Messaufbau und Kriterien „als Prototyp brauchbar“ | Entwicklung | Testplan | ⚪ |
| 7 | `firmware/radio-lab/`: gemeinsame Firmware mit Node-ID und TX/RX-Rolle, Sequenznummer, CRC, ACK, OLED-Werte, CSV-Ausgabe, Build-/Flash-/Testanleitung | Entwicklung | Phase-1-Firmware | ⚪ |

Die Schritte 5–7 beginnen erst, wenn Schritt 4 echte Hardwaredaten geliefert hat.

## Danach

Die weiteren Phasen 2–5 sind im Projektauftrag [`CODE.md`](../CODE.md#11-entwicklungsphasen) beschrieben. Für jede Phase wird vor Beginn ein eigener Arbeitsplan vorgelegt, freigegeben und hier ergänzt.
