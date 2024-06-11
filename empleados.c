#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
#include "empleados.h"
#include "ordenamientos.h"

///EMPLEADOS EN ORDEN///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///mostrar completo
void mostrarOrdenAlfabE()
{
        stEmpleado* arrDinE;
        int validosE = 0;
        validosE = ArchivoToArregloEmpleados(&arrDinE, validosE);
        ordenamientoSeleccionEmpleado(arrDinE, validosE);
        mostrarArregloEmpleadosRecursiva(arrDinE, validosE, 0);
        if(validosE == 0){
            printf("No se encontraron empleados\n");
        }

}

void mostrarOrdenDniE(){

    stEmpleado * arrDinE;
    int validosE=0;
    validosE=ArchivoToArregloEmpleados(&arrDinE, validosE);
    ordenamientoInserccionEmpleado(arrDinE, validosE);
    mostrarArregloEmpleadosRecursiva(arrDinE, validosE, 0);
    if(validosE == 0){
            printf("No se encontraron empleados\n");
        }


}
///mostrar baja
void mostrarOrdenAlfabBajaE()
{
        stEmpleado* arrDinE;
        int validosE = 0;
        validosE = ArchivoToArregloEmpleadosInactivos(&arrDinE, validosE);
        ordenamientoSeleccionEmpleado(arrDinE, validosE);
        mostrarArregloEmpleadosRecursiva(arrDinE, validosE, 0);

        if(validosE == 0){
            printf("No se encontraron empleados dados de baja\n");
        }
}

void mostrarOrdenDniBajaE(){

    stEmpleado * arrDinE;
    int validosE=0;
    validosE=ArchivoToArregloEmpleadosInactivos(&arrDinE, validosE);
    ordenamientoInserccionEmpleado(arrDinE, validosE);
    mostrarArregloEmpleadosRecursiva(arrDinE, validosE, 0);
    if(validosE == 0){
            printf("No se encontraron empleados dados de baja\n");
        }

}
///mostrar activos
void mostrarOrdenAlfabEActivo()
{
        stEmpleado* arrDinE;
        int validosE = 0;
        validosE = ArchivoToArregloEmpleadosActivo(&arrDinE, validosE);
        //printf("LISTA DE EMPLEADOS ORDENADOS:\n");
        ordenamientoSeleccionEmpleado(arrDinE, validosE);
        mostrarArregloEmpleadosRecursiva(arrDinE, validosE, 0);
        if(validosE == 0){
            printf("No se encontraron empleados activos\n");
        }

}

void mostrarOrdenDniActivosE(){

    stEmpleado * arrDinE;
    int validosE=0;
    validosE=ArchivoToArregloEmpleadosActivo(&arrDinE, validosE);
    ordenamientoInserccionEmpleado(arrDinE, validosE);
    mostrarArregloEmpleadosRecursiva(arrDinE, validosE, 0);
    if(validosE == 0){
            printf("No se encontraron empleados activos\n");
        }

}

/// Calcular registros//////

int calcularRegistrosE(){

    int cant=0;

    FILE *buf;
    buf = fopen(archEmpleado, "rb");

    if(buf){
        fseek(buf, 0, 2);

        cant = ftell(buf)/ sizeof(stEmpleado);

    fclose(buf);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

int calcularRegistrosActivosE()
{

    int cant = 0;
    stEmpleado A;

    FILE *buff;
    buff = fopen(archEmpleado, "rb");

    if(buff){
        while(fread(&A, sizeof(stEmpleado), 1, buff))
        {
            if(A.estado == 1){
                cant++;
            }
        }

    fclose(buff);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

int calcularRegistrosInactivosE()
{
    int cant = 0;
    stEmpleado A;

    FILE *buff;
    buff = fopen(archEmpleado, "rb");

    if(buff){
        while(fread(&A, sizeof(stEmpleado), 1, buff))
        {
            if(A.estado == 0)
            {
                cant++;
            }
        }

    fclose(buff);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

///pasar de archivo a arreglo/////
int ArchivoToArregloEmpleados (stEmpleado** arrD, int validos){

    FILE* buf;
    stEmpleado A;

    int cantRegistrosE = calcularRegistrosE();

    *arrD = (stEmpleado*)malloc(sizeof(stEmpleado)*cantRegistrosE);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    buf = fopen(archEmpleado, "rb");

    if (buf){
        while(fread(&A, sizeof(stEmpleado), 1, buf) > 0 && validos < cantRegistrosE){
            (*arrD)[validos] = A;
            validos++;
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo\n");
        }


    return validos;
}

int ArchivoToArregloEmpleadosActivo (stEmpleado** arrD, int validos)
{

    FILE* buf;
    stEmpleado A;

    int cantRegistrosE = calcularRegistrosActivosE();

    *arrD = (stEmpleado*)malloc(sizeof(stEmpleado)*cantRegistrosE);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    buf = fopen(archEmpleado, "rb");

    if (buf){
        while(fread(&A, sizeof(stEmpleado), 1, buf) > 0 && validos < cantRegistrosE){
            if(A.estado == 1)
                {
                    (*arrD)[validos] = A;
                     validos++;
                }
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo\n");
        }


    return validos;
}

int ArchivoToArregloEmpleadosInactivos(stEmpleado** arrD, int validos)
{

    FILE* buf;
    stEmpleado A;

    int cantRegistrosE = calcularRegistrosInactivosE();

    *arrD = (stEmpleado*)malloc(sizeof(stEmpleado)*cantRegistrosE);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    buf = fopen(archEmpleado, "rb");

    if (buf){
        while(fread(&A, sizeof(stEmpleado), 1, buf) > 0 && validos < cantRegistrosE){
            if(A.estado == 0)
                {
                    (*arrD)[validos] = A;
                     validos++;
                }
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validos;
}

///mostrar arreglo
void mostrarArregloEmpleadosRecursiva(stEmpleado A[], int validos, int i){
    if (i < validos) {
        mostrarEmpleado(A[i]);
        mostrarArregloEmpleadosRecursiva(A, validos, i+1);
    }
}


///Cargar Empleado//////////////////////////////////////////////////////////////////////////////////////////////////////////////

stEmpleado cargarContraseniaEmpleado(stEmpleado A){
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

stEmpleado cargarEmpleado(){

    stEmpleado A;

    int flag=0, flag1=0;

    printf("Ingrese el nombre y apellido del empleado\n");
    fflush(stdin);
    gets(A.nYa);

    A=cargarContraseniaEmpleado(A);


    printf("Ingrese su DNI.\n");
    fflush(stdin);
    gets(A.dni);

    printf("Ingrese su fecha de nacimiento:\n");

    while(flag!=1){
        printf("Dia:");
        scanf("%d", &A.fechaN.dia);
        flag=validarDiaFecha(A.fechaN.dia);
        if(flag!=1){
            printf("Dia invalido. Vuelva a ingresar una fecha valida.\n");
        }
    }

    while(flag1!=1){
        printf("Mes:");
        scanf("%d", &A.fechaN.mes);
        flag1=validarMesFecha(A.fechaN.mes);
        if(flag1!=1){
            printf("Mes invalido. Vuelva a ingresar un mes valido.\n");
        }
    }

    printf("Anio:");
    scanf("%i", &A.fechaN.anio);

    printf("Ingrese su numero de telefono:\n");
    fflush(stdin);
    gets(A.tel);

    printf("Ingrese su sueldo:\n");
    fflush(stdin);
    scanf("%i", &A.sueldo);

    printf("Ingrese su puesto de trabajo:\n");
    fflush(stdin);
    gets(A.puesto);

    A.estado=1;

    return A;
}


void registrarEmpleado(){

    FILE *buf;
    buf=fopen(archEmpleado, "ab");
    stEmpleado A;

    if(buf){
        A=cargarEmpleado();
        fwrite(&A, sizeof(stEmpleado), 1, buf);
        fclose(buf);
        printf("Empleado registrado con exito.\n");
    }else{
        printf("No se pudo abrir el archivo.\n");
    }
}

stEmpleado busquedaEmpleadoInicioSesion (char dni[], char contrasenia[]){

    FILE* buf;
    buf=fopen(archEmpleado, "rb");
    stEmpleado A;
    int flag=0;

    if(buf)
    {
        while(flag != 1 && fread(&A, sizeof(stEmpleado), 1, buf)>0)
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

stEmpleado iniciarSesionEmpleado(){

    FILE *buf;
    buf = fopen(archEmpleado, "rb");
    stEmpleado A;
    char dni[10];
    char contrasenia[20];
    char contrasenia2[20];
    int flag=0;

    if(buf){
        while(flag!=1){

        printf("Ingrese el DNI:\n");
        fflush(stdin);
        gets(dni);

        printf("Ingrese contrasenia:\n");
        fflush(stdin);
        gets(contrasenia);
        A=busquedaEmpleadoInicioSesion(dni, contrasenia);

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


///Mostrar Empleado/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarEmpleado (stEmpleado A)
{
    printf("Nombre y apellido: %s.\n", A.nYa);
    printf("DNI: %s.\n", A.dni);
    printf("Tel: %s.\n", A.tel);
    printf("Sueldo: $%i.\n", A.sueldo);
    printf("Puesto: %s.\n", A.puesto);
    printf("\n");
}

///Modificar Empleado///////////////////////////////////////////////////////////////////////////////////////////////////////////
stEmpleado modificarNyAE(stEmpleado A)
{
    printf("Ingrese el nuevo nombre y apellido:\n");
    fflush(stdin);
    gets(A.nYa);

    return A;
}

stEmpleado modificarDniE(stEmpleado A)
{
    printf("Ingrese el nuevo DNI:\n");
    fflush(stdin);
    gets(A.dni);

    return A;
}

stEmpleado modificarTelE(stEmpleado A)
{
    printf("Ingrese el nuevo nro de telefono:\n");
    fflush(stdin);
    gets(A.tel);

    return A;
}

stEmpleado modificarSueldoE(stEmpleado A)
{
    printf("Ingrese el nuevo sueldo:\n");
    fflush(stdin);
    scanf("%i", &A.sueldo);

    return A;
}

stEmpleado modificarPuestoE(stEmpleado A)
{
    printf("Ingrese el nuevo puesto:\n");
    fflush(stdin);
    gets(A.puesto);

    return A;
}

void modificarEmpleado (char nYa[30]){

    stEmpleado aux;
    int flag = 0;
    int pos=0;

    FILE* buf;
    buf = fopen(archEmpleado, "r+b");

    if(buf){
        while((fread(&aux, sizeof(stEmpleado), 1, buf)>0)&& flag==0){
            if(strcmpi(aux.nYa, nYa) == 0){
                flag = 1;
            }else{
                pos++;
            }
        }
        fseek(buf, sizeof(stEmpleado) * pos, SEEK_SET);
        fread(&aux, sizeof(stEmpleado), 1, buf);

        aux = modificarDatosEmpleado(aux);

        fseek(buf, sizeof(stEmpleado)*(-1), SEEK_CUR);
        fwrite(&aux, sizeof(stEmpleado), 1, buf);
        fclose(buf);
    }
}

stEmpleado modificarDatosEmpleado(stEmpleado aux){

char control = 's';

        printf("1. Desea modificar el Nombre y apellido?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarNyAE(aux);
        }

        printf("2. Desea modificar el DNI?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarDniE(aux);
        }


        printf("5. Desea modificar el Telefono?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarTelE(aux);
        }

        printf("6. Desea modificar el Sueldo?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarSueldoE(aux);
        }

        printf("7. Desea modificar el Puesto de empleo?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarPuestoE(aux);
        }

        printf("Asi quedo modificado el Empleado: \n");
        mostrarEmpleado(aux);
        return aux;
}

///BUSCAR EMPLEADO/////////////////////////////////////////////////////////////////////////////////////////////////////////
void encontrarEmpleadoN(char N[30])
{
stEmpleado A;
int flag = 0;

FILE *buff;
buff = fopen(archEmpleado, "rb");

if(buff){
       while(fread(&A, sizeof(stEmpleado), 1, buff) && flag == 0)
        {
            if(strcmpi(A.nYa, N) ==0)
            {
                    flag = 1;
                    mostrarEmpleado(A);
            }
        }
    fclose(buff);
    if (flag == 0) {
            printf("El nombre ingresado no fue encontrado\n");
        }
    }else{
    printf("El archivo no se pudo abrir\n");
    }
}

void encontrarEmpleadoDni(char D[10])
{
stEmpleado A;
int flag = 0;

FILE *buff;
buff = fopen(archEmpleado, "rb");

if(buff){
       while(fread(&A, sizeof(stEmpleado), 1, buff) && flag == 0)
        {
            if(strcmpi(A.dni, D) == 0)
                {
                    flag = 1;
                    mostrarEmpleado(A);
                }
        }
        fclose(buff);
        if (flag == 0) {
            printf("El nombre ingresado no fue encontrado\n");
        }
    }
    else{
        printf("El archivo no se pudo abrir\n");
    }
}
///FILTRAR EMPLEADOS/////////////////////////////////////////////////////////////////////////////////////////////////////////
///Filtrar Empleado por Puesto
void filtrarEmpleadoPuesto(char P[10])
{
stEmpleado A;
int encontrado=0;
FILE *buff;
buff = fopen(archEmpleado, "rb");

if(buff){
       while(fread(&A, sizeof(stEmpleado), 1, buff))
        {
            if(strcmpi(A.puesto, P) == 0)
                {
                    mostrarEmpleado(A);
                    encontrado=1;
                }
        }
        fclose(buff);

     if (!encontrado){
            printf("El puesto ingresado no fue encontrado\n");
        }
}
    else{
        printf("El archivo no se pudo abrir\n");
    }
}

///Filtrar Empleado por Estado
void filtrarEmpleadoEstado(int E)
{
stEmpleado A;
int encontrado=0;
FILE *buff;
buff = fopen(archEmpleado, "rb");

if(buff){
       while(fread(&A, sizeof(stEmpleado), 1, buff))
        {
            if(A.estado == E)
                {
                    mostrarEmpleado(A);
                    encontrado=1;
                }
        }
        fclose(buff);
     if (!encontrado){
            printf("El estado ingresado no fue encontrado\n");
        }
}
    else{
        printf("El archivo no se pudo abrir\n");
    }
}

///Mostrar archivo de empleados//////////////////////////////////////////////////////////////////////////////////////////////

void mostrarArchivoEmpleado()
{
    stEmpleado A;

    FILE* buff;
    buff = fopen(archEmpleado, "rb");

    if(buff)
    {
        while(fread(&A, sizeof(stEmpleado), 1, buff))
        {
            mostrarEmpleado(A);
        }
        fclose(buff);
    }
    else
    {
        printf("El archivo no pudo abrirse\n");
    }
}

/// Dar de baja un empleado////////////////////////////////////////////////////////////////////////////////////////////////////
void darBajaEmpleado(char nYa[])
{
    stEmpleado aux;
    int flag = 0;
    int pos=0;

    FILE* buf;
    buf = fopen(archEmpleado, "r+b");

    if(buf){
        while((fread(&aux, sizeof(stEmpleado), 1, buf)>0)&& flag==0){
            if(strcmpi(aux.nYa, nYa) == 0){
                flag = 1;
            }else{
                pos++;
            }
        }
        fseek(buf, sizeof(stEmpleado) * pos, SEEK_SET);
        fread(&aux, sizeof(stEmpleado), 1, buf);

        aux = darBajaE(aux);

        fseek(buf, sizeof(stEmpleado)* (-1), SEEK_CUR);
        fwrite(&aux, sizeof(stEmpleado), 1, buf);
        fclose(buf);
    }
    else{
        printf("El archivo no se pudo abrir");
    }
}

stEmpleado darBajaE(stEmpleado aux)
{

       char control = 's';

        printf("¿Desea dar de baja este empleado?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux.estado = 0;
        }

        printf("Asi quedo modificado el empleado: \n");
        mostrarEmpleado(aux);

        return aux;
}
