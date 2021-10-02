// @Author Salvador Puertes
// @Description Simple termometer with Arduino UNO, LM35 sensor and display 4 digits 7 segments.

// Display segments
int pin_A = 2;
int pin_B = 3;
int pin_C = 4;
int pin_D = 5;
int pin_E = 6;
int pin_F = 7;
int pin_G = 8; 
int pin_H = 9; // dot

int pin_hundres = 13; // Hundreds
int pin_tens = 12; // Tens
int pin_units = 11; // Units
int pin_decimals = 10; // Decimals

float temperature;

void setup() {
  Serial.begin(9600);

 // Display digits GND configuration
 pinMode(pin_hundres, OUTPUT);
 pinMode(pin_tens, OUTPUT);
 pinMode(pin_units, OUTPUT);
 pinMode(pin_decimals,OUTPUT);

 // Display segments configuration
  pinMode(pin_A,OUTPUT);
  pinMode(pin_B,OUTPUT);
  pinMode(pin_C,OUTPUT);
  pinMode(pin_D,OUTPUT);
  pinMode(pin_E,OUTPUT);
  pinMode(pin_F,OUTPUT);
  pinMode(pin_G,OUTPUT);
  pinMode(pin_H,OUTPUT);
 }

void loop() {

 temperature = ((analogRead(1) - analogRead(0))*500)/1023.0;

 Serial.println(temperature);  

 delay(5000);
}
