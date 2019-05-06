#define ILOGICO -1
#define OCUPADO 0
#define LIBRE 1
#define LIMITE 3



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
//void mostrarListaCosas(sCosasUno[], int, sCosasDos[], int);
void mostrarListaCosas(sCosasUno* arrayCosasUno, int cantidad);
int eliminarCosa(sCosasUno* arrayCosasUno, int capacidad);
void modificarCosa(sCosasUno* arrayCosasUno, int capacidad);
