/*desarrollar un simulador de juego de futbol , su simulador deberia funcionar de la siguiente manera:
Un generad9r de numeros aleatorios debe generar un numero y este será el numero de eventos en un juego.
este valor debe estar entre 18 y 45.

Su programa deberia entonces generar este numero de eventos. para cada evento
debe generar un numero aleatorio entre 1 y 8.

Si el numero generado es 1, equipo 1 marca un gol
Si el numero generado es 2, equipo 2 marca un gol
Si el numero generado es 3, equipo 1 marca fuera de juego
Si el numero generado es 4, equipo 2 marca fuera de juego
Si el numero generado es 5, equipo 1 comete penalti
Si el numero generado es 6, equipo 2 comete penalti
Si el numero generado es 7, equipo 1 ejecuta tiro de esquina
Si el numero generado es 8, equipo 2 ejecuta tiro de esquina

Para decidir el resultado de la sanción (penalti), su programa debe generar otro numero aleatorio
entre 1 y 4.
SI este numero es 1 o 3, el equipo anota el penalti.
si es 2 o 4, falla el penalti.
Para decidir el resultado de la sanción (penalti), su programa debe generar otro numero aleatorio
entre 1 y 4.
SI este numero es 2 o 3, tarjeta amarilla.
si es 1 o 4, tarjeta roja

en cada evento generado el programa debe generar una declaración dando un comentario sobre ese evento como
"El equipo 1 anotó un gol"al final del programa. debe imprimir la puntuación final del juego.
en el inicio de su función principal inicialice el generador de numeros aleatorios con la hora del sistema.
No olvide almacenar la información del nombre de los equipos que entran en simulación.

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define MAXEV 45
#define MINEV 18
#define NUMEV 8
#define RES 4


struct Estadisticas{
	int goles;
	int tarjetaAmarilla;
	int tarjetaRoja;
	int penaltis;
	int tirosDeEsquinaConGol;
	int fueraDeJuego;
};

struct Equipo
{
	char *nombre;
	struct Estadisticas *estadisticas;
	
};
void cargarEquipos (struct Equipo *equipos){
	printf("Introduzca el nombre del primer equipo:");
	fgets((equipos+1)->nombre,30,stdin);
	printf("Introduzca el nombre del segundo equipo:");
	fgets((equipos+2)->nombre,30,stdin);
}


void generarTotalEventos(){
	int totalEventos = rand () % MAXEV + MINEV;
for (int i = 0; i < totalEventos; i++)
{
	generarEvento();	
}
}
void generarEvento(struct Equipo *equipos){
int Eventos = rand () % NUMEV + 1;
switch (Eventos){
case 1:
printf("El equipo: %s ha anotado un gol\n",);
break;
case 2:

break;
case 3:

break;
case 4:

break;
case 5:

break;
case 6:

break;
case 7:

break;
case 8:

break;

}

}

void generarResultado(){

}




int main(int argc, char const *argv[])
{	
	srand(time(NULL));
	generarTotalEventos();
	return 0;
}