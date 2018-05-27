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

//#include "rele1.h"
//_______________________________________________________________________________defines
// For the Adafruit shield, these are the default.
#define TFT_DC 26  // PANTALLA
#define TFT_CS 28  // PANTALLA

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

//#define HT1 40  //DTH
//#define HT2 38  //DTH
//#define HT3 36  //DTH
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

//________________________________________________________________________________int

// Pin donde se conecta el bus 1-Wire
//const int pinDatosDQ = 32;  //ds18b20
// Instancia a las clases OneWire y DallasTemperature
//OneWire oneWireObjeto(pinDatosDQ);  //ds18b20
//DallasTemperature sensorDS18B20(&oneWireObjeto);  //ds18b20
// Variables con las direcciones únicas de los 4 sensores DS18B20
/*
DeviceAddress temperatura_tierra = {0x28, 0xFF, 0xB6, 0x4C, 0xA1, 0x17, 0x04, 0xD7};  //ds18b20
DeviceAddress temperatura_agua = {0x28, 0xFF, 0xE7, 0xDC, 0xA0, 0x17, 0x05, 0x9B};  //ds18b20
*/

//const int DHTPin = 5;     // what digital pin we're connected to
//DHT dht1(HT1, DHTTYPE);  //DTH
//DHT dht2(HT2, DHTTYPE);  //DTH
//DHT dht3(HT3, DHTTYPE);  //DTH

//RTC_DS3231 rtc;  //RELOJ 3231
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};  //RELOJ 3231

const int sensorPin0 = A0;  //HIGROMETROS
const int sensorPin1 = A1;  //HIGROMETROS

// Pin analogico de entrada para el LDR
int pinLDR = A7;  //LDR sensor LUZ => LUISDA: Estaba puesto 7, el pin es A7, no 7 a secas :-) .
// Variable donde se almacena el valor del LDR
//int valorLDR = 0;  //LDR sensor LUZ; LUISDA: Pasado a variable global.

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);  // PANTALLA
// If using the breakout, change pins as desired
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);





//____________________________________________________________ void para setup (vsNAME):
void vsPANTALLA()
{
    Serial.println("ILI9341 Pantalla ok");  //pantalla
    tft.begin();  //pantalla
}


//____________________________________________________________ void para loop (vlNAME):

void vlPANTALLA()
{
  //for(uint8_t rotation=0; rotation<4; rotation++) {
  //tft.setRotation(rotation);
  tft.setRotation(1);//0 y 4 vertical , 1 y 3 horizontal, 6 vertical con texto en pines.
    //int testText();
    //testText();
  delay(4000);

  tft.fillScreen(ILI9341_BLACK);// para loop con pantalla en negro
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
  tft.print("AMDG  +++             ");

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
  tft.println(" ");

  tft.setTextColor(ILI9341_WHITE); tft.setTextSize(2);
  tft.print("GrowControl ___v3.02_");//____________________________________________________________ versión del proyecto
  tft.setTextColor(ILI9341_WHITE); tft.setTextSize(1);
  tft.println("VERSION");//____________________________________________________________ versión del proyecto estable / version beta con cambios
  tft.println("                                              PRUEBA");//____________________________________________________________ versión del proyecto estable / version beta con cambios
}

void vlDS18B20()
{
  // Leemos y mostramos los datos de los sensores DS18B20 por dirección única
  Serial.print("Temperatura de la tierra ds18b20: ");
  Serial.print(g_temperatura_tierra);
  Serial.println(" C");
  Serial.print("Temperatura del agua ds18b20: ");
  Serial.print(g_temperatura_agua);
  Serial.println(" C");

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
        Serial.println("Failed DHT 1!");
        return;
     }


     Serial.print("H 1: "); //del sensor 1
     Serial.print(g_humedad_ambiente1);
     Serial.print(" %\t");
     Serial.print("T 1: ");
     Serial.print(g_temperatura_ambiente1);
     Serial.print(" *C ");
     Serial.print("\t");

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

    if (isnan(g_humedad_ambiente2) || isnan(g_temperatura_ambiente1)) {
      Serial.println("Failed DHT 2!");
      return;
    }


    Serial.print("H 2: ");// del sensor 2
    Serial.print(g_humedad_ambiente2);
    Serial.print(" %\t");
    Serial.print("T 2: ");
    Serial.print(g_temperatura_ambiente2);
    Serial.print(" *C ");
    Serial.print("\t");

    tft.print(" H2: ");// del sensor 2
    tft.print(g_humedad_ambiente2);
    tft.print(" % ");
    tft.print(" T2: ");
    tft.print(g_temperatura_ambiente2);
    tft.println(" C ");

    if (isnan(g_humedad_ambiente3) || isnan(g_temperatura_ambiente3)) {
        Serial.println("Failed DHT 3!");
        return;
    }

    Serial.print("H 3: "); // del sensor 3
    Serial.print(g_humedad_ambiente3);
    Serial.print(" %\t");
    Serial.print(" 3: ");
    Serial.print(g_temperatura_ambiente3);
    Serial.print(" *C ");
    Serial.print("\n");


    tft.print(" H3: "); // del sensor 3
    tft.print(g_humedad_ambiente3);
    tft.print(" % ");
    tft.print(" T3: ");
    tft.print(g_temperatura_ambiente3);
    tft.println(" C ");
}

void vlHIGROMETROS()
{
    Serial.print("Humedad_1 ");
    Serial.print(g_humedad1);
    Serial.println("% ");
    //int humedad1 = analogRead(sensorPin0); //LUISDA: No hace falta leer un mismo pin varias veces ni usar distintas variables (no olvidar: ahorrar carga del micro es clave :-) )
    //   Serial.print("Humedad ");
    //Serial.println(g_humedad1);

    //LUISDA: Conviene tener una indentación (para entendernos, sangrado) correcta. Dentro de un mismo ámbito, es buena práctica tener todas las líneas con el mismo sangrado
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

    Serial.print("Humedad_2: ");
    Serial.print(g_humedad2);
    Serial.println("%");
    //Serial.println(g_humedad2);

    tft.print(" HS_2: ");
    tft.print(g_humedad2);
    tft.print("%");

    //LUISDA: Una nota interesante, el código que esté comentado, lo he quitado. Dejarlo únicamente si tenemos dudas, si no, es un incordio y dificulta la lectura del código fuente.
}

void vlLDR()
{
    Serial.print("  L: ");
    Serial.print(g_LDR);
    Serial.println("%");

    tft.print(" L: ");
    tft.print(g_LDR);
    tft.println("%");

      //___________________letras finales de la pantalla
    tft.println(" ");
    tft.println(" ");
    tft.print("hola k0t4!!!; ");
    tft.print("hola mundo!");
    tft.println(" ");
}
