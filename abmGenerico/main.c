#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "estructuraUno.h"
#include "estructuraDos.h"
#include "funcionesGenericas.h"
#include "menu.h"
#include "hardcode.h"
#include "validaciones.h"


int main()
{
    sCosasUno arrayCosasUno[LIMITE];
    sCosasDos arrayCosasDos[LIMITE];

    inicializarEstadoCosasUno(arrayCosasUno, LIMITE);
    inicializarEstadoCosasDos(arrayCosasDos, LIMITE);

    int opcion;
    char confirmacion;
    int flagUno;
    int flagDos;
    int lugarLibre;


    do
    {
        opcion = menuPrincipal();
        switch(opcion)
        {
        case 1:
            lugarLibre=buscarLibreUno(arrayCosasUno, LIMITE);
            if (lugarLibre!=-1)
            {
                opcion = subMenuAltas();
                switch(opcion)
                {
                case 1:
                    agregarDato(arrayCosasUno, LIMITE);
                    break;
                case 2:
                    agregarDatoDos(arrayCosasDos, LIMITE);
                    break;
                }
            }
            else
            {
                printf("No hay mas espacio\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            flagUno = datoCargado(arrayCosasUno, LIMITE);
            flagDos = datoCargadoDos(arrayCosasDos, LIMITE);
            if (flagUno == 0 || flagDos == 0)
            {
                opcion = subMenuListar();
                switch(opcion)
                {
                case 1:
                    if (flagUno == 0)
                    {
                        mostrarListaCosas(arrayCosasUno, LIMITE);
                    }
                    else
                    {
                        printf("No hay datos cargados.\n");
                    }
                    break;
                case 2:
                    if (flagDos == 0)
                    {
                        mostrarListaCosasDos(arrayCosasDos, LIMITE);
                    }
                    else
                    {
                        printf("No hay datos cargados.\n");
                    }
                    break;
                }
            }
            else
            {
                printf("No hay datos cargados.\n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            flagUno = datoCargado(arrayCosasUno, LIMITE);
            flagDos = datoCargadoDos(arrayCosasDos, LIMITE);
            if (flagUno == 0 || flagDos == 0)
            {
                opcion = subMenuBaja();
                switch(opcion)
                {
                case 1:
                    if (flagUno == 0)
                    {
                        mostrarListaCosas(arrayCosasUno, LIMITE);
                        eliminarCosa(arrayCosasUno, LIMITE);
                    }
                    else
                    {
                        printf("No hay datos cargados.\n");
                    }
                    break;
                case 2:
                    if (flagDos == 0)
                    {
                        mostrarListaCosasDos(arrayCosasDos, LIMITE);
                        eliminarCosaDos(arrayCosasDos, LIMITE);
                    }
                    else
                    {
                        printf("No hay datos cargados.\n");
                    }
                    break;
                }
            }
            else
            {
                printf("No hay datos cargados.\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            flagUno = datoCargado(arrayCosasUno, LIMITE);
            flagDos = datoCargadoDos(arrayCosasDos, LIMITE);
            if (flagUno == 0 || flagDos == 0)
            {
                opcion = subMenuModificar();
                switch(opcion)
                {
                case 1:
                    if (flagUno == 0)
                    {
                        mostrarListaCosas(arrayCosasUno, LIMITE);
                        modificarCosa(arrayCosasUno, LIMITE);
                        do
                        {
                            confirmacion = getChar("Desea seguir modificando datos? S/N ");
                            switch(confirmacion)
                            {
                            case 's':
                                modificarCosa(arrayCosasUno, LIMITE);
                                break;
                            case 'n':
                                system("cls");
                                break;
                            default:
                                printf("Ingrese una opcion valida.\n");
                                break;
                            }
                        }
                        while (confirmacion != 'n');
                    }
                    else
                    {
                        printf("No hay datos cargados.\n");
                    }
                    break;
                case 2:
                    if (flagDos == 0)
                    {
                        mostrarListaCosasDos(arrayCosasDos, LIMITE);
                        modificarCosaDos(arrayCosasDos, LIMITE);
                        do
                        {
                            confirmacion = getChar("Desea seguir modificando datos? S/N ");
                            switch(confirmacion)
                            {
                            case 's':
                                modificarCosaDos(arrayCosasDos, LIMITE);
                                break;
                            case 'n':
                                system("cls");
                                break;
                            default:
                                printf("Ingrese una opcion valida.\n");
                                break;
                            }
                        }
                        while (confirmacion != 'n');
                    }
                    else
                    {
                        printf("No hay datos cargados.\n");
                    }
                }
            }

            else
            {
                printf("No hay datos cargados.\n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            printf("APROBAME PLOX\n");
            system("pause");
            system("cls");
            break;
        case 777:
            hardcodeUno(arrayCosasUno, LIMITE, 1, 1, "caca", 'c', 5 , 0);
            hardcodeUno(arrayCosasUno, LIMITE, 2, 3, "pis", 's', 3 , 0);
            hardcodeDos(arrayCosasDos, LIMITE, 1, 2, "hola", 'h', 7, 0);
            hardcodeDos(arrayCosasDos, LIMITE, 2, 8, "chau", 'c', 10, 0);
            system("cls");
            break;
        }
    }
    while(opcion != 5);
    return 0;
}
