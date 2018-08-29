
#include <DHT.h>  //DTH
#include <Adafruit_Sensor.h>  //DTH

#include "global_variables.h" // En cada fichero *.cpp debemos hacer este include para acceder a las variables globales

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

#define HT1 40  //DTH

DHT dht11(HT1, DHTTYPE);  //DTH

//__________________________VENTILADOR 1______________________________________________________________
void vsRele1()
{
  pinMode(2, OUTPUT); // El pin anteriormente definido enciende el rele
}



void vlRele1() //Ventilador de la parte superior
{

  if(g_estado_ventilador1 == 0 && g_temperatura_ambiente1 > TEMP_MAX_VENTILADOR) //definir valor en global_variables.h
  {
      g_estado_ventilador1 = 1;
      digitalWrite(2, HIGH);   // encender ventilador
  }

  if(g_estado_ventilador1 == 1 && g_temperatura_ambiente1 < TEMP_MIN_VENTILADOR) //definir valor en global_variables.h
  {
      g_estado_ventilador1 == 0;
      digitalWrite(2, LOW);   // apagar ventilador
  }
}

//__________________________VENTILADOR 2______________________________________________________________
void vsRele2()
{
  pinMode(3, OUTPUT); // El pin anteriormente definido enciende el rele
}



void vlRele2() //Ventilador de la parte superior
{

  if(g_estado_ventilador2 == 0 && g_temperatura_ambiente1 > TEMP_MAX_VENTILADOR) //definir valor en global_variables.h
  {
      g_estado_ventilador2 = 1;
      digitalWrite(3, HIGH);   // encender ventilador
  }

  if(g_estado_ventilador2 == 1 && g_temperatura_ambiente1 < TEMP_MIN_VENTILADOR) //definir valor en global_variables.h
  {
      g_estado_ventilador2 == 0;
      digitalWrite(3, LOW);   // apagar ventilador
  }
}

//___________________luz_____________________________________________________________________
void vsRele3()
{
  pinMode(4,OUTPUT);

}



void vlRele3()
{
  DateTime now = g_rtc_clk.now();
  float hours = now.hour() +  now.minute();

  bool hourCondition = ((hours > HORA_INICIO_LUZ) || (hours < HORA_FIN_LUZ)); //definir valor en global_variables.h

  if (hourCondition)
  {
    pinMode(4, HIGH);
  }
  else
  {
    pinMode(4, LOW);
  }

}

//__________________________AGUA______________________________________________________________
void vsRele4()
{
  pinMode(5, OUTPUT); // El pin anteriormente definido enciende el rele
}



void vlRele4()
{
  DateTime now = g_rtc_clk.now();
  float hours = now.hour() +  now.minute();

  bool hourCondition1 = ((hours > HORA_INICIO_RIEGO_1) && (hours < HORA_INICIO_RIEGO_1 + DURACION_RIEGO_MIN/60.0)); //definir valor en global_variables.h
  bool hourCondition2 = ((hours > HORA_INICIO_RIEGO_2) && (hours < HORA_INICIO_RIEGO_2 + DURACION_RIEGO_MIN/60.0));
  bool hourCondition3 = ((hours > HORA_INICIO_RIEGO_3) && (hours < HORA_INICIO_RIEGO_3 + DURACION_RIEGO_MIN/60.0));
  bool hourCondition4 = ((hours > HORA_INICIO_RIEGO_4) && (hours < HORA_INICIO_RIEGO_4 + DURACION_RIEGO_MIN/60.0));



  if ((hourCondition1 || hourCondition2 || hourCondition3 || hourCondition4) && (g_humedad1 < 90) && (g_humedad2 < 90))
  {
    pinMode(5, HIGH);
  }
  else
  {
    pinMode(5, LOW);
  }
}

//__________________________HEATER______________________________________________________________
void vsRele5()
{
  pinMode(6, OUTPUT); // El pin anteriormente definido enciende el rele
}



void vlRele5()
{
  bool tempBajaCondition2 = (g_temperatura_ambiente2 < TEMP_MIN_CALENTADOR); //definir valor en global_variables.h
  bool tempBajaCondition3 = (g_temperatura_ambiente3 < TEMP_MIN_CALENTADOR);
  bool tempBajaCondition = (tempBajaCondition2 || tempBajaCondition3);

  bool tempAltaCondition2 = (g_temperatura_ambiente2 > TEMP_MAX_CALENTADOR);
  bool tempAltaCondition3 = (g_temperatura_ambiente3 > TEMP_MAX_CALENTADOR);
  bool tempAltaCondition = (tempAltaCondition2 || tempAltaCondition3);
  
  //NOTA: Determinar el sensor más cercano a la luz ambiental por si puede interferir con la función, y ése se excluye
  if(g_estado_calentador == 1 && tempAltaCondition)
  {
      g_estado_calentador = 0;
      digitalWrite(6, LOW);   // apagar el calentador
  }

  if(g_estado_calentador == 0 && tempBajaCondition)
  {
      g_estado_calentador == 1;
      digitalWrite(6, HIGH);   // encender el calentador
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
