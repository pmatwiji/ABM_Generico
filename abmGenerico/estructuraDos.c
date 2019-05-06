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

int inicializarEstadoCosasDos (sCosasDos* arrayCosasDos, int capacidad)
{
    int retorno = ILOGICO;
    int i;
    if(arrayCosasDos != NULL && capacidad != 0)
    {
        retorno = OCUPADO;
        for (i=0; i<capacidad; i++)
        {
            arrayCosasDos[i].datoOcupado = LIBRE;
        }
    }
    return retorno;
}

int buscarLibreDos(sCosasDos* arrayCosasDos, int capacidad)
{
    int retorno = ILOGICO;
    int i;
    if(capacidad > 0 && arrayCosasDos != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayCosasDos[i].datoOcupado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int datoCargadoDos(sCosasDos* arrayCosasDos, int capacidad)
{
    int retorno = 1;
    int i;
    if(capacidad > 0 && arrayCosasDos != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayCosasDos[i].datoOcupado == OCUPADO)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int encontrarDatoPorIDDos(sCosasDos* arrayCosasDos, int capacidad, int id)
{
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayCosasDos[i].id == id && arrayCosasDos[i].datoOcupado == 0)
        {
            return i;
            break;
        }
    }
    return -1;
}

int agregarDatoDos(sCosasDos* arrayCosasDos, int capacidad)
{

    int retorno = -1;
    int index = buscarLibreDos(arrayCosasDos, capacidad);
    char auxString[50];
    char buffer[50];
    int auxInt;
    char auxChar;
    float auxFloat;
    int i;
    if(capacidad > 0 && arrayCosasDos != NULL)
    {
        if(index != -1)
        {
            /*----------------ID---------------------------*/
            arrayCosasDos[index].id=index+1;
            /*---------------STRING------------------------*/
            getString("Ingrese el dato String: ", buffer);
            while(strlen(buffer)>50)
            {
                getString("El string es demasiado largo, ingreselo nuevamente: ", buffer);
            }
            strcpy(auxString, buffer);
            strcpy(strlwr(auxString), auxString);
            auxString[0]=toupper(auxString[0]);
            for(i=0;i < strlen(auxString); i++)
            {
                if(auxString[i] == ' ')
                {
                    auxString[i+1]=toupper(auxString[i+1]);
                }
            }
            strcpy(arrayCosasDos[index].datoString, auxString);
            /*------------------INT------------------------*/
            auxInt = getValidInt("Ingrese el dato entero: ","Solamente puede ingresar numeros.", 0, 10);
            arrayCosasDos[index].datoInt = auxInt;
            /*-----------------CHAR-------------------------*/
            auxChar = getChar("Ingrese el dato char: ");
            //validar solo char
            arrayCosasDos[index].datoChar = auxChar;
            /*-----------------FLOAT-------------------------*/
            auxFloat = getValidFloat("Ingrese el dato float: ", "Solamente puede ingresar numeros", 0, 100);
            arrayCosasDos[index].datoFloat = auxFloat;
            /*------------------ESPACIO-----------------------*/
            arrayCosasDos[index].datoOcupado = OCUPADO;

            retorno = 0;
            printf("Datos cargados correctamente.\n");
            system("pause");
            system("cls");
        }
    }
    return retorno;
}

void mostrarListaCosasDos(sCosasDos* arrayCosasDos, int cantidad)
{
    int i;
    printf("=====================================================================\n"
           "||                              Listado:                           ||\n"
           "=====================================================================\n");
    for(i=0; i<cantidad; i++)
    {
        if(arrayCosasDos[i].datoOcupado == OCUPADO)
        {
            printf(" %3d | %25s | %4d | %1c | %.2f               \n", arrayCosasDos[i].id, arrayCosasDos[i].datoString, arrayCosasDos[i].datoInt, arrayCosasDos[i].datoChar, arrayCosasDos[i].datoFloat);
        }
    }
    printf("=====================================================================\n");
}

int eliminarCosaDos(sCosasDos* arrayCosasDos, int capacidad)
{
    int retorno = ILOGICO;
    int auxiliarId;
    char opcion;

    auxiliarId = getInt("Ingrese el ID a buscar: ");
    int idCosa=encontrarDatoPorIDDos(arrayCosasDos, LIMITE, auxiliarId);
    if (idCosa>=0)
    {
        do
        {
            opcion = getChar("Confirma la baja? S/N\n");
            switch(opcion)
            {
            case 's':
                arrayCosasDos[idCosa].datoOcupado = LIBRE;
                printf("Baja realizada con exito.\n");
                break;
            case 'n':
                printf("Se cancelo la baja.\n");
                break;
            default:
                printf("Ingrese una opcion valida.\n");
                break;
            }
        }
        while (opcion != 's' && opcion != 'n');
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");
    }

    return retorno;
}


void modificarCosaDos(sCosasDos* arrayCosasDos, int capacidad)
{
    char auxString[50];
    int auxInt;
    char auxChar;
    float auxFloat;
    int auxId;
    int opcion;
    char confirmacion;


    auxId = getInt("Ingrese el ID a buscar: ");
    int idCosa = encontrarDatoPorIDDos(arrayCosasDos, LIMITE, auxId);
    if (idCosa>=0)
    {
        printf("ID encontrado, indique que dato desea modificar: \n");
        opcion = subMenuModificarDos();
        switch(opcion)
        {
        case 1:
            auxInt = getInt("Ingrese el nuevo entero: ");

            do
            {
                confirmacion = getChar("Confirma la modificacion? S/N ");
                switch(confirmacion)
                {
                case 's':
                    arrayCosasDos[idCosa].datoInt = auxInt;
                    printf("Modificacion realizada con exito.\n");
                    break;
                case 'n':
                    printf("Se cancelo la modificacion.\n");
                    break;
                default:
                    printf("Ingrese una opcion valida. ");
                    break;
                }
            }
            while (confirmacion != 'n' && confirmacion != 's');
            break;
        case 2:
            getString("Ingrese el string: ", auxString);
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    strcpy(arrayCosasDos[idCosa].datoString, auxString);
                    printf("Modificacion realizada con exito.\n");
                    break;
                case 'n':
                    printf("Se cancelo la modificacion.\n");
                    break;
                default:
                    printf("Ingrese una opcion valida. ");
                    break;
                }
            }
            while (confirmacion != 'n' && confirmacion != 's');
            break;
        case 3:
            auxChar = getChar("Ingrese el char: ");
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    arrayCosasDos[idCosa].datoChar = auxChar;
                    printf("Modificacion realizada con exito.\n");
                    break;
                case 'n':
                    printf("Se cancelo la modificacion.\n");
                    break;
                default:
                    printf("Ingrese una opcion valida. ");
                    break;
                }
            }
            while (confirmacion != 'n' && confirmacion != 's');
            break;
        case 4:
            auxFloat = getFloat("Ingrese el float: ");
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    arrayCosasDos[idCosa].datoFloat = auxFloat;
                    printf("Modificacion realizada con exito.\n");
                    break;
                case 'n':
                    printf("Se cancelo la modificacion.\n");
                    break;
                default:
                    printf("Ingrese una opcion valida. ");
                    break;
                }
            }
            while (confirmacion != 'n' && confirmacion != 's');
            break;
        }
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");

    }
}
