<p align="center">
  <img src="docs/images/banner.svg" alt="NotfallbuttonLoRa – stiller Alarmknopf für allein arbeitende Personen in der Praxis" width="100%">
</p>

<p align="center">
  <img alt="Status: Prototyp" src="https://img.shields.io/badge/Status-Prototyp-b26a00">
  <img alt="Phase 0: Hardware verifizieren" src="https://img.shields.io/badge/Phase%200-Hardware%20verifizieren-0b6e69">
  <img alt="Board: Heltec WiFi LoRa 32" src="https://img.shields.io/badge/Board-Heltec%20WiFi%20LoRa%2032-555">
  <img alt="Funk: EU-868 zu prüfen" src="https://img.shields.io/badge/Funk-EU--868%20zu%20pr%C3%BCfen-555">
  <img alt="Firmware: Arduino IDE" src="https://img.shields.io/badge/Firmware-Arduino%20IDE-00878F">
  <img alt="Gehäuse: 3D-Druck" src="https://img.shields.io/badge/Geh%C3%A4use-3D--Druck-555">
  <a href="LICENSE"><img alt="Lizenz: MIT" src="https://img.shields.io/badge/Lizenz-MIT-555"></a>
</p>

**NotfallbuttonLoRa Mini** ist ein diskreter, tragbarer Alarmknopf für eine allein arbeitende Person in einer Praxis. Ein 2 Sekunden langer Druck löst einen **stillen Alarm** aus. Der Alarm läuft per LoRa – unabhängig vom Praxis-WLAN – zu Gateways und lokalen Alarmdiensten, die Vertrauenspersonen über Pushover alarmieren und ohne Reaktion nach 180 Sekunden eskalieren. Rückmeldungen spürt die Trägerin ausschließlich als Vibration.

> [!WARNING]
> **Prototyp – kein zertifiziertes Sicherheitssystem.** Kein Ersatz für eine professionelle Überfall- oder Hausnotrufanlage, keine automatische Notrufabsetzung an 110/112, keine zugesicherte Verfügbarkeit oder Funkreichweite.

## Inhalt

- [Anleitung](#anleitung)
- [So funktioniert es](#so-funktioniert-es)
- [Bedienung](#bedienung)
- [Alarm und Eskalation](#alarm-und-eskalation)
- [Geräte](#geräte)
- [Gehäuse](#gehäuse)
- [Projektphasen](#projektphasen)
- [Repository](#repository)
- [Sicherheit und Datenschutz](#sicherheit-und-datenschutz)
- [Autor und Lizenz](#autor-und-lizenz)

## Anleitung

Die [**vollständige Nachbau-Anleitung**](docs/anleitung/README.md) führt durch das gesamte System: Notfallbuttons und Gateways, Gehäuse aus dem 3D-Drucker, Alarmdienst auf der Synology, n8n, Pushover, Tailscale und FRITZ!Box – bis zu Inbetriebnahme, Ausfalltests und täglichem Betrieb. Kapitel werden ausgearbeitet, sobald der jeweilige Teil aufgebaut und getestet ist.

## So funktioniert es

<p align="center">
  <img src="docs/images/architecture.svg" alt="Architektur: SOS-01 sendet per LoRa an GW-PRAXIS und optional GW-HOME; Gateways melden an Alarmdienste auf den Synology-NAS, verbunden über Tailscale; Pushover alarmiert Vertrauenspersonen; Quittierung läuft über einen Rückkanal zum Gerät" width="100%">
</p>

Durchgezogene Linien sind vorgesehene Wege, gestrichelte sind optional oder **noch nicht durch Messung belegt**. Ein LoRa-Paket am Praxis-Gateway ist noch keine externe Alarmierung: Fällt das Internet aus, sind Pushover und Tailscale nicht erreichbar. Wie dieser Fall abgesichert wird, ist eine [offene Entscheidung](CODE.md#14-offene-entscheidungen).

## Bedienung

<p align="center">
  <img src="docs/images/bedienung-vibration.svg" alt="Kurzer Druck: Display ca. 10 s an, kein Alarm. Druck ab 2 s: stiller SOS. Vibration 1× technisch empfangen, 2× persönlich quittiert, 3× noch nicht bestätigt" width="100%">
</p>

Das Display leuchtet bei einem Alarm **nicht** von selbst auf. Den Status zeigt es nur nach einem bewussten kurzen Druck – etwa `TECHNISCH EMPFANGEN` (ausdrücklich nicht „Hilfe unterwegs“) oder `PERSOENLICH QUITTIERT`.

## Alarm und Eskalation

<p align="center">
  <img src="docs/images/eskalation.svg" alt="Zeitleiste: SOS bei 0 s, technische Bestätigung, Pushover Priority 2 an Vertrauensperson 1, nach 180 s ohne persönliche Quittierung zusätzlich Vertrauensperson 2" width="100%">
</p>

Technische Zustellung und menschliche Reaktion werden strikt getrennt: Nur eine serverseitig geprüfte Pushover-Quittierung zählt als „persönlich quittiert“.

## Geräte

| Knoten | Ort | Rolle |
|---|---|---|
| `SOS-01` | bei der Trägerin | Akku-Sender, Taster, OLED, Vibration |
| `GW-PRAXIS` | Praxis | LoRa-Empfang + WLAN/LAN zur Praxis-Synology |
| `GW-HOME` | Zuhause | LoRa-Empfang + WLAN/LAN zur Heim-Synology – nur nach Funkstreckentest belastbar |
| `TEST-04` | variabel | Funktests, Debugging, Reserve |

Basis sind vier Heltec WiFi LoRa 32 mit Antennen. Revision, Funkchip und Frequenzvariante werden gerade erfasst: [Hardware-Inventur](docs/hardware-inventory.md).

## Gehäuse

Alle Geräte erhalten kleine, selbst entworfene Gehäuse für den 3D-Druck – der Mini mit großem, ertastbarem Taster, die Gateways für eine feste Montage mit gut platzierter Antenne. Quelldateien und druckfertige Dateien liegen künftig unter `hardware/enclosure/`. Maße werden ausschließlich an der echten Hardware gemessen.

## Projektphasen

| Phase | Inhalt | Stand |
|---|---|---|
| 0 | Hardware verifizieren | 🟡 in Arbeit |
| 1 | LoRa-Funklabor: Reichweite, RSSI/SNR, Paketverlust | ⚪ offen |
| 2 | Alarmprotokoll, Zustandsmaschine, Taster, Vibration | ⚪ offen |
| 3 | Gateways und NAS-Alarmdienste | ⚪ offen |
| 4 | Pushover, Eskalation, Rückkanal | ⚪ offen |
| 5 | Gehäuse, Miniaturisierung, Abnahme | ⚪ offen |

Details stehen im Projektauftrag [`CODE.md`](CODE.md), die aktuellen Arbeitsschritte im [`Arbeitsplan`](docs/arbeitsplan.md), Änderungen im [`CHANGELOG.md`](CHANGELOG.md).

## Repository

```text
NotfallbuttonLoRa/
├── CODE.md                    Projektauftrag und Anforderungen
├── CHANGELOG.md               Änderungshistorie
├── LICENSE                    MIT-Lizenz
├── docs/
│   ├── anleitung/             Nachbau-Anleitung für das gesamte System
│   ├── arbeitsplan.md         freigegebene Arbeitsschritte mit Stand
│   ├── hardware-inventory.md  Erfassungsbogen Phase 0
│   └── images/                Grafiken (SVG, hell/dunkel) und Fotos
└── firmware/
    └── hw-probe/              ESP32-Info-Sketch zur Board-Erfassung
```

Weitere Ordner (`services/`, `hardware/enclosure/`, `tests/` …) entstehen mit den jeweiligen Phasen.

## Sicherheit und Datenschutz

- Keine Zugangsdaten, Tokens, Telefonnummern, Standortdetails oder Kontaktdaten im Repository – nur Beispieldateien mit Platzhaltern.
- Fotos werden vor dem Einchecken von Metadaten (EXIF/GPS) befreit; Seriennummern und Adressen sind nicht erkennbar.
- Keine erfundenen Messwerte: Unbelegtes ist als `OFFEN / ZU MESSEN` gekennzeichnet, Diagramme zeigen nur echte Messungen.
- Sendebetrieb erst nach Prüfung der zulässigen EU-868-MHz-Parameter (Frequenz, Duty Cycle, ERP).

## Autor und Lizenz

**[lindekai](https://github.com/lindekai)** – Konzept, Hardware und Entwicklung.

Veröffentlicht unter der [MIT-Lizenz](LICENSE). Die Lizenz schließt jede Gewährleistung aus; das gilt hier ausdrücklich auch für die Eignung als Sicherheits- oder Notrufsystem.
