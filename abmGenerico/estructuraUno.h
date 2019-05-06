#define ILOGICO -1
#define OCUPADO 0
#define LIBRE 1
#define LIMITE 3

#ifndef ESTRUCTURAUNO_H_INCLUDED
#define ESTRUCTURAUNO_H_INCLUDED
#include "estructuraDos.h"


typedef struct
{
    int id;
    int datoInt;
    char datoString[51];
    char datoChar;
    float datoFloat;
    int datoOcupado;
} sCosasUno;




int inicializarEstadoCosasUno(sCosasUno* arrayCosasUno, int capacidad);
int buscarLibreUno(sCosasUno* arrayCosasUno, int capacidad);
int datoCargado(sCosasUno* arrayCosasUno, int capacidad);
int encontrarDatoPorID(sCosasUno* arrayCosasUno, int capacidad, int id);
int agregarDato(sCosasUno* arrayCosasUno, int capacidad);
//void mostrarCosa (sCosasUno, sCosasDos[], int);
void mostrarListaCosas(sCosasUno* listaCosas, int cantidadCosasUno, sCosasDos* listaCosasDos, int cantidadCosasDos);
//void mostrarListaCosas(sCosasUno* arrayCosasUno, int cantidad);
int eliminarCosa(sCosasUno* arrayCosasUno, int capacidad);
void modificarCosa(sCosasUno* arrayCosasUno, int capacidad);

#endif
