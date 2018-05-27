// Ventilador por rango de temperatura
#include <DHT.h>  //DTH
#include <Adafruit_Sensor.h>  //DTH

#include "global_variables.h" //LUISDA: En cada fichero *.cpp debemos hacer este include para acceder a las variables globales

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//const int DHTPin = 5;     // what digital pin we're connected to
#define HT1 40  //DTH

//const int ledRele = 2; // PWM que activa el rele para activar ventilador
const int tempmin = 23; // Rango temperatura minima
const int tempmax = 26; // Rango temperatura maxima

// FALTAN MAS VARIABLES DE MAX Y MIN

//bool state = 0; // Ventilador activo o inactivo => LUISDA: Lo pasamos a variable global... Y le damos un nombre más descriptivo, g_ventilador_estado


//float temp1();
DHT dht11(HT1, DHTTYPE);  //DTH

//__________________________VENTILADOR 1______________________________________________________________
void vsRele1()
{
  // Ventilador por rango de temperatura
  //dht1.begin();//Inicializamos los sensores  //DTH
  pinMode(2, OUTPUT); // El pin anteriormente definido enciende el rele
}



void vlRele1()
{
  //float t11 = dht11.readTemperature();
  //LUISDA: Ya que hemos definido la variable global g_temperatura_ambiente1, la usamos (en ella se escribe en la pantalla) ;-) .
  //float currentTemperature = GetTemperature();

  if(g_estado_ventilador1 == 0 && g_temperatura_ambiente1 > tempmax)
  {
      g_estado_ventilador1 = 1;
      digitalWrite(2, HIGH);   // encender ventilador
  }

  if(g_estado_ventilador1 == 1 && g_temperatura_ambiente1 < tempmin)
  {
      g_estado_ventilador1 == 0;
      digitalWrite(2, LOW);   // apagar ventilador
  }
}

//__________________________VENTILADOR 2______________________________________________________________
void vsRele2()
{
  // Ventilador por rango de temperatura
  //dht1.begin();//Inicializamos los sensores  //DTH
  pinMode(3, OUTPUT); // El pin anteriormente definido enciende el rele
}



void vlRele2()
{
  //float t11 = dht11.readTemperature(); //LUISDA: Usar mejor la variable global g_temperatura_ambiente1
  //float currentTemperature = GetTemperature();

  if(g_estado_ventilador2 == 0 && g_temperatura_ambiente1 > tempmax)
  {
      g_estado_ventilador2 = 1;
      digitalWrite(3, HIGH);   // encender ventilador
  }

  if(g_estado_ventilador2 == 1 && g_temperatura_ambiente1 < tempmin)
  {
      g_estado_ventilador2 == 0;
      digitalWrite(3, LOW);   // apagar ventilador
  }
}

//___________________luz_____________________________________________________________________
void vsRele3()
{

}



void vlRele3()
{

}

//__________________________AGUA______________________________________________________________
void vsRele4()
{
  // Ventilador por rango de temperatura
  //dht1.begin();//Inicializamos los sensores  //DTH
  pinMode(5, OUTPUT); // El pin anteriormente definido enciende el rele
}



void vlRele4()
{

}

//__________________________HEATER______________________________________________________________
void vsRele5()
{
  // Ventilador por rango de temperatura
  //dht1.begin();//Inicializamos los sensores  //DTH
  pinMode(6, OUTPUT); // El pin anteriormente definido enciende el rele
}



void vlRele5()
{
  //float t11 = dht11.readTemperature(); //LUISDA: Usar mejor la variable global g_temperatura_ambiente1

  //float currentTemperature = GetTemperature();

  if(g_estado_calentador == 0 && g_temperatura_ambiente1 > tempmax)
  {
      g_estado_calentador = 1;
      digitalWrite(6, HIGH);   // encender ventilador
  }

  if(g_estado_calentador == 1 && g_temperatura_ambiente1 < tempmin)
  {
      g_estado_calentador == 0;
      digitalWrite(6, LOW);   // apagar ventilador
  }
}

//__________________________S0S______________________________________________________________
void vsRele7()
{
  // CORTE DE CORRIENTE POR SEGURIDAD
  pinMode(8, OUTPUT); // El pin anteriormente definido enciende el rele
}



void vlRele7()
{

}
