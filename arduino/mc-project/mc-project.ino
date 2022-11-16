#include <dht.h>

#define outPinDHT 22  // номер піна, до якого під’єднаний датчик
dht DHT;  


float oldTemp = 0; // ініціалізація змінних
float oldHum = 0;

const int buttonPin1 = 20; // ініціалізація констант
const int buttonPin2 = 21; 
const int led = 30;

int val1;
int val2;
int on;

ISR(INT0_vect){ // переривання
on = 0;
}

void setup() {
Serial.begin(9600); // підключення COM-port`а 

noInterrupts();
EIMSK |= (1<<INT0);	//
EICRA &= ~(1<<ISC00); // блок переривання
EICRA |= (1 <<ISC01); //

interrupts(); // дозволяємо переривання

DDRC = 0x0F; // ініціалізуємо порти
DDRC |= (1<<7);

pinMode(buttonPin1, INPUT_PULLUP); // ініціалізуємо кнопку на вихід
digitalWrite(buttonPin1, HIGH); // даємо високу напргу і відповідно коли
                                // вона буде натиснутою, напруга буде низькою
pinMode(buttonPin2, INPUT_PULLUP); digitalWrite(buttonPin2, HIGH);

}


void loop() {
  int readData = DHT.read11(outPinDHT);
  int t = DHT.temperature;  
  int h = DHT.humidity; 
  
  if (t != oldTemp || h != oldHum) { 
    
    Serial.print("COM request");
    Serial.print("    ");
    Serial.print("Temperature is : ");
    Serial.print(t);
    Serial.print(" C");
    Serial.print("    ");    
    Serial.print("Humidity is : ");
    Serial.print(h);
    Serial.print(" %");
    Serial.println("");

    oldTemp = t;
    oldHum = h;
  }
  
  val1 = digitalRead(buttonPin1);
  val2 = digitalRead(buttonPin2);

  int byte = Serial.read();
  if (byte == 11) {
    val1 = LOW;
  }
  
  if (val1 == LOW) {
    on = 1;
  }
  
  while (on == 1) {
      int byte = Serial.read();
      if (byte == 12) {
        val1 = HIGH;
      }
      if (val1 == HIGH) {
         on =0;
      }
      PORTC = 0b00000001;
      delay(200);
      PORTC = 0b00000100;
      delay(200);
      PORTC = 0b00001000;
      delay(200); 
      PORTC = 0b00000010;
      delay(200);
  }
  if (on == 0) {
    digitalWrite(led, HIGH);
  }
}
