int firstSensor = 0;    // first analog sensor, initial value
int secondSensor = 0;    // digital sensor, initial value
int inByte = 0;         // incoming serial byte

void setup() {
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  while(!Serial){
    ;;
  }

  pinMode(19, INPUT);   // digital sensor is on Pi Pico GPIO 19
  establishContact();  // send a byte to establish contact until receiver responds
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    
    // get incoming byte:
    inByte = Serial.read();
    
    // read first analog input:
    firstSensor = analogRead(A0);
    
    // read switch value
    secondSensor = digitalRead(19);
    
    // send sensor values:
    Serial.print(firstSensor);
    Serial.print(",");
    Serial.println(secondSensor);
  }
  
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("0,0");   // send an initial string
    delay(300);
  }
}