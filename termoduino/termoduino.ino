// @Author Salvador Puertes
// @Description Simple termometer with Arduino UNO, LM35 sensor and display 4 digits 7 segments.

// Display segments
const int pin_A = 2;
const int pin_B = 3;
const int pin_C = 4;
const int pin_D = 5;
const int pin_E = 6;
const int pin_F = 7;
const int pin_G = 8; 
const int pin_H = 9; // dot

const int pin_hundres = 13; // Hundres
const int pin_tens = 12; // Tens
const int pin_units = 11; // Units
const int pin_decimals = 10; // Decimals

float temperature;
String numberString;

const int minus_symbol = 10;

int counter = 1000;

int numbers[11][7] = { // A,B,C,D,E,F,G
    {1,1,1,0,1,1,1}, // 0
    {0,0,0,0,0,1,1}, // 1
    {0,1,1,1,1,1,0}, // 2
    {0,0,1,1,1,1,1}, // 3
    {1,0,0,1,0,1,1}, // 4
    {1,0,1,1,1,0,1}, // 5
    {1,1,1,1,1,0,1}, // 6
    {0,0,1,0,0,1,1}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,0,1,1,1,1,1}, // 9
    {0,0,0,1,0,0,0} // -
  };

void setup() {
 // Display digits GND configuration
 pinMode(pin_hundres, OUTPUT);
 pinMode(pin_tens, OUTPUT);
 pinMode(pin_units, OUTPUT);
 pinMode(pin_decimals, OUTPUT);

 // Display segments configuration
 pinMode(pin_A, OUTPUT);
 pinMode(pin_B, OUTPUT);
 pinMode(pin_C, OUTPUT);
 pinMode(pin_D, OUTPUT);
 pinMode(pin_E, OUTPUT);
 pinMode(pin_F, OUTPUT);
 pinMode(pin_G, OUTPUT);
 pinMode(pin_H, OUTPUT); 
}

void loop() {

 if(counter == 1000){
  counter = -1;
  temperature = ((analogRead(1) - analogRead(0)) * 500) / 1023.0;
 }

 printNumber(temperature);
  
 counter++;
}

void printNumber(float temperature){
 int digit;
   
 if(temperature < 0){
  printDigit(minus_symbol, pin_hundres);
 }

 digit = temperature / 100;
 temperature = temperature - (digit * 100.0);
 if(digit > 0){
  printDigit(digit, pin_hundres);
 }

 digit = temperature / 10;
 temperature = temperature - (digit * 10.0);
 if(digit > 0){
  printDigit(digit, pin_tens);
 }

 digit = temperature / 1; // equal to floor(temperature)
 temperature = (temperature * 10) - digit * 10;
 
 digitalWrite(pin_H, HIGH);
 printDigit(digit, pin_units);
 digitalWrite(pin_H, LOW);

 printDigit(floor(temperature), pin_decimals);

}

void printDigit(int number, int digit){
  resetNumbers(); 

  digitalWrite(pin_A, numbers[number][0]);
  digitalWrite(pin_B, numbers[number][1]);
  digitalWrite(pin_C, numbers[number][2]);
  digitalWrite(pin_D, numbers[number][3]);
  digitalWrite(pin_E, numbers[number][4]);
  digitalWrite(pin_F, numbers[number][5]);
  digitalWrite(pin_G, numbers[number][6]);
  
  digitalWrite(digit, LOW);

  delay(2); // time to no overlap
}

void resetNumbers(){
  digitalWrite(pin_hundres, HIGH);
  digitalWrite(pin_tens, HIGH);
  digitalWrite(pin_units, HIGH);
  digitalWrite(pin_decimals, HIGH);
}
