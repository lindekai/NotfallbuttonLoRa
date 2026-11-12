# Changelog

Alle relevanten Änderungen an diesem Projekt werden hier dokumentiert.
Format angelehnt an [Keep a Changelog](https://keepachangelog.com/de/1.1.0/).

## [Unveröffentlicht]

### Hinzugefügt
- Projektauftrag `CODE.md` (vormals `NotfallbuttonLoRa_CODE.md`, Stand 2026-11-12).
- `README.md` mit Projektzweck, Status und Grundregeln.
- `.gitignore` für macOS-Dateien, Secrets, lokale Konfiguration und Build-Artefakte.
- `CHANGELOG.md`.
- `docs/hardware-inventory.md`: Erfassungsbogen für Phase 0 mit Sicherheitshinweisen, Identifikationsmerkmalen und Tabelle je Board (alle Werte `OFFEN`).
- Grafiken unter `docs/images/` (SVG, automatisch hell/dunkel): Banner, Architektur, Bedienung und Vibrationsmuster, Alarm- und Eskalationsablauf.
- `CODE.md` §16: Ergänzungen zu 3D-druckbaren Gehäusen, Darstellung im Repository und Autorschaft.
- Hardware-Inventur um 3D-Drucker ergänzt.
- `LICENSE`: MIT-Lizenz.
- `firmware/hw-probe/`: board-unabhängiger ESP32-Info-Sketch für Phase 0 (keine GPIOs, kein Funk) mit Flash- und Ausleseanleitung; noch nicht kompiliert/getestet.

- `docs/anleitung/`: Gerüst der Nachbau-Anleitung für das gesamte System (Kapitel 00–14), Kapitel 00 Überblick in erster Fassung.
- `CODE.md` §16: vollständige Nachbau-Anleitung als Projektbestandteil.

### Geändert
- `README.md` neu gestaltet: Banner, Status-Badges, eingebundene Grafiken, Geräte, Gehäuse, Phasenübersicht, Autor.
