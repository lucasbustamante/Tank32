#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESP32Servo.h>

// Definições dos pinos
#define SERVO_PIN_LEFT 5  // Pino do servo da frente
#define SERVO_PIN_RIGHT 6 // Pino do servo de trás

// Definições da rede WiFi
const char *ssid = "ESP32-AP";
const char *password = "12345678";

// Criação dos servos
Servo servoLeft;
Servo servoRight;

// Criação do servidor web
AsyncWebServer server(80);

void setup() {
  // Inicialização dos servos
  servoLeft.attach(SERVO_PIN_LEFT);
  servoRight.attach(SERVO_PIN_RIGHT);

  // Configura os servos para a posição neutra (90 graus)
  servoLeft.write(90);
  servoRight.write(90);

  // Configuração do modo Access Point
  WiFi.softAP(ssid, password);
  Serial.begin(115200);
  Serial.println("Access Point criado");
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());

  // Rota para a página principal
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    String html = "<!DOCTYPE html><html><head><title>Controle de Servos</title></head><body>";
    html += "<h1>Controle dos Servo Motores</h1>";
    html += "<button onclick=\"sendData('left')\">Mover Esquerda</button>";
    html += "<button onclick=\"sendData('right')\">Mover Direita</button>";
    html += "<button onclick=\"sendData('neutral')\">Posição Neutra</button>";
    html += "<script>function sendData(action){fetch('/control?servo='+action);}</script>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  // Rota para o controle dos servos
  server.on("/control", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("servo")) {
      String servoAction = request->getParam("servo")->value();
      if (servoAction == "left") {
        servoLeft.write(45);   // Mover o servo da frente para a esquerda
        servoRight.write(135); // Mover o servo de trás para a direita
      } else if (servoAction == "right") {
        servoLeft.write(135);  // Mover o servo da frente para a direita
        servoRight.write(45);  // Mover o servo de trás para a esquerda
      } else if (servoAction == "neutral") {
        servoLeft.write(90);   // Voltar para a posição neutra
        servoRight.write(90);
      }
    }
    request->send(200, "text/plain", "OK");
  });

  // Inicia o servidor
  server.begin();
}

void loop() {
  // Não há necessidade de código aqui para este exemplo
}
