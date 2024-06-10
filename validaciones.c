#include "validaciones.h"

// validacion inicio sesion/registro

void lenghtContrasenia(char contrasenia){

    if(srtlen(contrasenia)<8){
        return 0;
    }
    return 1;
}

int validacionContrasenia (char contrasenia[], char contrasenia2[]){

    int flag=0;
    if(strcmp(contrasenia, contrasenia2)==0){
        flag=1;
    }
    return flag;
}
