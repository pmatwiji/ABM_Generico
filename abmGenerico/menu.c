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

int menuPrincipal()
{
    int opcion;
    opcion = getInt("=====================================================================\n"
                    "||                              MENU:                              ||\n"
                    "|| 1. Alta                                                         ||\n"
                    "||                                                                 ||\n"
                    "|| 2. Listar                                                       ||\n"
                    "||                                                                 ||\n"
                    "|| 3. Baja                                                         ||\n"
                    "||                                                                 ||\n"
                    "|| 4. Modificar                                                    ||\n"
                    "||                                                                 ||\n"
                    //"5. Baja director\n"
                    //"6. Mostrar\n"
                    "|| 5. Salir                                                        ||\n"
                    "||                                                                 ||\n"
                    "=====================================================================\n"
                    "Ingrese una opcion: ");

    while((opcion < 0 && opcion != 777) || (opcion > 5  && opcion != 777))
    {
        printf("Ingrese una opcion valida\n");
        system("pause");
        system("cls");
        opcion = getInt("=====================================================================\n"
                        "||                              MENU:                              ||\n"
                        "|| 1. Alta                                                         ||\n"
                        "||                                                                 ||\n"
                        "|| 2. Listar                                                       ||\n"
                        "||                                                                 ||\n"
                        "|| 3. Baja                                                         ||\n"
                        "||                                                                 ||\n"
                        "|| 4. Modificar                                                    ||\n"
                        "||                                                                 ||\n"
                        //"|| 5. Baja director\n"
                        //"6. Mostrar\n"
                        "|| 5. Salir                                                        ||\n"
                        "||                                                                 ||\n"
                        "=====================================================================\n"
                        "Ingrese una opcion: ");
    }
    return opcion;
}

int subMenuAltas()
{
    int opcion;
    opcion = getInt(" 1. Agregar datos a Cosas Uno\n"
                    " 2. Agregar datos a Cosas Dos\n");

    while(opcion < 0 || opcion > 2)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        " 1. Agregar datos a Cosas Uno\n"
                        " 2. Agregar datos a Cosas Dos\n");
    }
    return opcion;
//    switch(opcion)
//    {
//    case 1:
//        agregarDato(arrayCosasUno, LIMITE);
//        break;
//    case 2:
//        agregarDatoDos(arrayCosasDos, LIMITE);
//        break;
//    }
}

int subMenuListar()
{
    int opcion;
    opcion = getInt(" 1. Mostrar datos de Cosas Uno\n"
                    " 2. Mostrar datos de Cosas Dos\n");

    while(opcion < 0 || opcion > 2)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        " 1. Mostrar datos de Cosas Uno\n"
                        " 2. Mostrar datos de Cosas Dos\n");
    }
    return opcion;
}

int subMenuBaja()
{
    int opcion;
    opcion = getInt(" 1. Dar de baja elemento de Cosas Uno\n"
                    " 2. Dar de baja elemento de Cosas Dos\n");

    while(opcion < 0 || opcion > 2)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        " 1. Dar de baja elemento de Cosas Uno\n"
                        " 2. Dar de baja elemento de Cosas Dos\n");
    }
    return opcion;
}

int subMenuModificar()
{
    int opcion;
    opcion = getInt(" 1. Modificar elemento de Cosas Uno\n"
                    " 2. Modificar elemento de Cosas Dos\n");

    while(opcion < 0 || opcion > 2)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        " 1. Modificar elemento de Cosas Uno\n"
                        " 2. Modificar elemento de Cosas Dos\n");
    }
    return opcion;
}
int subMenuModificarUno()
{
    int opcion;
    opcion = getInt("1. Int\n"
                    "2. String\n"
                    "3. Char\n"
                    "4. Float\n"
                    "Ingrese una opcion: ");

    while(opcion < 0 || opcion > 4)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        "1. Int\n"
                        "2. String\n"
                        "3. Char\n"
                        "4. Float\n"
                        "Ingrese una opcion: ");
    }
    return opcion;
}

int subMenuModificarDos()
{
    int opcion;
    opcion = getInt("1. Int\n"
                    "2. String\n"
                    "3. Char\n"
                    "4. Float\n"
                    "Ingrese una opcion: ");

    while(opcion < 0 || opcion > 4)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        "1. Int\n"
                        "2. String\n"
                        "3. Char\n"
                        "4. Float\n"
                        "Ingrese una opcion: ");
    }
    return opcion;
}
