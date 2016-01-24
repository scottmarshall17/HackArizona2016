#include <CapacitiveSensor.h>

#define DEBUG 0

CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);
CapacitiveSensor cs_4_5 = CapacitiveSensor(4, 5);
CapacitiveSensor cs_6_7 = CapacitiveSensor(6, 7);
CapacitiveSensor cs_8_9 = CapacitiveSensor(8,9);
CapacitiveSensor cs_10_11 = CapacitiveSensor(10,11);

int on_1 = 0;
int on_2 = 0;
int on_3 = 0;
int on_4 = 0;
int on_5 = 0;

void setup() {
  // put your setup code here, to run once:
  cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_6_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_8_9.set_CS_AutocaL_Millis(0xFFFFFFFF);
  cs_10_11.set_CS_AutocaL_Millis(0xFFFFFFFF);
  
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
    //long start = millis();
    long total1 = cs_2_3.capacitiveSensor(30);
    long total2 = cs_4_5.capacitiveSensor(30);
    long total3 = cs_6_7.capacitiveSensor(30);
    long total4 = cs_8_9.capacitiveSensor(30);
    long total5 = cs_10_11.capacitiveSensor(30);
    
    /*
    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\n");                    // tab character for debug window spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.print("\n");
    */

    //Below is the code for channel 1 -------------------------------
    if(total1 > 35 && on_1 == 0) {
      digitalWrite(13, HIGH);
      Serial.write(0b10010000);   //Note ON event, Channel 1
      Serial.write(0b01000011);   //Play middle C, Key number 60//////////////////////////////////////////Nick Modified this value- Previous:0b00111100
      Serial.write(0b01111111);   //Play at maximum
      on_1 = 1;
    }
    else if(total1 > 35 && on_1 != 0) {
      on_1 = 1;
    }
    else if(total1 <= 35 && on_1 != 0){
      digitalWrite(13, LOW);
      Serial.write(0b10000000);   //Note OFF event, Channel 1
      Serial.write(0b01000011);   //Play middle C, Key number 60//////////////////////////////////////////Nick Modified this value- Previous:0b00111100
      Serial.write(0b01111111);   //Play at maximum
      on_1 = 0;
    }
    else if(total1 <= 35 && on_1 == 0){
      on_1 = 0;
    }

    //Below is the code for channel 2 -------------------------------
    if(total2 > 35 && on_2 == 0) {
      digitalWrite(13, HIGH);
      Serial.write(0b10010001);   //Note ON event, Channel 1
      Serial.write(0b00111100);   //Play middle C, Key number 60
      Serial.write(0b01111111);   //Play at maximum
      on_2 = 1;
    }
    else if(total2 > 35 && on_2 != 0) {
      on_2 = 1;
    }
    else if(total2 <= 35 && on_2 != 0){
      digitalWrite(13, LOW);
      Serial.write(0b10000001);   //Note OFF event, Channel 1
      Serial.write(0b00111100);   //Play middle C, Key number 60
      Serial.write(0b01111111);   //Play at maximum
      on_2 = 0;
    }
    else if(total2 <= 35 && on_2 == 0){
      on_2 = 0;
    }

    //Below is the code for channel 3 ----------------------------
    if(total3 > 35 && on_3 == 0) {
      digitalWrite(13, HIGH);
      Serial.write(0b10010010);   //Note ON event, Channel 3
      Serial.write(0b01000100);   //Play middle C, Key number 60
      Serial.write(0b01111111);   //Play at maximum
      on_3 = 1;
    }
    else if(total3 > 35 && on_3 != 0) {
      on_3 = 1;
    }
    else if(total3 <= 35 && on_3 != 0){
      digitalWrite(13, LOW);
      Serial.write(0b10000010);   //Note OFF event, Channel 3
      Serial.write(0b01000100);   //Play middle C, Key number 60
      Serial.write(0b01111111);   //Play at maximum
      on_3 = 0;
    }
    else if(total3 <= 35 && on_3 == 0){
      on_3 = 0;
    }
///////////////////////////////////////////////Place code loop logic here for cans 4 and 5/////////////////////////////////////////////////////////
    //Below is the code for channel 4 ----------------------------
    if(total4 > 35 && on_4 == 0) {
      digitalWrite(13, HIGH);
      Serial.write(0b10010011);   //Note ON event, Channel 4
      Serial.write(0b01000100);   //Play middle C, Key number 60
      Serial.write(0b01111111);   //Play at maximum
      on_4 = 1;
    }
    else if(total4 > 35 && on_4 != 0) {
      on_4 = 1;
    }
    else if(total4 <= 35 && on_4 != 0){
      digitalWrite(13, LOW);
      Serial.write(0b10000011);   //Note OFF event, Channel 4
      Serial.write(0b01000100);   //Play middle C, Key number 60
      Serial.write(0b01111111);   //Play at maximum
      on_4 = 0;
    }
    else if(total4 <= 35 && on_4 == 0){
      on_4 = 0;
    }

    //////////////// Can 5

        //Below is the code for channel 5 ----------------------------
    if(total5 > 35 && on_5 == 0) {
      digitalWrite(13, HIGH);
      Serial.write(0b10010101);   //Note ON event, Channel 6
      Serial.write(0b01000100);   //Play middle C, Key number 60
      Serial.write(0b01111111);   //Play at maximum
      on_5 = 1;
    }
    else if(total5 > 35 && on_5 != 0) {
      on_5 = 1;
    }
    else if(total5 <= 35 && on_5 != 0){
      digitalWrite(13, LOW);
      Serial.write(0b10000101);   //Note OFF event, Channel 6
      Serial.write(0b01000100);   //Play middle C, Key number 60
      Serial.write(0b01111111);   //Play at maximum
      on_5 = 0;
    }
    else if(total5 <= 35 && on_5 == 0){
      on_5 = 0;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if DEBUG
  Serial.println(total1);
  Serial.println(total2);
  Serial.println(total3);
  Serial.println(total4);
  Serial.print(total5);
  Serial.print("\n\n");
  delay(100);
#else
  delay(5);
#endif                             // arbitrary delay to limit data to serial port... works with 10 at 115200 baud
}
