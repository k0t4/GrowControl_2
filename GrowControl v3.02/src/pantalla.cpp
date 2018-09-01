//_______________________________________________________________________________includes

#include <Arduino.h>


#include "SPI.h"  // PANTALLA
#include "Adafruit_GFX.h"  // PANTALLA
#include "Adafruit_ILI9341.h"  // PANTALLA

//#include <OneWire.h>  //ds18b20
//#include <DallasTemperature.h>  //ds18b20

//#include <Adafruit_Sensor.h>  //DTH
//#include <DHT.h>  //DTH

//#include <Wire.h>  //RELOJ 3231
//#include "RTClib.h"  //RELOJ 3231

#include "pantalla.h"

#include "global_variables.h"


#define TFT_DC 26  // PANTALLA
#define TFT_CS 28  // PANTALLA



//RTC_DS3231 rtc;  //RELOJ 3231
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};  //RELOJ 3231

const int sensorPin0 = A0;  //HIGROMETROS
const int sensorPin1 = A1;  //HIGROMETROS

// Pin analogico de entrada para el LDR
int pinLDR = A7;  //LDR sensor LUZ 


Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);  // PANTALLA

//____________________________________________________________ void para setup (vsNAME):
void vsPANTALLA()
{
#ifdef DEBUG_MODE
    Serial.println("ILI9341 Pantalla ok");  //pantalla
#endif

    tft.begin();  //pantalla

}


//____________________________________________________________ void para loop (vlNAME):

void vlPANTALLA()
{
  tft.setRotation(3);//0 y 4 vertical , 1 y 3 horizontal, 6 vertical con texto en pines.

  delay(4000);

  tft.fillScreen(ILI9341_BLACK);// para loop con pantalla en negro
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
  tft.print("AMDG  +++    ASP&LDLRL ");

  DateTime now = g_rtc_clk.now();
  tft.print("    ");
  tft.print(now.year(), DEC);
  tft.print('/');
  tft.print(now.month(), DEC);
  tft.print('/');
  tft.print(now.day(), DEC);
  tft.print(" (");
  tft.print(daysOfTheWeek[now.dayOfTheWeek()]);
  tft.print(") ");
  tft.print(now.hour(), DEC);
  tft.print(':');
  tft.print(now.minute(), DEC);

  tft.println(" ");
  //tft.println(" ");

  tft.setTextColor(ILI9341_WHITE); tft.setTextSize(2);
  tft.print("GrowControl ___v4_");//____________________________________________________________ versión del proyecto
  tft.setTextColor(ILI9341_WHITE); tft.setTextSize(1);
  tft.println("VERSION");//____________________________________________________________ versión del proyecto estable / version beta con cambios
  tft.println("                                              ESTABLE");//____________________________________________________________ versión del proyecto estable / version beta con cambios
}

void vlDS18B20()
{
  // Leemos y mostramos los datos de los sensores DS18B20 por dirección única
#ifdef DEBUG_MODE
  Serial.print("Temperatura de la tierra ds18b20: ");
  Serial.print(g_temperatura_tierra);
  Serial.println(" C");
  Serial.print("Temperatura del agua ds18b20: ");
  Serial.print(g_temperatura_agua);
  Serial.println(" C");
#endif

  tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(1);
  //tft.println(" ");
  tft.println(" ");
  tft.println(" SENSORES DS18B20");
  tft.println(" ");

  tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(2);
  tft.print(" TT: ");
  tft.print(g_temperatura_tierra);
  tft.print(" C ");
  tft.print(" TA: ");
  tft.print(g_temperatura_agua);
  tft.print(" C  ");
}

void vlDTH()
{
     // Reading temperature or humidity takes about 250 milliseconds!
     if (isnan(g_humedad_ambiente1) || isnan(g_temperatura_ambiente1)) {

#ifdef DEBUG_MODE
        Serial.println("Failed DHT 1!");
#endif
        return;
     }

#ifdef DEBUG_MODE
     Serial.print("H 1: "); //del sensor 1
     Serial.print(g_humedad_ambiente1);
     Serial.print(" %\t");
     Serial.print("T 1: ");
     Serial.print(g_temperatura_ambiente1);
     Serial.print(" *C ");
     Serial.print("\t");
#endif

     tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
     //tft.println(" ");

    tft.println(" ");
    tft.print(" SENSORES DTH"); //del sensor 1
    tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(2);
    tft.println(" ");

    tft.print(" H1: "); //del sensor 1
    tft.print(g_humedad_ambiente1);
    tft.print(" % ");
    tft.print(" T1: ");
    tft.print(g_temperatura_ambiente1);
    tft.println(" C ");

    if (isnan(g_humedad_ambiente2) || isnan(g_temperatura_ambiente2)) {

#ifdef DEBUG_MODE
      Serial.println("Failed DHT 2!");
#endif
      return;
    }

#ifdef DEBUG_MODE
    Serial.print("H 2: ");// del sensor 2
    Serial.print(g_humedad_ambiente2);
    Serial.print(" %\t");
    Serial.print("T 2: ");
    Serial.print(g_temperatura_ambiente2);
    Serial.print(" *C ");
    Serial.print("\t");
#endif

    tft.print(" H2: ");// del sensor 2
    tft.print(g_humedad_ambiente2);
    tft.print(" % ");
    tft.print(" T2: ");
    tft.print(g_temperatura_ambiente2);
    tft.println(" C ");

    if (isnan(g_humedad_ambiente3) || isnan(g_temperatura_ambiente3)) {

#ifdef DEBUG_MODE       
        Serial.println("Failed DHT 3!");
#endif
        return;
    }

#ifdef DEBUG_MODE
    Serial.print("H 3: "); // del sensor 3
    Serial.print(g_humedad_ambiente3);
    Serial.print(" %\t");
    Serial.print(" 3: ");
    Serial.print(g_temperatura_ambiente3);
    Serial.print(" *C ");
    Serial.print("\n");
#endif

    tft.print(" H3: "); // del sensor 3
    tft.print(g_humedad_ambiente3);
    tft.print(" % ");
    tft.print(" T3: ");
    tft.print(g_temperatura_ambiente3);
    tft.println(" C ");
}

void vlHIGROMETROS()
{
#ifdef DEBUG_MODE  
    Serial.print("Humedad_1 ");
    Serial.print(g_humedad1);
    Serial.println("% ");
#endif

    tft.setTextColor(ILI9341_GREEN); tft.setTextSize(1);
    tft.println(" ");
    tft.setTextColor(ILI9341_GREEN); tft.setTextSize(1);
    tft.print(" SENSORES HUMEDAD DEL SUELO");
    tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(1);
    tft.println("                   LUZ");
    tft.println(" ");
    tft.setTextColor(ILI9341_GREEN); tft.setTextSize(2);
    tft.print(" HS_1: ");
    tft.print(g_humedad1);
    tft.print("%");

#ifdef DEBUG_MODE
    Serial.print("Humedad_2: ");
    Serial.print(g_humedad2);
    Serial.println("%");
#endif

    tft.print(" HS_2: ");
    tft.print(g_humedad2);
    tft.print("%");

}

void vlLDR()
{
#ifdef DEBUG_MODE
    Serial.print("  L: ");
    Serial.print(g_LDR);
    Serial.println("%");
#endif

    tft.print(" L: ");
    tft.print(g_LDR);
    tft.println("%");

      //___________________letras finales de la pantalla
    tft.println(" ");
    tft.println(" ");
    //tft.print("hola k0t4!!!; ");
    //tft.print("hola mundo!");
    tft.println(" ");
}
