#ifndef ORDENAMIENTOS_H_INCLUDED
#define ORDENAMIENTOS_H_INCLUDED
#include "empleados.h"
#include "clientes.h"
#include "viajes.h"
#include "ventas.h"

///ORDENAMIENTO POR SELECCION/////////////////////////////////////////////////////////////////////////////////////////////////////

// empleados

int contarCantidadRegistrosE();
int buscarPosMenorEmpleado (stEmpleado* A, int pos, int cantRegistrosE);
void ordenamientoSeleccionEmpleado(stEmpleado* A, int cantRegistrosE);

// clientes

int buscarPosMenorCliente (stCliente* A, int pos, int cantRegistrosC);
void ordenamientoSeleccionCliente(stCliente* A, int cantRegistrosC);

// viajes

int buscarPosMenorViaje (stViaje* A, int pos, int cantRegistrosV);
void ordenamientoSeleccionViaje(stViaje* A, int cantRegistrosV);

//ventas

int buscarPosMenorTicket(stTickets* A, int pos, int cantRegistrosT);
void ordenamientoSeleccionTicket(stTickets* A, int cantRegistrosT);

///ORDENAMIENTO POR INSERCION/////////////////////////////////////////////////////////////////////////////////////////////////////

// empleados

void insertarEmpleado (stEmpleado* A, int u, stEmpleado aux);
void ordenamientoInserccionEmpleado (stEmpleado* A, int cantRegistrosE);

// clientes

void insertarCliente (stCliente* A, int u, stCliente aux);
void ordenamientoInserccionCliente (stCliente* A, int cantRegistrosC);

// viajes

void insertar (stViaje* A, int u, stViaje aux);
void ordenamientoInserccion (stViaje* A, int cantRegistrosV);

//ventas

void insertarTicket(stTickets* A, int u, stTickets aux);
void ordenamientoInserccionTicket(stTickets* A, int cantRegistrosT);

#endif // ORDENAMIENTOS_H_INCLUDED
