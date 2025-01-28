#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Definições do relé
#define RELAY_PIN 23

// Credenciais do Wi-Fi
char ssid[] = "NomeDaSuaRedeWiFi";
char pass[] = "SenhaDaSuaRedeWiFi";

// Blynk
char auth[] = "SeuAuthToken";

char localServer[] = "192.168.1.100"; // IP do seu servidor local
uint16_t localPort = 8080; // Porta padrão do Blynk Local Server

BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // Lê o valor do pino virtual V1
  digitalWrite(RELAY_PIN, pinValue); // Liga ou desliga o relé
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Inicialmente, desliga o relé

  Serial.println("Conectando ao Blynk Cloud...");
  if (Blynk.begin(auth, ssid, pass)) {
    Serial.println("Conectado ao Blynk Cloud!");
  } else {
    Serial.println("Falha ao conectar ao Blynk Cloud. Tentando servidor local...");
    Blynk.begin(auth, ssid, pass, localServer, localPort);
    Serial.println("Conectado ao Blynk Local Server!");
  }
}

void loop() {
  Blynk.run();
}