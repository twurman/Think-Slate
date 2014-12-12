#include <SPI.h>
#include <boards.h>
#include <ble_shield.h>
#include <services.h>

const byte ledPin = 4;
const byte speakerOut = 4; /* This makes a standard old PC speaker connector fit nicely over the pins. */

int x1, x2 = 0, y1, y2 = 0, z1, z2 = 0;

byte readVal = 0x00;

void setup() {
  
//  ble_begin();
//  
//  pinMode(ledPin, OUTPUT); 
  pinMode(speakerOut, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
  x1 = analogRead(0);       // read analog input pin 0
  y1 = analogRead(1);       // read analog input pin 1
  z1 = analogRead(2);       // read analog input pin 1
  
  if(abs(x1 - x2) > 10 || abs(y1 - y2) > 10 || abs(z1 - z2) > 10) {
    x2 = x1;
    y2 = y1;
    z2 = z1;
    Serial.print("accelerations are x, y, z: ");
    Serial.print(x1, DEC);    // print the acceleration in the X axis
    Serial.print(" ");       // prints a space between the numbers
    Serial.print(y1, DEC);    // print the acceleration in the Y axis
    Serial.print(" ");       // prints a space between the numbers
    Serial.println(z1, DEC);  // print the acceleration in the Z axis
    //digitalWrite(ledPin, HIGH);
    
//    noTone(speakerOut);
//    tone(speakerOut, 440, 200);
//    noTone(speakerOut);
//    tone(speakerOut, 494, 500);
//    noTone(speakerOut);
//    tone(speakerOut, 523, 300);
    
  } else {
    //digitalWrite(ledPin, LOW);
    noTone(speakerOut);
  }
  
  delay(200);              // wait 100ms for next reading
  
//
//
//  if(ble_connected()){
//    digitalWrite(7,255);
//  }
//
//  
//  if(ble_available()){
//    readVal = ble_read();
//  }
//    
//    
//  if(readVal == 0x01){
//      //play song
//      if(thisNote >= 98){
//        thisNote = 0;
//      }
//
//    // to calculate the note duration, take one second
//    // divided by the note type.
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//    int noteDuration = 1000/noteDurations[thisNote];
//    tone(6, melody[thisNote],noteDuration);
//
//    // to distinguish the notes, set a minimum time between them.
//    // the note's duration + 30% seems to work well:
//    int pauseBetweenNotes = noteDuration * 1.30;
//    delay(pauseBetweenNotes);
//    // stop the tone playing:
//    noTone(6);
//    thisNote++;
//  } else {
//    thisNote = 0;
//  }
//
//  if (!ble_connected()){
//    readVal = 0x02;
//    digitalWrite(7, LOW);
//  }
//  
//  // Allow BLE Shield to send/receive data
//  ble_do_events();
//  //digitalWrite(RED, LOW);
}
