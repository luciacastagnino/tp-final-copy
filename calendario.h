#ifndef CALENDARIO_H_INCLUDED
#define CALENDARIO_H_INCLUDED
#include "viajes.h"

void llamadaCalendario();
void MostrarCalendario(int calendario[6][7], stViaje viajes[], int numViajes, int mesSeleccionado);
void CargarCalendario(int calendario[6][7], int calendarioOpciones);


#endif // CALENDARIO_H_INCLUDED
