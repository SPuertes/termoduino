
float tension;
float escala = 250; // 2,5mV

void setup() {
  Serial.begin(9600);
  //analogReference(EXTERNAL);
}

void loop() {

 Serial.print("V in: ");
 
 tension = analogRead(0);
 
 Serial.print((tension*5)/1023);
 Serial.println("V");

 delay(500);
}
