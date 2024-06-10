#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED

static const char archViaje[] = {"archivoViaje.bin"};

typedef struct{
    int dia;
    int mes;
    int anio;
}stViajeFecha;

typedef struct{
int id;
char destino[30];
stViajeFecha fechaP;
stViajeFecha fechaR;
int duracion;
char transporte[20];
int precio;
int estado;
}stViaje;

///PROTOTIPOS VIAJE(alta, baja, mostrar, modificacion)
stViaje cargarViaje();
void mostrarViaje(stViaje A);
void mostrarArchivoViaje();
int verificarIDViaje(int id);
stViaje buscarViajePorID(int id);

//modificar viaje
stViaje modificarIdV(stViaje A);
stViaje modificarFechaPartidaV (stViaje A);
stViaje modificarFechaRegresoV (stViaje A);
stViaje modificarDestinoV(stViaje A);
stViaje modificarDuracionV(stViaje A);
stViaje modificarTransporteV(stViaje A);
stViaje modificarPrecioV(stViaje A);
stViaje modificarEstadoV(stViaje A);
void modificarViaje (int id);
stViaje modificarDatosViaje(stViaje aux);
int verificarIDNoExiste(int id);

// dar baja viaje

void darDeBajaViaje (int id);
stViaje darBajaVJ(stViaje aux);

//Filtrar Viajes
void filtrarViajeTransporte(char transporte[10]);
void filtrarViajeDestino(char D[10]);
void filtrarViajeEstado(int E);

///PROTOTIPO ARCHIVO

/// ordenar viajes

int calcularRegistrosV();
int ArchivoToArregloViaje (stViaje** arrD, int validos);
int ArchivoToArregloViajeActivo(stViaje** arrD, int validos);
int ArchivoToArregloViajeInactivo(stViaje** arrD, int validos);
void ordenarArrDinamicoViaje (stViaje** arrD, int validos);
void MostrarArregloViaje(stViaje A[], int validos);
void mostrarOrdenIDV();
void mostrarOrdenDestinoV();
void mostrarOrdenIDActivosV();
void mostrarOrdenDestinoActivosV();
void mostrarOrdenIDBajaV();
void mostrarOrdenDestinoBajaV();

void cargarArchivoViaje();
stViaje encontrarViajeId(int id);

/// FUNCIONES AUXILIARES

int calculaDuracionViaje();


#endif // VIAJES_H_INCLUDED


