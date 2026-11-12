# Anleitung: NotfallbuttonLoRa nachbauen

Diese Anleitung beschreibt das **gesamte System** – von den Notfallbuttons und Gateways über die Alarmdienste auf den Synology-NAS bis zu n8n, Pushover, Tailscale und der FRITZ!Box.

Programmiert werden nur die Firmware der Heltec-Boards und ein schlanker Alarm-Eingangsdienst. Alles andere wird eingerichtet; auch diese Einrichtung ist hier Schritt für Schritt dokumentiert.

> [!IMPORTANT]
> Kapitel werden erst ausgearbeitet, wenn der jeweilige Teil tatsächlich aufgebaut und getestet ist. Ein Kapitel mit Status **⚪ offen** ist ein Gerüst, keine Anleitung.

## Kapitel

| Nr. | Kapitel | entsteht in | Status |
|---|---|---|---|
| 00 | [Überblick, Voraussetzungen, Grenzen](00-ueberblick.md) | jetzt | 🟡 erste Fassung |
| 01 | [Hardware, Stückliste und Werkzeuge](01-hardware-und-werkzeuge.md) | Phase 0 | ⚪ offen |
| 02 | [Boards identifizieren und vorbereiten](02-boards-identifizieren.md) | Phase 0 | ⚪ offen |
| 03 | [Funklabor: Reichweite messen](03-funklabor-reichweite.md) | Phase 1 | ⚪ offen |
| 04 | [Notfallbutton-Firmware flashen und konfigurieren](04-notfallbutton-firmware.md) | Phase 2 | ⚪ offen |
| 05 | [Gateways aufbauen und flashen](05-gateways.md) | Phase 3 | ⚪ offen |
| 06 | [Gehäuse drucken und montieren](06-gehaeuse-drucken.md) | Phase 5 | ⚪ offen |
| 07 | [Synology: Alarmdienst als Container](07-synology-alarmdienst.md) | Phase 3 | ⚪ offen |
| 08 | [n8n in Praxis und Zuhause](08-n8n.md) | Phase 3/4 | ⚪ offen |
| 09 | [Pushover: Emergency, Quittierung, Eskalation](09-pushover.md) | Phase 4 | ⚪ offen |
| 10 | [Tailscale zwischen den NAS](10-tailscale.md) | Phase 3 | ⚪ offen |
| 11 | [FRITZ!Box: Netz, Geräte, optional SIP-Anruf](11-fritzbox.md) | Phase 3/4 | ⚪ offen |
| 12 | [Inbetriebnahme und Ende-zu-Ende-Tests](12-inbetriebnahme-und-tests.md) | Phase 5 | ⚪ offen |
| 13 | [Betrieb: Funktionskontrolle, Akku, Notfallplan](13-betrieb.md) | Phase 5 | ⚪ offen |
| 14 | [Fehlersuche](14-fehlersuche.md) | laufend | ⚪ offen |

Legende: 🟢 ausgearbeitet und getestet · 🟡 in Arbeit · ⚪ offen

## Aufbau jedes Kapitels

**Ziel → Voraussetzungen → Schritte → Prüfen → Typische Fehler**

Jedes Kapitel endet mit einer Prüfung, die zeigt, ob der Schritt wirklich funktioniert – nicht nur, ob er ausgeführt wurde.
