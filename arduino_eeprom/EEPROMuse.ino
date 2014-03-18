#include <EEPROM.h>

int stored;                                   //data stored in EEPROM
int address = 0;                              //location in EEPROM

void setup() {
  Serial.begin(9600);                         // sets up serial communication at 9600 bitss per second
  
  for (int count = 2; count < 8; count++) {   // initializes the digital pins as an outputs.
    pinMode(count, OUTPUT);
  }
  stored = EEPROM.read(address);              // reads the data stored in address 0 and assigns to variable
  Serial.println(stored);                     // Serial print the value
  stored++;                                   //increment value
  if (stored > 2) {                           //set this number based on how many different functions you want
    stored = 0;                              
  }
  EEPROM.write(address, stored);              //write the incremented value to EEPROM for next Arduino startup
}

void loop() {                                 //one of 3 functions runs based on stored EEPROM value
  if (stored == 0) {
    allblue();
  }

  if (stored == 1) {
    allred();
  }

  if (stored == 2) {
    everylight();
  }

}

void allblue() {                                          //functions use "for loop" to digitalWrite to every other light
  for (int count = 2; count < 8; count = count + 2) {
    digitalWrite(count, HIGH);
  }
  delay(50);
  for (int count = 2; count < 8; count = count + 2) {
    digitalWrite(count, LOW);
  }
  delay(50);
}

void allred() {
  for (int count = 3; count < 8; count = count + 2) {
    digitalWrite(count, HIGH);
  }
  delay(100);
  for (int count = 3; count < 8; count = count + 2) {
    digitalWrite(count, LOW);
  }
  delay(100);
}

void everylight() {
  for (int count = 2; count < 8; count++) {
    digitalWrite(count, HIGH);
  }
  delay(25);
  for (int count = 2; count < 8; count++) {
    digitalWrite(count, LOW);
  }
  delay(25);
}
