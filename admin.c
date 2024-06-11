#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#include "empleados.h"
#include "ordenamientos.h"
#include "admin.h"
#include "validaciones.h"

stAdmin cargarContraseniaAdmin(stAdmin A){

    char contrasenia[30];
    char contrasenia2[30];
    int flag=0;
    printf("Ingrese su contrasenia:  \n");
    fflush(stdin);
    gets(contrasenia);
    flag=lenghtContrasenia(contrasenia);

    while(flag!=1)
    {
        printf("La contrasenia es muy corta, ingrese una contrasenia mas larga.\n");
        fflush(stdin);
        gets(contrasenia);
        flag=lenghtContrasenia(contrasenia);
    }
    printf("Vuelva a ingresar su contrasenia \n");
    fflush(stdin);
    gets(contrasenia2);

    int validacion=0;

    validacion=validacionContrasenia(contrasenia, contrasenia2);

    while(validacion!=1){
        printf("Las contrasenias no coinciden, ingrese nuevamente la contrasenia\n");
        fflush(stdin);
        gets(contrasenia);
        printf("Vuelva a ingresar su contrasenia \n");
        fflush(stdin);
        gets(contrasenia2);
        validacion=validacionContrasenia(contrasenia, contrasenia2);
    }
    strcpy(A.contrasenia, contrasenia);

    return A;
}

stAdmin cargarAdmin(){

    stAdmin A;

    printf("Ingrese su nombre y apellido:\n");
    fflush(stdin);
    gets(A.nYa);

    A=cargarContraseniaAdmin(A);

    printf("Ingrese su DNI:\n");
    fflush(stdin);
    gets(A.dni);

    A.estado=1;

    return A;
}

// REGISTRO CLIENTE
/*
int generarIdCliente()
{
    FILE* buf;
    buf = fopen(archCliente,"rb");
    stCliente A;

    if(buf)
    {
        fseek(buf, sizeof(stCliente)*(-1), SEEK_END);
        fread(&A, sizeof(stCliente), 1, buf);
        fclose(buf);
    }
    return A.;
}*/

void registrarAdmin() {

    FILE *buf;
    buf=fopen(archAdmin, "ab");
    stAdmin A;

    if(buf){
        A=cargarAdmin();
        fwrite(&A, sizeof(stAdmin), 1, buf);
        fclose(buf);
        printf("Administrador registrado con exito.\n");
    }else{
        printf("No se pudo abrir el archivo.\n");
    }
}

stAdmin busquedaAdminInicioSesion (char dni[], char contrasenia[])
{
    FILE* buf;
    buf=fopen(archAdmin, "rb");
    stAdmin A;
    int flag=0;

    if(buf)
    {
        while(flag != 1 && fread(&A, sizeof(stAdmin), 1, buf)>0)
        {
            if(strcmpi(A.dni, dni)==0 && strcmp(A.contrasenia, contrasenia)==0)
            {
                flag=1;
            }
        }
        fclose(buf);
    }

    return A;
}

stAdmin iniciarSesionAdmin() {

    FILE *buf;
    buf = fopen(archAdmin, "rb");
    char dni[10];
    char contrasenia[20];
    char contrasenia2[20];
    stAdmin A;
    int flag=0;

    if(buf){
        while(flag!=1){

        printf("Ingrese el DNI:\n");
        fflush(stdin);
        gets(dni);

        printf("Ingrese contrasenia:\n");
        fflush(stdin);
        gets(contrasenia);
        A=busquedaAdminInicioSesion(dni, contrasenia);

        if((strcmp(A.dni, dni)==0) && strcmp(A.contrasenia, contrasenia)==0){
            printf("Inicio de sesion exitoso.\n");
            flag=1;
        }else{
            printf("Dni o contrasenia incorrectos. Vuelva a iniciar sesion.\n");
        }

    }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo.\n");
    }

    return A;
}

///Mostrar Cliente///////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAdmin(stAdmin A)
{
    printf("Nombre y Apellido: %s\n", A.nYa);
    printf("DNI: %s\n", A.dni);
    printf("\n");
}

///Mostrar archivo Clientes/////////////////

void mostrarArchivoAdmin()
{
    stAdmin A;

    FILE* buf;
    buf = fopen(archAdmin, "rb");

    if(buf)
    {
        while(fread(&A, sizeof(stAdmin), 1, buf))
        {
            mostrarAdmin(A);
        }
        fclose(buf);
    }
    else
    {
        printf("El archivo no pudo abrirse\n");
    }
}
