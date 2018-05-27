#ifndef SENSORES_H
#define SENSORES_H

//Funciones para setup de los sensores
void vsDS18B20();
void vsDTH();
void vsRELOJ3231();

//Funciones para bucle de los sensores
void actualizarSensorDS18B20();
void actualizarSensoresDTH();
void actualizarHigrometros();
void actualizarLDR();

#endif
