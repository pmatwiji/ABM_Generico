#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "estructuraDos.h"
#include "estructuraUno.h"
#include "funcionesGenericas.h"
#include "menu.h"
#include "hardcode.h"
#include "validaciones.h"

int inicializarEstadoCosasUno (sCosasUno* arrayCosasUno, int capacidad)
{
    int retorno = ILOGICO;
    int i;
    if(arrayCosasUno != NULL && capacidad != 0)
    {
        retorno = OCUPADO;
        for (i=0; i<capacidad; i++)
        {
            arrayCosasUno[i].datoOcupado = LIBRE;
        }
    }
    return retorno;
}

int buscarLibreUno(sCosasUno* arrayCosasUno, int capacidad)
{
    int retorno = ILOGICO;
    int i;
    if(capacidad > 0 && arrayCosasUno != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayCosasUno[i].datoOcupado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int datoCargado(sCosasUno* arrayCosasUno, int capacidad)
{
    int retorno = 1;
    int i;
    if(capacidad > 0 && arrayCosasUno != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayCosasUno[i].datoOcupado == OCUPADO)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


int encontrarDatoPorID(sCosasUno* arrayCosasUno, int capacidad, int id)
{
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayCosasUno[i].id == id && arrayCosasUno[i].datoOcupado == 0)
        {
            return i;
            break;
        }
    }
    return -1;
}

int agregarDato(sCosasUno* arrayCosasUno, int capacidad)
{

    int retorno = -1;
    int index = buscarLibreUno(arrayCosasUno, capacidad);
    char auxString[50];
    char buffer[50];
    int auxInt;
    char auxChar;
    float auxFloat;
    int i;
    if(capacidad > 0 && arrayCosasUno != NULL)
    {
        if(index != -1)
        {
            /*----------------ID---------------------------*/
            arrayCosasUno[index].id=index+1;
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
            strcpy(arrayCosasUno[index].datoString, auxString);
            /*------------------INT------------------------*/
            auxInt = getValidInt("Ingrese el dato entero: ", "Solamente puede ingresar numeros.", 0, 10);
            arrayCosasUno[index].datoInt = auxInt;
            /*-----------------CHAR-------------------------*/
            auxChar = getChar("Ingrese el dato char: ");
            //validar solo char
            arrayCosasUno[index].datoChar = auxChar;
            /*-----------------FLOAT-------------------------*/
            auxFloat = getValidFloat("Ingrese el dato float: ", "Solamente puede ingresar numeros", 0, 100);
            arrayCosasUno[index].datoFloat = auxFloat;
            /*------------------ESPACIO-----------------------*/
            arrayCosasUno[index].datoOcupado = OCUPADO;

            retorno = 0;
            printf("Datos cargados correctamente.\n");
            system("pause");
            system("cls");
        }
    }
    return retorno;
}


void mostrarListaCosas(sCosasUno* listaCosas, int cantidadCosasUno, sCosasDos* listaCosasDos, int cantidadCosasDos)
{
    int i;
    int j;
    char relacion[20];
    printf("=====================================================================\n"
           "||                              Listado:                           ||\n"
           "=====================================================================\n");
    for(i=0; i<cantidadCosasUno; i++)
    {
        if(listaCosas[i].datoOcupado == OCUPADO)
        {
            for(j=0;j<cantidadCosasDos; j++)
            {
                if(listaCosas[i].datoInt == listaCosasDos[j].id)
                {
                    strcpy(relacion, listaCosasDos[j].datoString);
                }
            }
            printf(" %3d | %25s | %4d %s  | %1c | %.2f               \n", listaCosas[i].id, listaCosas[i].datoString, listaCosas[i].datoInt, relacion, listaCosas[i].datoChar, listaCosas[i].datoFloat);
        }


    }
    printf("=====================================================================\n");
}

int eliminarCosa(sCosasUno* arrayCosasUno, int capacidad)
{
    int retorno = ILOGICO;
    int auxiliarId;
    char opcion;

    auxiliarId = getInt("Ingrese el ID a buscar: ");
    int idCosa=encontrarDatoPorID(arrayCosasUno, LIMITE, auxiliarId);
    if (idCosa>=0)
    {
        do
        {
            opcion = getChar("Confirma la baja? S/N\n");
            switch(opcion)
            {
            case 's':
                arrayCosasUno[idCosa].datoOcupado = LIBRE;
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


void modificarCosa(sCosasUno* arrayCosasUno, int capacidad)
{
    char auxString[50];
    int auxInt;
    char auxChar;
    float auxFloat;
    int auxId;
    int opcion;
    char confirmacion;
    char buffer[50];
    int i;


    auxId = getInt("Ingrese el ID a buscar: ");
    int idCosa = encontrarDatoPorID(arrayCosasUno, LIMITE, auxId);
    if (idCosa>=0)
    {
        printf("ID encontrado, indique que dato desea modificar: \n");
        opcion = subMenuModificarUno();
        switch(opcion)
        {
        case 1:
            auxInt = getValidInt("Ingrese el dato entero: ", "Solamente puede ingresar numeros.", 0, 10);
            do
            {
                confirmacion = getChar("Confirma la modificacion? S/N ");
                switch(confirmacion)
                {
                case 's':
                    arrayCosasUno[idCosa].datoInt = auxInt;
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
            strcpy(arrayCosasUno[idCosa].datoString, auxString);
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    strcpy(arrayCosasUno[idCosa].datoString, auxString);
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
                    arrayCosasUno[idCosa].datoChar = auxChar;
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
            auxFloat = getValidFloat("Ingrese el dato float: ", "Solamente puede ingresar numeros", 0, 100);
            do
            {
                confirmacion = getChar("Confirma la modificacion? ");
                switch(confirmacion)
                {
                case 's':
                    arrayCosasUno[idCosa].datoFloat = auxFloat;
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
