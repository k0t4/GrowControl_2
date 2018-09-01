/**
* Este fichero se usa para declarar variables globales, siempre como extern, luego el tipo y luego el identificador de la variable.
*/
#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

//Para depurar con traza serie. Si deseo ver las trazas, descomentar lo siguiente y...: 
//#define DEBUG_MODE
//...Compilar y subir

//Horainicio luz
#define HORA_INICIO_LUZ 7.00
#define HORA_FIN_LUZ 22.00

//Horas inicio y fin del riego
#define HORA_INICIO_RIEGO_1 8.00
#define HORA_INICIO_RIEGO_2 12.00
#define HORA_INICIO_RIEGO_3 16.00
#define HORA_INICIO_RIEGO_4 20.00
#define DURACION_RIEGO_MIN 5.0

#define TEMP_MIN_VENTILADOR 20
#define TEMP_MAX_VENTILADOR 33

#define TEMP_MIN_CALENTADOR 10
#define TEMP_MAX_CALENTADOR 20

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
