#define trig 13
#define echo 12

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  double tempo, dist;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  tempo = pulseIn(echo, HIGH);
  dist = (tempo/2)*0.03;
  if(dist < 400){
    Serial.println(dist);
  }
  //Serial.println(dist);
  delay(100);
}
