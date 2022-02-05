const int BUZZER_PIN = WEMOS_D4_LED;

void beepSetup() {
  pinMode(BUZZER_PIN, OUTPUT);
  tone(BUZZER_PIN, 2000, 100);
}
