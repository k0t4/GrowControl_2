/**
* Este fichero es para inicializar las variables globales.
*/
#include <OneWire.h>
#include "global_variables.h"

#define HT1 40  //DTH
#define HT2 38  //DTH
#define HT3 36  //DTH

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

int g_humedad1 = 0;
int g_humedad2 = 0;

int g_LDR = 0;

float g_temperatura_tierra = 0.0;
float g_temperatura_agua = 0.0;

float g_humedad_ambiente1 = 0.0;
float g_temperatura_ambiente1 = 0.0;
float g_humedad_ambiente2 = 0.0;
float g_temperatura_ambiente2 = 0.0;
float g_humedad_ambiente3 = 0.0;
float g_temperatura_ambiente3 = 0.0;

unsigned char g_estado_ventilador1 = 0; //Usando un unsigned char usamos un solo byte, con un bool dos o cuatro (no recuerdo)
unsigned char g_estado_ventilador2 = 0; //Usando un unsigned char usamos un solo byte, con un bool dos o cuatro (no recuerdo)

unsigned char g_estado_calentador = 0;

RTC_DS3231 g_rtc_clk;
DHT g_dht1(HT1, DHTTYPE);  //DTH
DHT g_dht2(HT2, DHTTYPE);  //DTH
DHT g_dht3(HT3, DHTTYPE);  //DTH

OneWire oneWireObjeto(32);  //ds18b20
DallasTemperature g_sensorDS18B20(&oneWireObjeto);
