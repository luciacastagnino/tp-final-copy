#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "menu.h"
#include "empleados.h"
#include "clientes.h"
#include "ventas.h"
#include "viajes.h"
#include "admin.h"
#include"home.h"

/// inicio de sesion

//admin

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

//empleado

stEmpleado arBuscarUsuarioLoginEmpleado (char dni[], char contrasenia[])
{
    FILE* buf = fopen(archEmpleado, "rb");
    int flag = 0;
    stEmpleado A;
    if(buf)
    {
        while(flag == 0 && fread(&A, sizeof(stEmpleado), 1, buf)>0)
        {
            if(strcmpi(A.dni, dni)==0 && strcmp(A.contrasenia, contrasenia)==0)
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

stEmpleado iniciarSesionEmpleado()
{
    stEmpleado empleado;
    char dni[10];
    char contrasenia[20];

    printf("Ingrese DNI \n");
    fflush(stdin);
    gets(dni);
    printf("Ingrese contrasenia \n");
    fflush(stdin);
    gets(contrasenia);
    empleado = arBuscarUsuarioLoginEmpleado (dni, contrasenia);
    return empleado;
}

//cliente


/// registro

//admin



//empleado

//cliente
