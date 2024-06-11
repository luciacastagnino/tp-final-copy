#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "menu.h"
#include "empleados.h"
#include "clientes.h"
#include "ventas.h"
#include "viajes.h"
#include "home.h"
#include "admin.h"
#include "validaciones.h"

int main()
{
    int op, opcion;

    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///               ////              ////       /////////              /////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////         ///////   ////////////////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   ///    //////   ////////////////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   /////   /////   ////////////////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   //////   ////              /////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   //////   ////   ////////////////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   /////   /////   ////////////////////////////////////////////////////////////\n");
    printf("///    ///////////////   ////////   ////   ////   //////   ////////////////////////////////////////////////////////////\n");
    printf("///               ////              ////        ////////               ////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                ////          //////              ////   //////////////   ////               ////   ////////////////\n");
    printf("/////////   ///////////   /////   /////   ////////   /////   ////////////   /////   ////////////////   ////////////////\n");
    printf("/////////   ///////////   /////    ////   ////////   /////   ///////////   //////   ////////////////   ////////////////\n");
    printf("/////////   ///////////   ////    /////   ////////   //////   /////////   ///////   ////////////////   ////////////////\n");
    printf("/////////   ///////////         ///////              ///////   ///////   ////////               ////   ////////////////\n");
    printf("/////////   ///////////   //   ////////   ////////   ////////   /////   /////////   ////////////////   ////////////////\n");
    printf("/////////   ///////////   ///   ///////   ////////   /////////   ///   //////////   ////////////////   ////////////////\n");
    printf("/////////   ///////////   ////   //////   ////////   //////////   /   ///////////   ////////////////   ////////////////\n");
    printf("/////////   ///////////   /////   /////   ////////   ///////////     ////////////               ////               ////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\n");

    system("pause");
    system("cls");
    stAdmin admin;
    stEmpleado empleado;
    stCliente cliente;
    printf("Bienvenido!\n\n");
    printf("1. Iniciar sesion\n");
    printf("2. Registro\n");
    fflush(stdin);
    scanf("%d", &op);
    do{
    switch(op)
    {
    case 1:
        {
            printf("Ingrese su tipo de usuario:\n");
            printf("1. Empleado\n");
            printf("2. Cliente\n");
            printf("3. Salir\n");
            scanf("%i", &opcion);
            if(opcion==-1){
                admin=iniciarSesionAdmin();
                printf("Bienvenido/a %s.\n", admin.nYa);
                    menuAdmin();
            }else if(opcion==1){
                empleado=iniciarSesionEmpleado();
                printf("Bienvenido/a %s.\n", empleado.nYa);
                    //menuEmpleados();
            }else if(opcion==2){
                cliente=iniciarSesionCliente();
                printf("Bienvenido/a %s.\n", cliente.nYa);
                    //menuClientes();
            }
            break;
        }
    case 2:
        {
            printf("Ingrese su tipo de usuario:\n");
            printf("1. Empleado\n");
            printf("2. Cliente\n");
            printf("3. Salir\n");
            int option;
            scanf("%i", &option);
            if(option==1){
                registrarEmpleado();
            }else if(option==2){
                registrarCliente();
            }
            break;
        }
    default:
        printf("No existe la opcion.\n");
        break;
        }}while(op!=4);

    return 0;
}

