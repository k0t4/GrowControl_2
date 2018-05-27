/**
* Este fichero se usa para declarar variables globales, siempre como extern, luego el tipo y luego el identificador de la variable.
*/
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include <Wire.h>  //RELOJ 3231
#include "RTClib.h"  //RELOJ 3231

#include <Adafruit_Sensor.h>  //DTH
#include <DHT.h>  //DTH

//#include <OneWire.h>  //ds18b20
#include <DallasTemperature.h>  //ds18b20

//Variables que contendrán la lectura de los higrómetros analógicos conectado a A0 y A1, respectivamente
extern int g_humedad1;
extern int g_humedad2;

extern int g_LDR; //Lectura del sensor de luz LDR.

//Lectura de los sensores de temperatura de agua y tierra
extern float g_temperatura_tierra;
extern float g_temperatura_agua;

//Lectura de los sensores ambientales
extern float g_humedad_ambiente1;
extern float g_temperatura_ambiente1;
extern float g_humedad_ambiente2;
extern float g_temperatura_ambiente2;
extern float g_humedad_ambiente3;
extern float g_temperatura_ambiente3;

//LUISDA: Podría ser interesante englobar en un solo byte el estado de todos los relés, a estudiar para un poco más adelante, de momento así:
extern unsigned char g_estado_ventilador1;
extern unsigned char g_estado_ventilador2;

extern unsigned char g_estado_calentador;

//Objetos accesores a los sensores
extern RTC_DS3231 g_rtc_clk;  //RELOJ 3231
extern DHT g_dht1;//(HT1, DHTTYPE);  //DTH
extern DHT g_dht2;//(HT2, DHTTYPE);  //DTH
extern DHT g_dht3;//(HT3, DHTTYPE);  //DTH

extern DallasTemperature g_sensorDS18B20;

#endif
