#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#include "empleados.h"
#include "ordenamientos.h"
#include "admin.h"
#include "validaciones.h"

/// inicio de sesion ////////////////////////////////////////////

stAdmin arBuscarUsuarioLoginAdmin (char dni[], char contrasenia[])
{
    FILE* buf = fopen(archAdmin, "rb");
    int flag = 0;
    stAdmin A;
    if(buf)
    {
        while(flag == 0 && fread(&A, sizeof(stAdmin), 1, buf)>0)
        {
            if(strcmpi(A.DNI, dni)==0 && strcmp(A.contrasenia, contrasenia)==0)
            {
                flag=1;
            }
        }
        fclose(buf);
    }
    if(flag==0)
    {
        A.estado = 0;
    }
    return A;
}

stAdmin iniciarSesionAdmin()
{
    stAdmin admin;
    char dni[10];
    char contrasenia[20];

    printf("Ingrese DNI \n");
    fflush(stdin);
    gets(dni);
    printf("Ingrese contrasenia \n");
    fflush(stdin);
    gets(contrasenia);
    admin = arBuscarUsuarioLoginAdmin (dni, contrasenia);
    return admin;
}

/// registro ////////////////////////////////////////////////////

stAdmin cargarContraseniaRegistroAdmin (stAdmin A)
{
    char contrasenia[30];
    char constrasenia2[30];
    printf("Ingrese su contrasenia:  \n");
    fflush(stdin);
    gets(contrasenia);
    while(!lenghtContrasenia(contrasenia))
    {
        printf("La contrasenia es muy corta \n");
        printf("Ingrese una contrasenia mas larga:  \n");
        fflush(stdin);
        gets(contrasenia);
    }
    printf("Vuelva a ingresar su contrasenia \n");
    fflush(stdin);
    gets(constrasenia2);
    while(!validarContrasenia(contrasenia, confirmacion))
    {
        printf("Las contrasenias no coinciden\n");
        printf("Ingrese su nueva contrasenia:  \n");
        fflush(stdin);
        gets(contrasenia);
        printf("Vuelva a ingresar su contrasenia \n");
        fflush(stdin);
        gets(constrasenia2);
    }
    strcpy(A.contrasenia, contrasenia);
    return A;
}

/// cargar admin /////////////////////////////////////////////////////

stAdmin cargarAdmin()
{

    stAdmin A;

    printf("Ingrese su nombre y apellido:\n");
    fflush(stdin);
    gets(A.nYa);


    printf("Ingrese su DNI:\n");
    fflush(stdin);
    gets(A.dni);

    A=cargarContraseniaRegistroAdmin(A);

    A.estado=1;

    return A;
}


void cargarArchivoAdmin()
{
    stAdmin A;
    char control = 's';

    FILE* buff;
    buff = fopen(archAdmin, "ab");

    if(buff)
    {
        while(control == 's')
        {
            A = cargarAdmin();

            fwrite(&A, sizeof(stAdmin), 1, buff);

            printf("¿Quiere seguir cargando administadores?\n");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(buff);
    }
    else
    {
        printf("El archivo no pudo abrirse\n");
    }
}

void registroAdministrador()
{
    printf("Carga del administrador:\n");
    cargarArchivoAdmin();

}

///Mostrar Admin/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAdmin (stAdmin A)
{
    printf("ID: %i", A.id);
    printf("Nombre y apellido: %s.\n", A.nYa);
    printf("DNI: %s.\n", A.dni);
    printf("\n");
}
