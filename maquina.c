/*
La empresa que fabrica un modelo de maquinas
expendedoras de refrescos necesita un
programa para estas maquinas que realice
un calculo de cuantas monedas de cada tipo
debe devolver. Para elllos, en primer 
lugarse introducira por teclado la cantidad
a devolver en pesos (multipo de 5 centavos)
que es la moneda mas pequeña de la que se dispone
, es decir, se teclará 1.85 para 1 peso con
85 centavos ese programa escribira en pantalla
cuantass monedas de cada tipo hay que devolver
teniendo en cuenta que
se dispone de monedas de 50 centavos, 20 centavis
10 centavos y 5 centavos

siempre se dispone de las monedas necesarias de
cada tipo, se debe devolver el menor numero
de monedas posible, es decir, intentar devolver
con las de mayor valor.


Ejemplos:
 Si se introduce la cantidad de 1 peso con 85
 centavos, el programa debe imprimir: 3 monedas
 de 50 centavos y 1  moneda de 20 centavos, 1
 moneda de 10 centavos y 1 moneda de 5
 centavos.

 si se introduce la cantidad de 1 peso con 20
 centavos el programa debe imrpimir 2 monedas de 50
 1 moneda de 20, 0 de 10 y 0 de 5


 Este problema consiste en determinar cuantas monedas
 de cada tipo se necesitan para formar la cantidad
 que debe devolver la maquina expendedora, teniendo
 en cuenta que se debe utilizar el menor numero posible
 de momendas de cada valor
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Moneda{
	float entrada;
	int ctvs50;
	int ctvs20;
	int ctvs10;
	int ctvs5;
};

FILE *abrirArchivo(char path[],char nombreArchivo[], char modo[]){
    char tempPath[100];
    strcpy(tempPath,path);
    srcat(tempPath, nombreArchivo);
    return fopen(tempPath,modo);
}

void guardarEnArchivo(struct Moneda monedas, int limite, char path[],char nombre[]){
    FILE *file = abrirArchivo(path, nombre, "w");
    if(file == NULL) return;

    //AQUI VA TODO EL DESMADRE DE RESULTADOS
    fprintf(file, "Resultados del partido");
    fprintf(file,"Monedas de 50 centavos: %i\n",monedas->ctvs50);
	fprintf(file,"Monedas de 20 centavos: %i\n",monedas->ctvs20);
	fprintf(file,"Monedas de 10 centavos: %i\n",monedas->ctvs10);
	fprintf(file,"Monedas de  5 centavos: %i\n",monedas->ctvs5);
}

void tufuncionxdd(){
    char path[100],nombreArch[100];
    printf("Dame el path del archivo: ");
    fgets(path, 100, stdin);
    printf("Dame el nombre del archivo con el que lo quieres guardar");
    fgets(nombreArch,100,stdin);

    guardarEnArchivo(Moneda,1,path,nombreArch);
}

void validarEntrada(struct Moneda *monedas){

	monedas->ctvs50 = 0;
    monedas->ctvs20 = 0;
    monedas->ctvs10 = 0;
    monedas->ctvs5 = 0;
int Numero =monedas->entrada * 100 + 0.5;

	
if(Numero>=5){
	
while(Numero>=50){
(monedas->ctvs50)++;
Numero-=50;
}
while(Numero>=20){
(monedas->ctvs20)++;
Numero-=20;	
}
while(Numero>=10){
(monedas->ctvs10)++;
Numero-=10;	
}
while(Numero>=5){
(monedas->ctvs5)++;
Numero-=5;	
}	
}
else{
	printf("la entrada no es valida\n");
}
};

void mostrarResultados(struct Moneda *monedas){
printf("Resultados: \n");
printf("Monedas de 50 centavos: %i\n",monedas->ctvs50);
printf("Monedas de 20 centavos: %i\n",monedas->ctvs20);
printf("Monedas de 10 centavos: %i\n",monedas->ctvs10);
printf("Monedas de  5 centavos: %i\n",monedas->ctvs5);
printf("\n");
};

void ejecutarPrograma(){
	struct Moneda monedas;
	char aux[10];
printf("Escribe la entrada del cambio: \n");
fgets(aux, 10, stdin);
monedas.entrada = atof(aux);

validarEntrada(&monedas);
mostrarResultados(&monedas);
guardarEnArchivo(Moneda,1,path,nombreArch);

};
int main(int argc, char const *argv[])
{

	ejecutarPrograma();
	return 0;
}