

#include <Arduino.h>

#include "pantalla.h"
#include "sensores.h"
#include "rele1.h"

// PARA VER QUE FUNCIONA ARDUINO MEGA
const int ledPin = 13;  //LDR sensor LUZ
// EN UN FUTURO PASAR A DEFINE


void setup(){

    pinMode(ledPin, OUTPUT);  //LED PIN 13 FUNCIONAMIENTO
    digitalWrite(ledPin, HIGH);  //LED PIN 13 FUNCIONAMIENTO
    // Iniciamos la comunicación serie
    Serial.begin(9600);
    delay(3000); // wait for console opening

    vsDS18B20();
    vsDTH();
    vsRELOJ3231();
    vsPANTALLA();

    vsRele1();
    vsRele2();
    vsRele3();
    vsRele4();
    vsRele5();
    //vsRele7();



}


void loop()
{
  // Diferenciamos las funciones en tres grandes bloques:
  // - lectura de sensores.
  // - Refresco de pantalla
  // - Acciones sobre los actuadores.

  //Lectura de sensores
  actualizarSensorDS18B20();
  actualizarSensoresDTH();
  actualizarHigrometros();
  actualizarLDR();

  //Funciones de refresco de la pantalla
  vlPANTALLA();
  vlDS18B20();
  vlDTH();
  vlHIGROMETROS();
  vlLDR();

  //Funciones de los actuadores
  vlRele1();
  vlRele2();
  vlRele3();
  vlRele4();
  vlRele5();


}
