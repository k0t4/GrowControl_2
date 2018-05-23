/**
* Este fichero se usa para declarar variables globales, siempre como extern, luego el tipo y luego el identificador de la variable.
*/
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
