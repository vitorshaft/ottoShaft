//
// Shaft Robotica
// 08 fev 2019
// Vitor Domingues
// github.com/vitorshaft
// instagram.com/shaftrobotica
// vtrshaft@gmail.com
//
// código adaptado a partir do FirebaseDemo_ESP8266.ino. Copyright 2015 Google Inc.
// Licença Apache versão 2.0


#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// configuração de rede e acesso ao Firebase
#define FIREBASE_HOST "bancodedados.firebaseio.com"
#define FIREBASE_AUTH "INSIRA A CHAVE AQUI"
#define WIFI_SSID "SSID da rede WiFi"
#define WIFI_PASSWORD "senhadoWiFi"

void setup() {
  Serial.begin(9600);

  // conecta ao WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  // Firebase.begin(FIREBASE_HOST);
}

int n = 0;

void loop() {
  // envia valor Float a "number"
  Firebase.setFloat("number", 42.0);
  // em caso de erro
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // atualiza valor de "number"
  Firebase.setFloat("number", 43.0);
  // em caso de erro ...
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // get value 
  Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);

  // remove value
  Firebase.remove("number");
  delay(1000);

  // set string value
  Firebase.setString("message", "hello world");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // set bool value
  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // insere valor Int a "logs"
  String name = Firebase.pushInt("logs", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name);
  delay(1000);
}
