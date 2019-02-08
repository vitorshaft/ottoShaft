

#define FIREBASE_HOST "ottoshaft-b140c.firebaseio.com"
#define FIREBASE_AUTH "k7lJTEDS9bzRtPlN4FTHGcBJdqYywKXbYel8jpWO"
#define WIFI_SSID "DUARTE DOMINGUES"
#define WIFI_PASSWORD "recife2014"

#include <ESP8266WiFi.h>

#include <FirebaseArduino.h>


int LED1 = 2;

void setup()
{
Serial.begin(115200);

pinMode(LED1, OUTPUT);

  delay(2000);
  Serial.println('\n');
  
  wifiConnect();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  delay(10);
}

void loop()
{  
  
Serial.print(Firebase.getString("LED1") + "\n");

analogWrite(LED1, Firebase.getString("LED1").toInt());
delay(10);

String IPE;
if(WiFi.status() != WL_CONNECTED)
{
  wifiConnect();
  
//  IPE = String(WiFi.localIP());
}

Firebase.setString("/IP/AZneTrdO2qkVoXkBy1gI/IP","CONECTADO");
delay(10);

}

void wifiConnect()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID); Serial.println(" ...");

  int teller = 0;
  while (WiFi.status() != WL_CONNECTED)
  {                                       // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++teller); Serial.print(' ');
    digitalWrite(LED1, LOW);
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}
