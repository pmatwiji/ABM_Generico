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

void hardcodeUno(sCosasUno* arrayCosasUno, int capacidad, int id, int auxInt, char auxString[], char auxChar, float auxFloat, int datoOcupado)
{
    int index = buscarLibreUno(arrayCosasUno, capacidad);
    arrayCosasUno[index].id= id;
    strcpy(arrayCosasUno[index].datoString, auxString);
    arrayCosasUno[index].datoInt = auxInt;
    arrayCosasUno[index].datoChar = auxChar;
    arrayCosasUno[index].datoFloat = auxFloat;
    arrayCosasUno[index].datoOcupado = OCUPADO;

}

void hardcodeDos(sCosasDos* arrayCosasDos, int capacidad, int id, int auxInt, char auxString[], char auxChar, float auxFloat, int datoOcupado)
{
    int index = buscarLibreDos(arrayCosasDos, capacidad);
    arrayCosasDos[index].id= id;
    strcpy(arrayCosasDos[index].datoString, auxString);
    arrayCosasDos[index].datoInt = auxInt;
    arrayCosasDos[index].datoChar = auxChar;
    arrayCosasDos[index].datoFloat = auxFloat;
    arrayCosasDos[index].datoOcupado = OCUPADO;

}

