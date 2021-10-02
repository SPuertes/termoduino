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
int pin_H = 9;

int pin_hundres = 13; // Hundreds
int pin_tens = 12; // Tens
int pin_units = 11; // Units
int pin_decimals = 10; // Decimals

float temperature;

void setup() {
  Serial.begin(9600);
  }

void loop() {

 temperature = ((analogRead(1) - analogRead(0))*500)/1023.0;

 Serial.println(temperature);  

 delay(5000);
}
