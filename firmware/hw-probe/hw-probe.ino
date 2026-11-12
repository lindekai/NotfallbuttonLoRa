// NotfallbuttonLoRa – hw-probe
//
// Board-unabhängiger Info-Sketch für Phase 0 (Hardware verifizieren).
// Gibt ausschließlich Daten des ESP32 über die serielle Schnittstelle aus.
//
// Bewusst NICHT enthalten:
//   - keine GPIO-Zugriffe (auch keine LED, kein OLED, kein Vext)
//   - kein LoRa, kein WLAN, kein Bluetooth – es wird nichts gesendet
//
// Voraussetzung: Arduino-ESP32-Core ab Version 2.0 (Espressif).
// Board-Auswahl: "ESP32 Dev Module" (Details: README.md in diesem Ordner).
// Serieller Monitor: 115200 Baud.

#include <Arduino.h>
#include <esp_system.h>

static const uint32_t SERIAL_BAUD = 115200;
static const uint32_t REPORT_INTERVAL_MS = 5000;

static const char *resetReasonText(esp_reset_reason_t reason) {
  switch (reason) {
    case ESP_RST_POWERON:   return "POWERON";
    case ESP_RST_EXT:       return "EXT";
    case ESP_RST_SW:        return "SW";
    case ESP_RST_PANIC:     return "PANIC";
    case ESP_RST_INT_WDT:   return "INT_WDT";
    case ESP_RST_TASK_WDT:  return "TASK_WDT";
    case ESP_RST_WDT:       return "WDT";
    case ESP_RST_DEEPSLEEP: return "DEEPSLEEP";
    case ESP_RST_BROWNOUT:  return "BROWNOUT";
    case ESP_RST_SDIO:      return "SDIO";
    default:                return "UNKNOWN";
  }
}

static void printReport() {
  // Nur die letzten 3 MAC-Bytes ausgeben: reicht zur Unterscheidung der Boards
  // und gehört so in die Inventur (docs/hardware-inventory.md).
  const uint64_t mac = ESP.getEfuseMac();
  const uint8_t mac3 = (mac >> 24) & 0xFF;
  const uint8_t mac4 = (mac >> 32) & 0xFF;
  const uint8_t mac5 = (mac >> 40) & 0xFF;

  Serial.println();
  Serial.println(F("=== NotfallbuttonLoRa hw-probe ==="));
  Serial.printf("Chipmodell:      %s\n", ESP.getChipModel());
  Serial.printf("Chip-Revision:   %u\n", (unsigned)ESP.getChipRevision());
  Serial.printf("CPU-Kerne:       %u\n", (unsigned)ESP.getChipCores());
  Serial.printf("CPU-Takt:        %u MHz\n", (unsigned)ESP.getCpuFreqMHz());
  Serial.printf("Flashgroesse:    %u MB\n", (unsigned)(ESP.getFlashChipSize() / (1024UL * 1024UL)));
  Serial.printf("Flashtakt:       %u MHz\n", (unsigned)(ESP.getFlashChipSpeed() / 1000000UL));
  Serial.printf("PSRAM:           %u KB\n", (unsigned)(ESP.getPsramSize() / 1024UL));
  Serial.printf("MAC (letzte 3):  %02X:%02X:%02X\n", mac3, mac4, mac5);
  Serial.printf("Reset-Grund:     %s\n", resetReasonText(esp_reset_reason()));
  Serial.printf("ESP-IDF/SDK:     %s\n", ESP.getSdkVersion());
#ifdef ESP_ARDUINO_VERSION_MAJOR
  Serial.printf("Arduino-Core:    %d.%d.%d\n", ESP_ARDUINO_VERSION_MAJOR, ESP_ARDUINO_VERSION_MINOR,
                ESP_ARDUINO_VERSION_PATCH);
#else
  Serial.println(F("Arduino-Core:    unbekannt (vor 2.0)"));
#endif
  Serial.printf("Laufzeit:        %lu s\n", (unsigned long)(millis() / 1000UL));
  Serial.println(F("=================================="));
}

void setup() {
  Serial.begin(SERIAL_BAUD);
  delay(1000);  // Zeit zum Öffnen des seriellen Monitors
  printReport();
}

void loop() {
  // Bericht wiederholen, damit er auch bei spät geöffnetem Monitor sichtbar ist.
  static uint32_t lastReport = 0;
  if (millis() - lastReport >= REPORT_INTERVAL_MS) {
    lastReport = millis();
    printReport();
  }
}
