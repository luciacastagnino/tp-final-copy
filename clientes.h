#include "viajes.h"
#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

static const char archCliente[] = {"archivoCliente.bin"};

typedef struct{
char calle[20];
int num;
char localidad[20];
}stDomicilio;

typedef struct{
char nYa[30];
char contrasenia[30];
char fechaNac[15];
char genero;
char dni[10];
char tel[10];
stDomicilio dom;
stViaje v;
int estado;
}stCliente;

///PROTOTIPOS CLIENTE(alta, baja, mostrar, modificacion)///////////////////////////////////////////////////////////////////

stCliente cargarCliente();
void mostrarCliente(stCliente A);
void mostrarOrdenAlfabCActivo();
void mostrarOrdenDNIActivosC();
void mostrarOrdenAlfabBajaC();
void mostrarOrdenDNIBajaC();
void mostrarOrdenAlfabC();
void mostrarOrdenDNIC();
void mostrarArchivoCliente();

///modificar cliente//////////////////////////////////////////////////////////////////////////////////////////////////////
void modificarCliente (char nYa[]);
stCliente modificarDatosCliente(stCliente aux);
stCliente modificarNyAC(stCliente A);
stCliente modificarFechaNacC(stCliente A);
stCliente modificarGeneroC(stCliente A);
stCliente modificarDniC(stCliente A);
stCliente modificarTelC(stCliente A);
stCliente modificarDomicilioC(stCliente A);
stCliente modificarViajeC(stCliente A);

///Dar Baja Cliente//////////////////////////////////////////////////////////////////////////////////////////////////////////
void darBajaCliente (char nYa[30]);
stCliente darBajaC(stCliente aux);

///PROTOTIPOS DOMICILIO/////////////////////////////////////////////////////////////////////////////////////////////////////
stDomicilio cargarDomicilio();
void mostrarDomicilio(stDomicilio A);
stDomicilio modificarDomicilio(stDomicilio A);
stCliente cargarContraseniaCliente(stCliente A);

///PROTOTIPOS ARCHIVOS/////////////////////////////////////////////////////////////////////////////////////////////////////////
int generarIdCliente();
void registrarCliente();
stCliente busquedaClienteInicioSesion (char dni[], char contrasenia[]);
stCliente iniciarSesionCliente();
void encontrarClienteN(char N[30]);
void encontrarClienteDni(char D[10]);
void MostrarArregloCliente(stCliente A[], int validos);

/// ORDENAMIENTO CLIENTES/////////////////////////////////////////////////////////////////////////////////////////////////////
int calcularRegistrosC();
int ArchivoToArregloCliente(stCliente** arrD, int validos);
int ArchivoToArregloClienteActivo(stCliente** arrD, int validos);
int ArchivoToArregloBajaClientes(stCliente** arrD, int validos);
void ordenarArrDinamicoClientes (stCliente** arrD, int validos);


///Filtrar Clientes/////////////////////////////////////////////////////////////////////////////////////////////////////////
void filtrarClienteGenero(char G);
void filtrarClienteEstado(int E);
void filtrarClienteViaje(int ID);

#endif // CLIENTES_H_INCLUDED
