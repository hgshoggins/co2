/*
    Licence Creative Commons :  CC-BY-NC
    https://creativecommons.org/licenses/by-nc/2.0/fr/
    
    Auteur    : Alain GODON
    Courriel  : alain.godon@univ-angers.fr
    Création  : Novembre 2020
*/

#ifndef __AG_co2rgb__
#define __AG_co2rgb__

#include <Arduino.h>

// Common cathod
#define LEDON 128
#define LEDMED 64                                                 
#define LEDOFF 0
#define commState LOW

#define commPin 2
#define redPin 5
#define greenPin 17
#define bluePin 16

// PWM
#define freq 5000
#define redChannel 0
#define greenChannel 1
#define blueChannel 2
#define resolution 8

class CO2RGB {
public:
  CO2RGB(int, int, int);
  void SetColor(float);
  void System(void);
  void Sequence(void);
  int m_low;
  int m_med;
  int m_high;

private:
  void ledOff(void);
  void ledBlue(void);
  void ledGreen(void);
  void ledYellow(void);
  void ledOrange(void);
  void ledRed(void);
};

#endif
