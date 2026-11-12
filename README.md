# NotfallbuttonLoRa

Diskreter tragbarer Alarmknopf (**NotfallbuttonLoRa Mini**) für eine allein arbeitende Person in einer Praxis. Stille SOS-Auslösung per Taster, Übertragung via LoRa an Gateways und lokale Alarmdienste, Benachrichtigung über Pushover mit Eskalation, Rückmeldung am Gerät ausschließlich per Vibration.

> **Status: Konzept / Prototyp.** Kein einsatzbereites oder zertifiziertes Sicherheitssystem und kein Ersatz für eine professionelle Überfall-/Hausnotrufanlage. Keine automatische Notrufabsetzung an 110/112.

## Dokumente

- [`CODE.md`](CODE.md) – Projektauftrag, Anforderungen, Phasen und Definition of Done
- [`CHANGELOG.md`](CHANGELOG.md) – Änderungshistorie
- [`docs/hardware-inventory.md`](docs/hardware-inventory.md) – Hardware-Inventur (Phase 0)

## Aktueller Stand

Phase 0 – Hardware verifizieren (in Arbeit). Boardrevision, LoRa-Chip und Frequenzvariante der vorhandenen Heltec WiFi LoRa 32 sind noch `OFFEN / ZU PRÜFEN`.

## Grundregeln

- Keine Zugangsdaten, Tokens, Telefonnummern, Standortdetails oder persönlichen Kontaktdaten im Repository. Konfiguration nur über Beispieldateien mit Platzhaltern.
- Keine erfundenen Hardwarewerte, Reichweiten oder Laufzeiten; Unbekanntes wird als `OFFEN / ZU MESSEN` markiert.
- Sendebetrieb erst nach Prüfung der zulässigen EU-868-MHz-Parameter (Frequenz, Duty Cycle, ERP).
