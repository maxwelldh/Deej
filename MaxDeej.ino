const int NUM_SLIDERS = 7;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2, A3, A4, A5, A6};
/*
 * Based on the example code from the Deej project
 * https://github.com/omriharel/deej
 * "Mute LEDs" are still not programmed to change color when muted BUT they do work enough to look good
 */


#include "Keyboard.h"
#include <PololuLedStrip.h>

PololuLedStrip<13> ledStrip;

#define LED_COUNT 7

rgb_color colors[LED_COUNT];

int analogSliderValues[NUM_SLIDERS];

void setup() { 
  for (int i = 0; i < NUM_SLIDERS; i++) {
  pinMode(analogInputs[i], INPUT);
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Keyboard.begin();
  }

  Serial.begin(9600);
}



void loop() {
  updateSliderValues();
  sendSliderValues(); // Actually send data (all the time)
  // printSliderValues(); // For debug
  delay(10);
  rgb_color color;
      color.red = 20;
      color.green = 0;
      color.blue = 0;

      // Update the colors buffer.
      for(uint16_t i = 0; i < LED_COUNT; i++)
      {
        colors[i] = color;
      }

      // Write to the LED strip.
      ledStrip.write(colors, LED_COUNT);

      Serial.print("Showing color: ");
      Serial.print(color.red);
      Serial.print(",");
      Serial.print(color.green);
      Serial.print(",");
      Serial.println(color.blue);
   if (digitalRead(0) == LOW){
    Keyboard.press(KEY_F13);
    delay(20);
    Keyboard.releaseAll();
    delay(80);
   }
   if (digitalRead(1) == LOW){
    Keyboard.press(KEY_F14);
    delay(20);
    Keyboard.releaseAll();
    delay(80);
   }
   if (digitalRead(2) == LOW){
    Keyboard.press(KEY_F15);
    delay(20);
    Keyboard.releaseAll();
    delay(80);
   }
   if (digitalRead(3) == LOW){
    Keyboard.press(KEY_F16);
    delay(20);
    Keyboard.releaseAll();
    delay(80);
   }
   if (digitalRead(5) == LOW){
    Keyboard.press(KEY_F17);
    delay(20);
    Keyboard.releaseAll();
    delay(80);
   }
   if (digitalRead(6) == LOW){
    Keyboard.press(KEY_F18);
    delay(20);
    Keyboard.releaseAll();
    delay(80);
   }
   if (digitalRead(7) == LOW){
    Keyboard.press(KEY_F19);
    delay(20);
    Keyboard.releaseAll();
    delay(80);
   }
}

void updateSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
     analogSliderValues[i] = analogRead(analogInputs[i]);
  }
}

void sendSliderValues() {
  String builtString = String("");

  for (int i = 0; i < NUM_SLIDERS; i++) {
    builtString += String((int)analogSliderValues[i]);

    if (i < NUM_SLIDERS - 1) {
      builtString += String("|");
    }
  }
  
  Serial.println(builtString);
}

void printSliderValues() {
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String printedString = String("Slider #") + String(i + 1) + String(": ") + String(analogSliderValues[i]) + String(" mV");
    Serial.write(printedString.c_str());

    if (i < NUM_SLIDERS - 1) {
      Serial.write(" | ");
    } else {
      Serial.write("\n");
    }
  }
}
