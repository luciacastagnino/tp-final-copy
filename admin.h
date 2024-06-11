#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED


static const char archAdmin[] = {"archivoAdmin.bin"};

// ESTRUCTURA ADMIN

typedef struct{
    char nYa[50];
    char dni[10];
    char contrasenia[30];
    int estado;
}stAdmin;

// inicio de sesion

stAdmin arBuscarUsuarioLoginAdmin (char dni[], char contrasenia[]);
stAdmin iniciarSesionAdmin();

// registro

void registroAdministrador();
stAdmin cargarAdmin();
void cargarArchivoAdmin();
void mostrarAdmin (stAdmin A);

// perfil

void mostrarPerfilAdmin (char nYa[]);

// modificacion

void modificarAdmin (char nYa[]);

#endif // ADMIN_H_INCLUDED
