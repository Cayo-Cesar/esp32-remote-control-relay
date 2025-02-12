const int RELAY_PIN = 21;
const int LED_RED = 18;
const int LED_GREEN = 5;
const int BUTTON = 19;

int lastButtonState = LOW;
int relayState = LOW; // O relé começa DESLIGADO
unsigned long lastDebounceTime = 0;
const int debounceDelay = 50; // Tempo para evitar ruído no botão

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLDOWN);  // Ativa o pull-down interno

  // Se o relé for "Active Low", começa desligado
  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
  int buttonState = digitalRead(BUTTON);

  if (buttonState == HIGH && lastButtonState == LOW) {
    if (millis() - lastDebounceTime > debounceDelay) { // Aplica debounce
      relayState = !relayState;

      if (relayState == HIGH) {
        digitalWrite(RELAY_PIN, LOW);  // Liga o relé (se Active Low)
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, LOW);
      } else {
        digitalWrite(RELAY_PIN, HIGH);  // Desliga o relé (se Active Low)
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_RED, HIGH);
      }

      lastDebounceTime = millis(); // Atualiza tempo do debounce
    }

    while (digitalRead(BUTTON) == HIGH) {} // Aguarda soltar o botão
  }

  lastButtonState = buttonState;
}
