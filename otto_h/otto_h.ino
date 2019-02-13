/* Otto Shaft
 *  SHAFT ROBOTICA    https://instagram.com/shaftrobotica
  por VITOR DOMINGUES https://github.com/vitorshaft/

  09 fev 2019
*/

#include <Servo.h>
#include <Oscillator.h>
#include <Otto.h>
#include <Otto_gestures.h>

Otto Otto;

#define Dir0 4 //D2
#define Dir1 5 //D1
#define Esq0 0 //D3
#define Esq1 2 //D4

//  Servo Dir0,Dir1,E0,E1;
//  Dir0 = Direita perna
//  Dir1 = Direita pé
//  E0 = Esquerda perna
//  E1 = Esquerda pé



void setup() {
  Otto.init(Esq0,Dir0,Esq1,Dir1,false);
  Otto.home();
  delay(50);
  
//  Dir0.attach(4); // anexa servo Dir0 na porta GIO4 (D2)
//  Dir1.attach(5); // anexa servo Dir1 na porta GIO5 (D1)
//  E0.attach(0); // anexa servo E0 na porta GIO0 (D3)
//  E1.attach(2); // anexa servo E1 na porta GIO2 (D4)
}

void loop() {
  Otto.walk(2,1000,1);
  Otto.home();
}
