#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "ordenamientos.h"
#include "empleados.h"
#include "viajes.h"
#include "ventas.h"

/// ORDENAMIENTOS SELECCION/////////////////////////////////////////////////////////////////////////////////////////////////

/// ORDENAMIENTO EMPLEADOS ////////////////////////////////////////////////////////////////////////

int buscarPosMenorEmpleado (stEmpleado* A, int pos, int cantRegistrosE){

    int posMenor=pos, i;
    char menorEmpleado[30];

    strcpy(menorEmpleado, A[pos].nYa);

    for(i=pos+1; i<cantRegistrosE; i++){
        if(strcmpi(menorEmpleado, A[i].nYa) > 0){
            strcpy(menorEmpleado, A[i].nYa);
            posMenor=i;
        }
    }

    return posMenor;
}

void ordenamientoSeleccionEmpleado(stEmpleado* A, int cantRegistrosE){

    int posMenor;
    stEmpleado aux;
    int i=0;

     while(i<cantRegistrosE){
        posMenor=buscarPosMenorEmpleado(A, i, cantRegistrosE);
        aux=A[posMenor];
        A[posMenor]=A[i];
        A[i]=aux;
        i++;
     }
}

/// ORDENAMIENTO CLIENTES /////////////////////////////////////////////////////////////////////////

int cantRegistrosC=0;

int buscarPosMenorCliente (stCliente* A, int pos, int cantRegistrosC){

    int posMenor=pos, i;
    char menorCliente[30];

    strcpy(menorCliente, A[pos].nYa);

    for(i=pos+1; i<cantRegistrosC; i++){
        if(strcmpi(menorCliente, A[i].nYa) > 0){
            strcpy(menorCliente, A[i].nYa);
            posMenor=i;
        }
    }

    return posMenor;
}

void ordenamientoSeleccionCliente(stCliente* A, int cantRegistrosC){

    int posMenor;
    stCliente aux;
    int i=0;

     while(i<cantRegistrosC){
        posMenor=buscarPosMenorCliente(A, i, cantRegistrosC);
        aux=A[posMenor];
        A[posMenor]=A[i];
        A[i]=aux;
        i++;
     }
}

/// ORDENAMIENTO VIAJES ///////////////////////////////////////////////////////////////////////////

int buscarPosMenorViaje (stViaje* A, int pos, int cantRegistrosV){

    int posMenor=pos, i;
    char menorDestino[30];

    strcpy(menorDestino, A[pos].destino);

    for(i=pos+1; i<cantRegistrosV; i++){
        if(strcmpi(menorDestino, A[i].destino) > 0){
            strcpy(menorDestino, A[i].destino);
            posMenor=i;
        }
    }

    return posMenor;
}

void ordenamientoSeleccionViaje(stViaje* A, int cantRegistrosV){

    int posMenor;
    stViaje aux;
    int i=0;

     while(i<cantRegistrosV){
        posMenor=buscarPosMenorViaje(A, i, cantRegistrosV);
        aux=A[posMenor];
        A[posMenor]=A[i];
        A[i]=aux;
        i++;
     }
}

///ORDENAMIENTO VENTAS/////////////////////////////////////////////////////////////////////////////////////////////////

int cantRegistrosT=0;

int buscarPosMenorTicket(stTickets* A, int pos, int cantRegistrosT)
{

    int posMenor=pos, i;
    char menorVenta[30];

    strcpy(menorVenta, A[pos].idCliente);

    for(i=pos+1; i<cantRegistrosT; i++){
        if(strcmpi(menorVenta, A[i].idCliente) > 0){
            strcpy(menorVenta, A[i].idCliente);
            posMenor=i;
        }
    }

    return posMenor;
}

void ordenamientoSeleccionTicket(stTickets* A, int cantRegistrosT)
{
    int posMenor;
    stTickets aux;
    int i=0;

     while(i<cantRegistrosT){
        posMenor=buscarPosMenorTicket(A, i, cantRegistrosT);
        aux=A[posMenor];
        A[posMenor]=A[i];
        A[i]=aux;
        i++;
     }
}


/// ORDENAMIENTOS INSERCION////////////////////////////////////////////////////////////////////////////////////////

/// ORDENAMIENTO EMPLEADOS ////////////////////////////////////////////////////////////////////////

void insertarEmpleado (stEmpleado* A, int u, stEmpleado aux){

    int i=u;

    while(i>=0 && strcmp(A[i].dni, aux.dni)>0){
        A[i+1]=A[i];
        i--;

    }

    A[i+1]=aux;

}

void ordenamientoInserccionEmpleado (stEmpleado* A, int cantRegistrosE){

    int i=0;


    while(i < cantRegistrosE - 1){
        stEmpleado aux = A[i];
        insertarEmpleado(A, i, A[i+1]);
        i++;
    }

}

/// ORDENAMIENTO CLIENTES /////////////////////////////////////////////////////////////////////////

void insertarCliente (stCliente* A, int u, stCliente aux){

    int i=u;

    while(i>=0 && strcmp(A[i].dni, aux.dni)>0){
        A[i+1]=A[i];
        i--;

    }

    A[i+1]=aux;

}

void ordenamientoInserccionCliente (stCliente* A, int cantRegistrosC){

    int i=0;


    while(i < cantRegistrosC - 1){
        stCliente aux = A[i];
        insertarCliente(A, i, A[i+1]);
        i++;
    }

}

/// ORDENAMIENTO VIAJES ///////////////////////////////////////////////////////////////////////////

int cantRegistrosV=0;

void insertar (stViaje* A, int u, stViaje aux){

    int i=u;

    while(i>=0 && A[i].id > aux.id){
        A[i+1]=A[i];
        i--;

    }

    A[i+1]=aux;

}

void ordenamientoInserccion (stViaje* A, int cantRegistrosV){

    int i=0;


    while(i < cantRegistrosV - 1){
        stViaje aux = A[i];
        insertar(A, i, A[i+1]);
        i++;
    }

}

///ORDENAMIENTO VENTAS///////////////////////////////////////////////////////////////////

void insertarTicket(stTickets* A, int u, stTickets aux)
{

    int i=u;

    while(i>=0 && A[i].id > aux.id){
        A[i+1] = A[i];
        i--;
    }

    A[i+1]=aux;

}

void ordenamientoInserccionTicket(stTickets* A, int cantRegistrosT)
{
    int i=0;


    while(i < cantRegistrosT - 1){
        stTickets aux = A[i];
        insertarTicket(A, i, A[i+1]);
        i++;
    }

}
