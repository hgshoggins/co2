/*
    Licence Creative Commons :  CC-BY-NC
    https://creativecommons.org/licenses/by-nc/2.0/fr/
    
    Auteur    : Alain GODON
    Courriel  : alain.godon@univ-angers.fr
    Création  : Novembre 2020
*/

#include "co2rgb.h"

CO2RGB::CO2RGB(int low, int med, int high) {
  m_low = low;
  m_med = med;
  m_high = high;
  // configure LED PWM functionalitites
  ledcSetup(redChannel, freq, resolution);
  ledcSetup(greenChannel, freq, resolution);
  ledcSetup(blueChannel, freq, resolution);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(redPin, redChannel);
  ledcAttachPin(greenPin, greenChannel);
  ledcAttachPin(bluePin, blueChannel);
  pinMode(commPin, OUTPUT);
  digitalWrite(commPin, commState);
}

void CO2RGB::SetColor(float v) {
  if(v < m_low) {
    ledGreen();
  } else {
    if(v < m_med) {
      ledYellow();
    } else {
      if(v < m_high) {
        ledOrange();
      } else {
        ledRed();
      }
    }
  }
}

void CO2RGB::Sequence(void) {
  ledOff();
  delay(1000);
  ledGreen();
  delay(1000);
  ledYellow();
  delay(1000);
  ledOrange();
  delay(1000);
  ledRed();
  delay(1000);
  ledOff();
  delay(1000);
}

void CO2RGB::System(void){
  for(int i=0 ; i<5;i++) {
    ledOff();
    delay(500);
    ledBlue();
    delay(500);
  }
}

void CO2RGB::ledOff() {
  ledcWrite(blueChannel, LEDOFF);
  ledcWrite(greenChannel, LEDOFF);
  ledcWrite(redChannel, LEDOFF);
}
void CO2RGB::ledBlue() {
  ledcWrite(blueChannel, LEDON);
  ledcWrite(greenChannel, LEDOFF);
  ledcWrite(redChannel, LEDOFF);
}
void CO2RGB::ledGreen() {
  ledcWrite(blueChannel, LEDOFF);
  ledcWrite(greenChannel, LEDON);
  ledcWrite(redChannel, LEDOFF);
}
void CO2RGB::ledYellow() {
  ledcWrite(blueChannel, LEDOFF);
  ledcWrite(greenChannel, LEDON);
  ledcWrite(redChannel, LEDMED);
}
void CO2RGB::ledOrange() {
  ledcWrite(blueChannel, LEDOFF);
  ledcWrite(greenChannel, LEDMED);
  ledcWrite(redChannel, LEDON);
}
void CO2RGB::ledRed() {
  ledcWrite(blueChannel, LEDOFF);
  ledcWrite(greenChannel, LEDOFF);
  ledcWrite(redChannel, LEDON);
}
