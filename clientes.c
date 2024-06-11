#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <strings.h>
#include "clientes.h"
#include "viajes.h"
#include "ordenamientos.h"
#include "validaciones.h"

///CLIENTE ORDEN///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarOrdenAlfabCActivo()
{
            stCliente *arrDinC;
            int validosC=0;
            validosC= ArchivoToArregloClienteActivo(&arrDinC, validosC);
            //printf("LISTA DE CLIENTES ORDENADOS:\n");
            ordenamientoSeleccionCliente(arrDinC, validosC);
            MostrarArregloCliente(arrDinC, validosC);
            if(validosC == 0){
            printf("No se encontraron clientes activos\n");
        }
}

void mostrarOrdenDNIActivosC(){

    stCliente* arrDinC;
    int validosC=0;
    validosC=ArchivoToArregloClienteActivo(&arrDinC, validosC);
    ordenamientoInserccionCliente(arrDinC, validosC);
    MostrarArregloCliente(arrDinC, validosC);
    if(validosC == 0){
            printf("No se encontraron clientes activos\n");
        }
}

void mostrarOrdenAlfabBajaC()
{
            stCliente *arrDinC;
            int validosC = 0;
            validosC = ArchivoToArregloBajaClientes(&arrDinC, validosC);
            //printf("LISTA DE CLIENTES ORDENADOS:\n");
            ordenamientoSeleccionCliente(arrDinC, validosC);
            MostrarArregloCliente(arrDinC, validosC);
            if(validosC == 0){
            printf("No se encontraron clientes dados de baja\n");
        }

}

void mostrarOrdenDNIBajaC(){

    stCliente* arrDinC;
    int validosC=0;
    validosC=ArchivoToArregloBajaClientes(&arrDinC, validosC);
    ordenamientoInserccionCliente(arrDinC, validosC);
    MostrarArregloCliente(arrDinC, validosC);
    if(validosC == 0){
            printf("No se encontraron clientes dados de baja\n");
        }

}

/// muestra archivo completo ///

void mostrarOrdenAlfabC()
{
            stCliente *arrDinC;
            int validosC=0;
            validosC= ArchivoToArregloCliente(&arrDinC, validosC);
            //printf("LISTA DE CLIENTES ORDENADOS:\n");
            ordenamientoSeleccionCliente(arrDinC, validosC);
            MostrarArregloCliente(arrDinC, validosC);
            if(validosC == 0){
            printf("No se encontraron clientes\n");
        }
}

void mostrarOrdenDNIC(){

    stCliente* arrDinC;
    int validosC=0;
    validosC=ArchivoToArregloCliente(&arrDinC, validosC);
    ordenamientoInserccionCliente(arrDinC, validosC);
    MostrarArregloCliente(arrDinC, validosC);
    if(validosC == 0){
            printf("No se encontraron clientes\n");
        }
}

///calcular registros/////////////////////////////
int calcularRegistrosC(){

    int cant=0;

    FILE *buf;
    buf = fopen(archCliente, "rb");

    if(buf){
        fseek(buf, 0, 2);

        cant = ftell(buf)/ sizeof(stCliente);

    fclose(buf);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

int calcularRegistrosActivosC(){

    int cant = 0;
    stCliente A;

    FILE *buf;
    buf = fopen(archCliente, "rb");

    if(buf){
        while(fread(&A, sizeof(stCliente), 1, buf))
        {
            if(A.estado == 1){
                cant++;
            }
        }

    fclose(buf);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

int calcularRegistrosInactivosC(){

    int cant = 0;
    stCliente A;

    FILE *buf;
    buf = fopen(archCliente, "rb");

    if(buf){
        while(fread(&A, sizeof(stCliente), 1, buf))
        {
            if(A.estado == 0){
                cant++;
            }
        }

    fclose(buf);

    }else{

    printf("El archivo no se pudo abrir");

}
    return cant;
}

///pasar de archivo a arreglo////////////////////

int ArchivoToArregloCliente(stCliente** arrD, int validos){

    FILE* buf;
    stCliente A;

    int cantRegistrosC = calcularRegistrosC();

    *arrD = (stCliente*)malloc(sizeof(stCliente)*cantRegistrosC);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    buf = fopen(archCliente, "rb");

    if (buf){
        while(fread(&A, sizeof(stCliente), 1, buf) > 0 && validos < cantRegistrosC){
            (*arrD)[validos] = A;
            validos++;
        }
        fclose(buf);
    }else{
        printf("No se pudo abrir el archivo\n");
        }

    return validos;
}

int ArchivoToArregloClienteActivo(stCliente** arrD, int validos)
{

    FILE* buf;
    stCliente A;

    int cantRegistrosC = calcularRegistrosActivosC();

    *arrD = (stCliente*)malloc(sizeof(stCliente)*cantRegistrosC);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    buf = fopen(archCliente, "rb");

    if (buf){
        while(fread(&A, sizeof(stCliente), 1, buf) > 0 && validos < cantRegistrosC){
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

int ArchivoToArregloBajaClientes(stCliente** arrD, int validos)
{

    FILE* buf;
    stCliente A;

    int cantRegistrosC = calcularRegistrosInactivosC();

    *arrD = (stCliente*)malloc(sizeof(stCliente)*cantRegistrosC);

    if (*arrD == NULL) {
        printf("No se pudo asignar memoria\n");
        return validos;
    }

    buf = fopen(archCliente, "rb");

    if (buf){
        while(fread(&A, sizeof(stCliente), 1, buf) > 0 && validos < cantRegistrosC){
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

///ordenar arreglo/////////////////////////////////

void ordenarArrDinamicoClientes (stCliente** arrD, int validos){

    ordenamientoSeleccionCliente(*arrD, validos);

}
///mostrar arreglo/////////////////////////////////////////////////

void MostrarArregloCliente(stCliente A[], int validos){

int i;

printf("El contenido del arreglo:\n");

for(i=0; i<validos; i++){
    mostrarCliente(A[i]);
    }
}
///Cargar cliente/////////////////////////////////////////////////////////////////////////////////////////////////////////////

stCliente cargarContraseniaCliente(stCliente A)
{
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

stCliente cargarCliente()
{
    stCliente A;
    int flag=0, flag1=0;

    printf("Ingrese el nombre y apellido del cliente\n");
    fflush(stdin);
    gets(A.nYa);

    A=cargarContraseniaCliente(A);

    printf("Ingrese el DNI del cliente\n");
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

    printf("Ingrese el genero del cliente M/F (En mayuscula)\n");
    fflush(stdin);
    scanf("%c", &A.genero);

    while((A.genero != 'M') && (A.genero !='F')){
        printf("\nSexo erroneo, ingrese nuevamente. ");
        fflush(stdin);
        scanf("%c", &A.genero);
    }

    printf("Ingrese el numero de telefono del cliente\n");
    fflush(stdin);
    gets(A.tel);

    printf("Ingrese el domicilio del cliente\n");
    A.dom = cargarDomicilio();

    printf("Ingrese el viaje del cliente por ID\n\n");
    int id;
    mostrarArchivoViaje();
    printf("ID: ");
    scanf("%d", &id);
    A.v=buscarViajePorID(id);

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

void registrarCliente() {

    FILE *buf;
    buf=fopen(archCliente, "ab");
    stCliente A;

    if(buf){
        A=cargarCliente();
        fwrite(&A, sizeof(stCliente), 1, buf);
        fclose(buf);
        printf("Cliente registrado con exito.\n");
    }else{
        printf("No se pudo abrir el archivo.\n");
    }
}

stCliente busquedaClienteInicioSesion (char dni[], char contrasenia[])
{
    FILE* buf;
    buf=fopen(archCliente, "rb");
    int flag=0;
    stCliente A;

    if(buf)
    {
        while(flag != 1 && fread(&A, sizeof(stCliente), 1, buf)>0)
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

stCliente iniciarSesionCliente() {

    FILE *buf;
    buf = fopen(archCliente, "rb");
    char dni[10];
    char contrasenia[20];
    char contrasenia2[20];
    stCliente A;
    int flag=0;

    if(buf){
        while(flag!=1){

        printf("Ingrese el DNI:\n");
        fflush(stdin);
        gets(dni);

        printf("Ingrese contrasenia:\n");
        fflush(stdin);
        gets(contrasenia);
        A=busquedaClienteInicioSesion(dni, contrasenia);

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

void mostrarCliente(stCliente A)
{
    printf("Nombre y Apellido: %s\n", A.nYa);
    printf("Fecha de nacimiento: %i/%i/%i\n", A.fechaN.dia, A.fechaN.mes, A.fechaN.anio);
    printf("Genero: %c\n", A.genero);
    printf("DNI: %s\n", A.dni);
    printf("Telefono: %s\n", A.tel);
    mostrarDomicilio(A.dom);
    mostrarViaje(A.v);
    printf("\n");
}

///Mostrar archivo Clientes/////////////////

void mostrarArchivoCliente()
{
    stCliente A;

    FILE* buff;
    buff = fopen(archCliente, "rb");

    if(buff)
    {
        while(fread(&A, sizeof(stCliente), 1, buff))
        {
            mostrarCliente(A);
        }
        fclose(buff);
    }
    else
    {
        printf("El archivo no pudo abrirse\n");
    }
}


///Modificar Cliente///////////////////////////////////////////////////////////////////////////////////////////////////////////
void modificarCliente (char nYa[30]){

    stCliente aux;
    int flag = 0;
    int pos=0;

    FILE* buf;
    buf = fopen(archCliente, "r+b");

    if(buf){
        while((fread(&aux, sizeof(stCliente), 1, buf)>0)&& flag==0){
            if(strcmpi(aux.nYa, nYa) == 0){
                flag = 1;
            }else{
                pos++;
            }
        }
        fseek(buf, sizeof(stCliente) * pos, SEEK_SET);
        fread(&aux, sizeof(stCliente), 1, buf);

        aux = modificarDatosCliente(aux);

        fseek(buf, sizeof(stCliente)* (-1), SEEK_CUR);
        fwrite(&aux, sizeof(stCliente), 1, buf);
        fclose(buf);
    }
}

stCliente modificarDatosCliente(stCliente aux)
{

char control = 's';

        printf("1. Desea modificar el Nombre y apellido?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarNyAC(aux);
        }

        printf("2. Desea modificar la Fecha de nacimiento?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarFechaNacC(aux);
        }

        printf("3. Desea modificar el Genero?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarGeneroC(aux);
        }

        printf("4. Desea modificar el DNI?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarDniC(aux);
        }

        printf("5. Desea modificar el Telefono?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarTelC(aux);
        }

        printf("6. Desea mdificar el Domicilio?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarDomicilioC(aux);
        }

        printf("7. Desea modificar el Viaje?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux = modificarViajeC(aux);
        }

        printf("Asi quedo modificado el cliente: \n");
        mostrarCliente(aux);
        return aux;
}

stCliente modificarNyAC(stCliente A)
{
    printf("Ingrese el nuevo nombre y apellido:\n");
    fflush(stdin);
    gets(A.nYa);

    return A;
}

stCliente modificarFechaNacC(stCliente A)
{
    int flag=0, flag1=0;

    while(flag!=1){
        printf("Ingrese su fecha de nacimiento para modificar la anterior:\n");
        printf("Dia:");
        scanf("%d", &A.fechaN.dia);
        flag=validarDiaFecha(A.fechaN.dia);
        if(flag==0){
            printf("Dia invalido. Vuelva a ingresar una fecha valida.\n");
        }
    }

    while(flag1!=1){
        printf("Mes:");
        scanf("%d", &A.fechaN.mes);
        flag1=validarMesFecha(A.fechaN.mes);
        if(flag1==0){
            printf("Mes invalido. Vuelva a ingresar un mes valido.\n");
        }
    }

    printf("Anio:");
    scanf("%i", &A.fechaN.anio);

    return A;
}

stCliente modificarGeneroC(stCliente A)
{
    printf("Ingrese el nuevo genero:\n");
    fflush(stdin);
    scanf("%c", &A.genero);

    return A;
}

stCliente modificarDniC(stCliente A)
{
    printf("Ingrese la nueva fecha de nacimiento:\n");
    fflush(stdin);
    gets(A.dni);

    return A;
}

stCliente modificarTelC(stCliente A)
{
    printf("Ingrese la nueva fecha de nacimiento:\n");
    fflush(stdin);
    gets(A.tel);

    return A;
}

stCliente modificarDomicilioC(stCliente A)
{
    A.dom = modificarDomicilio(A.dom);

    return A;
}

stCliente modificarViajeC(stCliente A)
{
    int id;

    printf("Ingrese el ID del viaje que desea encontrar.\n");
    fflush(stdin);
    scanf("%d", &id);

    A.v = encontrarViajeId(id);

    return A;
}

///Dar Baja Cliente//////////////////////////////////////////////////////////////////////////////////////////////////////////
void darBajaCliente (char nYa[]){

    stCliente aux;
    int flag = 0;
    int pos=0;

    FILE* buf;
    buf = fopen(archCliente, "r+b");

    if(buf){
        while((fread(&aux, sizeof(stCliente), 1, buf)>0)&& flag==0){
            if(strcmpi(aux.nYa, nYa) == 0){
                flag = 1;
            }else{
                pos++;
            }
        }
        fseek(buf, sizeof(stCliente) * pos, SEEK_SET);
        fread(&aux, sizeof(stCliente), 1, buf);

        aux = darBajaC(aux);

        fseek(buf, sizeof(stCliente)* (-1), SEEK_CUR);
        fwrite(&aux, sizeof(stCliente), 1, buf);
        fclose(buf);
    }
}

stCliente darBajaC(stCliente aux)
{

    char control = 's';

        printf("1. Desea dar de baja este cliente?.\n");
        fflush(stdin);
        scanf("%c", &control);

        if(control=='s')
        {
            aux.estado = 0;
        }

        printf("Asi quedo modificado el cliente: \n");
        mostrarCliente(aux);

        return aux;
}


///DOMICILIO////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///Cargar Domicilio

stDomicilio cargarDomicilio()
{
    stDomicilio A;

	printf("Ingrese calle: \n");
	fflush(stdin);
	gets(A.calle);

	printf("Ingrese numero de calle: \n");
            fflush(stdin);
	scanf("%i", &A.num);

	printf("Ingrese localidad: \n");
	fflush(stdin);
	gets(A.localidad);

	return A;
	}

///Mostrar Domicilio

void mostrarDomicilio(stDomicilio A)
{
	printf("Calle: %s\n", A.calle);
	printf("Numero de calle: %i\n", A.num);
	printf("Localidad: %s\n", A.localidad);
}

///Modificar Domicilio

stDomicilio modificarDomicilio(stDomicilio A)
{
    char control = 'n';

    printf("Desea cambiar la calle?\n");
    fflush(stdin);
    scanf("%c", &control);

    if(control == 's'){
       	printf("Ingrese la calle para modificar la anterior: \n");
	    fflush(stdin);
	    gets(A.calle);
    }

    printf("Desea cambiar el numero de calle?\n");
    fflush(stdin);
    scanf("%c", &control);

    if(control == 's'){
        printf("Ingrese el numero de calle para modificar la anterior: \n");
	    fflush(stdin);
	    scanf("%i", &A.num);
    }

    printf("Desea cambiar la localidad?\n");
    fflush(stdin);
    scanf("%c", &control);

    if(control == 's'){
    printf("Ingrese la localidad para modificar la anterior: \n");
	fflush(stdin);
	gets(A.localidad);
    }

	return A;
}

///BUSCAR CLIENTE///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void encontrarClienteN(char N[30])
{
stCliente A;
int flag = 0;

FILE *buff;
buff = fopen(archCliente, "rb");

if(buff){
       while(fread(&A, sizeof(stCliente), 1, buff) && flag == 0)
        {
            if(strcmpi(A.nYa, N) ==0)
            {
                    flag = 1;
                    mostrarCliente(A);
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

///Encontrar Cliente por DNI///////////
void encontrarClienteDni(char D[10])
{
stCliente A;
int flag = 0;

FILE *buf;
buf = fopen(archCliente, "rb");

if(buf){
       while(fread(&A, sizeof(stCliente), 1, buf) && flag == 0)
        {
            if(strcmpi(A.dni, D) == 0)
                {
                    flag = 1;
                    mostrarCliente(A);
                }
        }

    fclose(buf);
    if (flag == 0) {
            printf("El DNI ingresado no fue encontrado\n");
    }
}
else{
    printf("El archivo no se pudo abrir\n");
}
}

///FILTRAR CLIENTES/////////////////////////////////////////////////////////////////////////////////////////////////////////////
///Filtrar Cliente por Genero
void filtrarClienteGenero(char G)
{
stCliente A;
int encontrado = 0;

FILE *buff;
buff = fopen(archCliente, "rb");

if(buff){
       while(fread(&A, sizeof(stCliente), 1, buff))
        {
           if(A.genero == G)
                {
                    mostrarCliente(A);
                    encontrado=1;
                }
        }
        fclose(buff);
        if (!encontrado){
            printf("El genero ingresado no fue encontrado\n");
        }
}
    else{
        printf("El archivo no se pudo abrir\n");
    }
}

///Filtrar Clientes por Estado
void filtrarClienteEstado(int E)
{
stCliente A;
int encontrado=0;
FILE *buff;
buff = fopen(archCliente, "rb");

if(buff){
       while(fread(&A, sizeof(stCliente), 1, buff))
        {
            if(A.estado == E)
                {
                    mostrarCliente(A);
                    encontrado=1;
                }
        }
        fclose(buff);
        if (!encontrado){
            printf("El estado ingresado no fue encontrado\n");
        }
}else{
        printf("El archivo no se pudo abrir\n");
    }
}

///Filtrar Cliente por Viaje
void filtrarClienteViaje(int ID)
{
stCliente A;
int encontrado=0;
FILE *buff;
buff = fopen(archCliente, "rb");

if(buff){
       while(fread(&A, sizeof(stCliente), 1, buff))
        {
           if(A.v.id == ID)
                {
                    mostrarCliente(A);
                    encontrado=1;
                }
        }
        fclose(buff);
        if (!encontrado){
            printf("El ID ingresado no fue encontrado\n");
        }
    }
    else{
        printf("El archivo no se pudo abrir\n");
    }
}

