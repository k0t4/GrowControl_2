#include <Arduino.h>

#include "sensores.h"
#include "global_variables.h"

DeviceAddress temperatura_tierra = {0x28, 0xFF, 0xB6, 0x4C, 0xA1, 0x17, 0x04, 0xD7};  //ds18b20
DeviceAddress temperatura_agua = {0x28, 0xFF, 0xE7, 0xDC, 0xA0, 0x17, 0x05, 0x9B};  //ds18b20

void vsDS18B20()
{
    // Iniciamos el bus 1-Wire  //ds18b20
    g_sensorDS18B20.begin();  //ds18b20
    // Buscamos los sensores conectados  //ds18b20
    Serial.println("Buscando dispositivos...");  //ds18b20
    Serial.println("Encontrados: ");  //ds18b20
    Serial.print(g_sensorDS18B20.getDeviceCount());  //ds18b20
    Serial.println(" sensores");  //ds18b20
}
void vsDTH()
{
    Serial.println("AMGD ADRIAN TFG");  //DTH
    g_dht1.begin();//Inicializamos los sensores  //DTH
    g_dht2.begin();  //DTH
    g_dht3.begin();  //DTH
}
void vsRELOJ3231()
{
    //RELOJ 3231
    if (! g_rtc_clk.begin()) {
      Serial.println("Couldn't find RTC");
      while (1);
    }
    //RELOJ 3231
    if (g_rtc_clk.lostPower()) {
      Serial.println("RTC lost power, lets set the time!");  //RELOJ 3231
      // following line sets the RTC to the date & time this sketch was compiled
      g_rtc_clk.adjust(DateTime(F(__DATE__), F(__TIME__)));  //RELOJ 3231
      // This line sets the RTC with an explicit date & time, for example to set
      // January 21, 2014 at 3am you would call:
      // g_rtc_clk.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }  //RELOJ 3231
}

//LUISDA: Funciones de lectura de sensores
//____________________________________________________________ Actualizar el sensor DS18B20
void actualizarSensorDS18B20()
{
  // Mandamos comandos para toma de temperatura a los sensores
  Serial.println("Mandando comandos a los sensores");
  g_sensorDS18B20.requestTemperatures();

  //LUISDA: Leemos las temperaturas una sola vez.
  g_temperatura_tierra = g_sensorDS18B20.getTempC(temperatura_tierra);
  g_temperatura_agua = g_sensorDS18B20.getTempC(temperatura_agua);
}

//____________________________________________________________ Actualizar los sensores DTH
void actualizarSensoresDTH()
{
  g_humedad_ambiente1 = g_dht1.readHumidity(); //para sensor 1 dht1 HT1 44
  g_temperatura_ambiente1 = g_dht1.readTemperature();

  if (isnan(g_humedad_ambiente1) || isnan(g_temperatura_ambiente1)) {
     Serial.println("Failed DHT 1!");
     //return;
  }

  g_humedad_ambiente2 = g_dht2.readHumidity(); //para sensor 2 dht2 HT2 45
  g_temperatura_ambiente2 = g_dht2.readTemperature();

  if (isnan(g_humedad_ambiente2) || isnan(g_temperatura_ambiente1)) {
    Serial.println("Failed DHT 2!");
    //return;
  }

  g_humedad_ambiente3 = g_dht3.readHumidity(); //para sensor 3 dht3 HT3 46
  g_temperatura_ambiente3 = g_dht3.readTemperature();

  if (isnan(g_humedad_ambiente3) || isnan(g_temperatura_ambiente3)) {
      Serial.println("Failed DHT 3!");
      //return;
  }
}

//____________________________________________________________ Actualizar los higrómetros
void actualizarHigrometros()
{
  g_humedad1 = analogRead(A0);
  g_humedad1 = map(g_humedad1, 300, 1023, 100, 0);

  g_humedad2 = analogRead(A1);
  g_humedad2 = map(g_humedad2, 300, 1023, 100, 0);
}

//____________________________________________________________ Actualizar LDR
void actualizarLDR()
{
  g_LDR= analogRead(A7);

  // Devolver el valor leido a nuestro monitor serial en el IDE de Arduino
  Serial.print("LDR: ");
  Serial.println(g_LDR);

  //Uso la funcion map para pasar a % el valorLDR
  g_LDR = map(g_LDR, 600, 0, 100, 0);
}
