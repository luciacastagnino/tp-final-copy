#include "calendario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viajes.h"

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"

///Funcion de carga del mes///
///En cada case cambia algo debido a la cantidad dias y dependiendo del primer dia que comienza cada mes///
void CargarCalendario(int calendario[6][7], int calendarioOpciones)
{
    switch (calendarioOpciones)
   {

case 1:          ///CARGAR ENERO///
{
        printf("\n Enero: \n\n");
        int d=0;
        int dia=1;

        for(int a=0;a<6;a++)
       {
          for(int b=0;b<7;b++)
         {
            if (d<31)
           {
             calendario[a][b]=dia;
             dia++;
             d++;
           }
            else
           {
             dia=1;
             d=0;
             calendario[a][b]=dia;
             dia++;
           }
         }
       }
       break;
}

case 2:          ///CARGAR FEBRERO///
{

    printf("\n Febrero: \n\n");
    int d=26;
    int dia=29;
    for(int a=0;a<6;a++)
   {
       for(int b=0;b<7;b++)
      {
          if (d==29)
        {
            dia=1;
            d=1;
            calendario[a][b]=dia;
            dia++;
        }
          else
        {
            calendario[a][b]=dia;
            dia++;
            d++;
        }
      }
    }
    break;
}

case 3:          ///CARGAR MARZO///
{
    printf("\n Marzo: \n\n");
    int d=27;
    int dia=26;

    for(int a=0;a<6;a++)
   {
      for(int b=0;b<7;b++)
     {
         if (d<31)
        {
            calendario[a][b]=dia;
            dia++;
            d++;
        }
         else
        {
            dia=1;
            d=1;
            calendario[a][b]=dia;
            dia++;
        }
     }
   }
     break;
}

case 4:          ///CARGAR ABRIL///
{
        printf("\n Abril: \n\n");
        int d=0;
        int dia=1;

        for(int a=0;a<6;a++)
       {
          for(int b=0;b<7;b++)
         {
            if (d==30)
           {
             dia=1;
             d=0;
             calendario[a][b]=dia;
             dia++;
           }
            else
           {
             calendario[a][b]=dia;
             dia++;
             d++;
           }
         }
       }
       break;
}

case 5:          ///CARGAR MAYO///
{
        printf("\n Mayo: \n\n");
        int d=29;
        int dia=29;

        for(int a=0;a<6;a++)
       {
          for(int b=0;b<7;b++)
         {
            if (d==31)
           {
             dia=1;
             d=1;
             calendario[a][b]=dia;
             dia++;
           }
            else
           {
             calendario[a][b]=dia;
             dia++;
             d++;
           }
         }
       }
       break;
}
case 6:          ///CARGAR JUNIO///
{
        printf("\n Junio: \n\n");
        int d=25;
        int dia=27;

        for(int a=0;a<6;a++)
       {
          for(int b=0;b<7;b++)
         {
            if (d==30)
           {
             dia=1;
             d=1;
             calendario[a][b]=dia;
             dia++;
           }
            else
           {
             calendario[a][b]=dia;
             dia++;
             d++;
           }
         }
       }
       break;
}
case 7:          ///CARGAR JULIO///
{
        printf("\n Julio: \n\n");
        int d=0;
        int dia=1;

        for(int a=0;a<6;a++)
       {
          for(int b=0;b<7;b++)
         {
            if (d==31)
           {
             dia=1;
             d=0;
             calendario[a][b]=dia;
             dia++;
           }
            else
           {
             calendario[a][b]=dia;
             dia++;
             d++;
           }
         }
       }
       break;
}

case 8:          ///CARGAR AGOSTO///
{
        printf("\n Agosto: \n\n");
        int d=28;
        int dia=29;

        for(int a=0;a<6;a++)
       {
          for(int b=0;b<7;b++)
         {
            if (d==31)
           {
             dia=1;
             d=1;
             calendario[a][b]=dia;
             dia++;
           }
            else
           {
             calendario[a][b]=dia;
             dia++;
             d++;
           }
         }
       }
       break;
}

case 9:          ///CARGAR SEPTIEMBRE///
{
        printf("\n Septiembre: \n\n");
        int d=24;
        int dia=26;

        for(int a=0;a<6;a++)
       {
          for(int b=0;b<7;b++)
         {
            if (d==30)
           {
             dia=1;
             d=1;
             calendario[a][b]=dia;
             dia++;
           }
            else
           {
             calendario[a][b]=dia;
             dia++;
             d++;
           }
         }
       }
       break;
}

case 10:          ///CARGAR OCTUBRE///
{
        printf("\n Octubre: \n\n");
        int d=30;
        int dia=30;

        for(int a=0;a<6;a++)
       {
          for(int b=0;b<7;b++)
         {
            if (d==31)
           {
             dia=1;
             d=1;
             calendario[a][b]=dia;
             dia++;
           }
            else
           {
             calendario[a][b]=dia;
             dia++;
             d++;
           }
         }
       }
       break;
}

case 11:          ///CARGAR NOVIEMBRE///
{
        printf("\n Noviembre: \n\n");
        int d=26;
        int dia=28;

        for(int a=0;a<6;a++)
       {
          for(int b=0;b<7;b++)
         {
            if (d==30)
           {
             dia=1;
             d=1;
             calendario[a][b]=dia;
             dia++;
           }
            else
           {
             calendario[a][b]=dia;
             dia++;
             d++;
           }
         }
       }
       break;
}

case 12:          ///CARGAR DICIEMBRE///
{
        printf("\n Diciembre: \n\n");
        int d=25;
        int dia=25;

        for(int a=0;a<6;a++)
       {
          for(int b=0;b<7;b++)
         {
            if (d==31)
           {
             dia=1;
             d=1;
             calendario[a][b]=dia;
             dia++;
           }
            else
           {
             calendario[a][b]=dia;
             dia++;
             d++;
           }
         }
       }
       break;
}
}
}

///Funcion para mostrar el calendario del mes elegido///
void MostrarCalendario(int calendario[6][7], stViaje viajes[], int numViajes, int mesSeleccionado) {
    printf("   L       M       M       J       V       S       D\n\n");

    for(int a = 0; a < 6; a++) {
        for(int b = 0; b < 7; b++) {
            int dia = calendario[a][b];
            int viajeEnFecha = 0;
            int viajeRegreso = 0;

            for(int i = 0; i < numViajes; i++) {
                if ((viajes[i].fechaP.dia == dia) && (viajes[i].fechaP.mes == mesSeleccionado)) {
                    viajeEnFecha = 1;
                }
                if (viajes[i].fechaR.dia == dia && viajes[i].fechaR.mes == mesSeleccionado) {
                        viajeRegreso = 1;
                    }

            }

             if (viajeEnFecha && viajeRegreso) {
                    printf(COLOR_RED);
                } else if (viajeEnFecha) {
                    printf(COLOR_GREEN);
                } else if (viajeRegreso) {
                    printf(COLOR_BLUE);
                } else {
                    printf(COLOR_RESET);
                }

            if(dia <= 9) {
                printf(" | %i  | ", dia);
            } else {
                printf(" | %i | ", dia);
            }
        }
        printf(COLOR_RESET "\n\n");
    }
}

void llamadaCalendario()
{
            int calendario[6][7];

            char controlCalendario='s';
            while(controlCalendario=='s')
             {
                int calendarioOpciones;
                printf("Ingrese el numero de mes que desea ver: ");
                scanf("%i", &calendarioOpciones);

                stViaje *arrDinV;
                int validosV = 0;
                validosV = ArchivoToArregloViajeActivo(&arrDinV, validosV);

                CargarCalendario(calendario, calendarioOpciones);
                MostrarCalendario(calendario, arrDinV, validosV, calendarioOpciones);

                printf("Desea ver otro mes? s/n");
                fflush(stdin);
                scanf("%c",&controlCalendario);
             }
}

