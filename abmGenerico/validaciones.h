/*---------------------ENTEROS----------------*/

int esNumerico(char str[]);
int getStringNumeros(char mensaje[],char input[]);
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/*-----------------------FLOTANTES--------------------*/

int esNumericoFlotante(char str[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

/*----------------------STRING-----------------------*/

int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int getStringLetras(char mensaje[],char input[]);
void getValidString(char requestMessage[],char errorMessage[], char input[]);
