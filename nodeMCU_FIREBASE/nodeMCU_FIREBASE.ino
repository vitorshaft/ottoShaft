#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <SerialTransceiver.h>
#include <Thing.h>

#define FIREBASE_HOST "ottoshaft-b140c.firebaseio.com"
#define FIREBASE_AUTH "k7lJTEDS9bzRtPlN4FTHGcBJdqYywKXbYel8jpWO"
#define WIFI_SSID "DUARTE DOMINGUES"

#define WIFI_PASSWORD "recife2014"

#define LED 2

void setup() {

pinMode(LED,OUTPUT);

digitalWrite(LED,0);

Serial.begin(9600);

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

Firebase.setInt("LEDStatus",0);

}

void loop() {

if(Firebase.getInt("LEDStatus"))

{

digitalWrite(LED,HIGH);

}

else

{

digitalWrite(LED,LOW);

}

if (Firebase.failed()) // Check for errors {

Serial.print("setting /number failed:");

Serial.println(Firebase.error());

return;

}

delay(1000);

}
