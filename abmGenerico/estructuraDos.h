typedef struct
{
    int id;
    int datoInt;
    char datoString[51];
    char datoChar;
    float datoFloat;
    int datoOcupado;
} sCosasDos;

int inicializarEstadoCosasDos(sCosasDos* arrayCosasDos, int capacidad);
int buscarLibreDos(sCosasDos* arrayCosasDos, int capacidad);
int datoCargadoDos(sCosasDos* arrayCosasDos, int capacidad);
int encontrarDatoPorIDDos(sCosasDos* arrayCosasDos, int capacidad, int id);
int agregarDatoDos(sCosasDos* arrayCosasDos, int capacidad);
void mostrarListaCosasDos(sCosasDos* arrayCosasDos, int cantidad);
int eliminarCosaDos(sCosasDos* arrayCosasDos, int capacidad);
void modificarCosaDos(sCosasDos* arrayCosasDos, int capacidad);


