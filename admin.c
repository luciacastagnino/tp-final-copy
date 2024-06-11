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

/// Mostrar Admin ///////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAdmin(stAdmin A)
{
    printf("Nombre y Apellido: %s\n", A.nYa);
    printf("DNI: %s\n", A.dni);
    printf("\n");
}

/// Mostrar archivo admin /////////////////

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

void mostrarPerfilAdmin (char nYa[]){

    FILE* buf;
    buf=fopen(archAdmin, "rb");
    stAdmin A;

    if(buf){
        while(fread(&A, sizeof(stAdmin), 1, buf)>0){
            if(strcmp(A.nYa, nYa)==0){
                mostrarAdmin(A);
            }
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo.\n");
    }
}

/// MODIFICAR ADMIN //////////////////////////////////////////////////////////////

void modificarAdmin (char nYa[]){

    FILE* buf;
    buf=fopen(archAdmin, "r+b");
    stAdmin A;
    int op=1, opcion=0, flag=0;

    if(buf){
            while(fread(&A, sizeof(stAdmin), 1, buf)>0){
                if(strcmp(A.nYa, nYa)==0){
                    flag=1;
                }
            if(flag==1){
                printf("Que desea modificar?\n");
                printf("1. Nombre y apellido.\n");
                printf("2. DNI.\n");
                printf("3. Contrasenia.\n");
                scanf("%i", &opcion);
                switch(opcion){
            case 1:
                printf("Ingrese el nuevo nombre y apellido del administrador:\n");
                fflush(stdin);
                gets(A.nYa);
                break;
            case 2:
                printf("Ingrese el nuevo DNI del administrador:\n");
                fflush(stdin);
                gets(A.dni);
                break;
            case 3:
                printf("Ingrese la nueva contrasenia:\n");
                fflush(stdin);
                char contrasenia[30];
                char contrasenia2[30];
                int flagC=0;
                gets(contrasenia);
                flagC=lenghtContrasenia(contrasenia);

                while(flagC!=1)
                {
                printf("La contrasenia es muy corta, ingrese una contrasenia mas larga.\n");
                fflush(stdin);
                gets(contrasenia);
                flagC=lenghtContrasenia(contrasenia);
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
                break;
            default:
                printf("No existe la opcion.\n");
                break;
                }}

                fseek(buf, -1*sizeof(stAdmin), SEEK_CUR);
                fwrite(&A, sizeof(stAdmin), 1, buf);
            }
            fclose(buf);
    }else{
        printf("No se pudo modificar el usuario.\n");
    }

    if(flag==0){
        printf("No se encontro el usuario.\n");
    }

}
