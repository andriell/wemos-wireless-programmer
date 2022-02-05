#define SETTINGS_SIZE 512

String settingsSave() {
  StaticJsonDocument<SETTINGS_SIZE> doc;
  doc["m"] = s6s.mode;
  String jsonString;
  int jsonLenght = serializeJson(doc, jsonString);
  if (jsonLenght == 0 ) {
    dbgLn(1, "Error saving settings");
  }
  File file = SPIFFS.open("/settings.json", "w");
  int bytesWritten = file.print(jsonString);
  file.close();
  if (bytesWritten == 0 ) {
    dbgLn(1, "Error saving settings");
  }
  dbg(1, "Saving settings: ");
  dbgLn(1, jsonString);
}

void settingsLoadFile() {
  File file = SPIFFS.open("/settings.json", "r");
  String jsonString = file.readString();
  file.close();
  settingsLoadString(jsonString);
}

void settingsLoadString(String jsonString) {
  StaticJsonDocument<SETTINGS_SIZE> doc;
  DeserializationError error = deserializeJson(doc, jsonString);
  if (error) {
    dbg(1, "Error deserialization settings: ");
    dbgLn(1, jsonString);
    return;
  }
  dbg(1, "Load settings: ");
  dbgLn(1, jsonString);

  if (doc.containsKey("m")) {
    s6s.mode = doc["m"];
  } else {
    s6s.mode = 1;
  }
}
