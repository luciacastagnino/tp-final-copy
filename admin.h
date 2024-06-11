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

stAdmin cargarContraseniaAdmin(stAdmin A){
stAdmin cargarAdmin();
void registrarAdmin();

stAdmin busquedaAdminInicioSesion (char dni[], char contrasenia[]);
stAdmin iniciarSesionAdmin();
void mostrarAdmin(stAdmin A);
void mostrarArchivoAdmin();

#endif // ADMIN_H_INCLUDED
