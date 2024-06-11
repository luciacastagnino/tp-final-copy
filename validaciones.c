#include "validaciones.h"
#include "string.h"

// validacion inicio sesion/registro

int lenghtContrasenia(char contrasenia[]){

    int flag=0;
    if(strlen(contrasenia)>8){
        flag=1;
    }
    return flag;
}

int validacionContrasenia (char contrasenia[], char contrasenia2[]){

    int flag=0;
    if(strcmp(contrasenia, contrasenia2)==0){
        flag=1;
    }
    return flag;
}
