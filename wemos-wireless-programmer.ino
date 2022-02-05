#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <Wire.h>
#include "SH1106Wire.h" // Library: ESP8266 and ESP32 OLED driver for SSD1306 displays
#include <ArduinoJson.h> // Library: ArduinoJson
#include "const.h"
#include <RCSwitch2.h> // Скопировать из lib/rc-switch2 в папку скетчей Arduino

#define WEMOS_A0     17
#define WEMOS_D0     16
#define WEMOS_D1     5
#define WEMOS_D2     4
#define WEMOS_D3     0
#define WEMOS_D4_LED 2
#define WEMOS_D5     14
#define WEMOS_D6     12
#define WEMOS_D7     13
#define WEMOS_D8     15
#define WEMOS_TX     1
#define WEMOS_RX     3

/**
 * Подключение
 * 
 * RC 433
 * VCC  - +5v
 * GND  - GND
 * DATA - D2
 * 
 * RC 315
 * VCC  - +5v
 * GND  - GND
 * DATA - D3
 */


struct Settings {
  int mode; // m
};

 // s6s is settings like i18n is internationalization
Settings s6s;

void setup() {
  wemosSetup();
  beepSetup();
  liionSetup();
  wsSetup();
  rcSetup();
  #if defined( __AVR_ATtinyX5__ ) or defined ( __AVR_ATtinyX4__ )
    Serial.println("defined( __AVR_ATtinyX5__ ) or defined ( __AVR_ATtinyX4__ )");
  #endif
}

void loop() {
  srLoop();
  dbgLoop();
  rcLoop();
  wsLoop();
}
