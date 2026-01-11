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


/*
struct Alumno *asignarMemoria(int cuantos) {
	int m, n;
	struct Alumno *alumnos = (struct Alumno *)malloc(cuantos*sizeof(struct Alumno));
	for(n=0; n<cuantos; n++) {
		for(m=0; m<MAX_CARGA; m++) {
			(alumnos+n)->(nombreUnidadAprendizaje+m) = (char *)malloc(MAX_NOMBRE_UA*sizeof(char));
			if((alumnos+n)->(nombreUnidadAprendizaje+m)==NULL) {
				printf("No se pudo asignar memoria al nombre de la unidad de aprendizaje.\n");
				return;
				}
			}
		(alumnos+n)->persona->nombreCompleto = (char *)malloc(MAX_NOMBRE_COMP*sizeof(char));
		if((alumnos+n)->persona->nombreCompleto==NULL) {
			printf("No se pudo asignar memoria al nombre del alumno.\n");
			return;
			}
		(alumnos+n)->boleta = (char *)malloc(MAX_BOLETA*sizeof(char));
		if((alumnos+n)->boleta==NULL) {
			printf("No se pudo asignar memoria a la boleta del alumno.\n");
			return;
			}
		}
	return alumnos;
}
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

struct Equipo *asignarMemoria (int cuantos){
	int n;
	struct Equipo *equipos = (struct Equipo *)malloc(cuantos*sizeof(struct Equipo));
	for (n = 0; n < cuantos; n++)
	{
		(equipos+n)->nombre=(char * )malloc(30*sizeof(char));
	
	}
	struct Equipo *estadisticas = (struct Equipo *)malloc(cuantos*sizeof(struct Equipo));
}
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
printf("El equipo: %s ha anotado un gol\n", (equipos+1)->estadisticas.nombre);
((equipos+1)->estadisticas.goles)++;
break;
case 2:
printf("El equipo: %s ha anotado un gol\n", (equipos+2)->estadisticas.nombre);
((equipos+2)->estadisticas.goles)++;
break;
case 3:
printf("El equipo: %s ha cometido un fuera de juego\n", (equipos+1)->estadisticas.fueraDeJuego);
((equipos+1)->estadisticas.fueraDeJuego)++;
break;
case 4:
printf("El equipo: %s ha cometido un fuera de juego\n", (equipos+2)->estadisticas.fueraDeJuego);
((equipos+2)->estadisticas.fueraDeJuego)++;
break;
case 5:

printf("El equipo: %s ha cometido un penalti\n", (equipos+1)->estadisticas.penaltis);
((equipos+1)->estadisticas.penaltis)++;
generarResultado(*equipos,1);

break;
case 6:
printf("El equipo: %s ha cometido un penalti\n", (equipos+2)->estadisticas.penaltis);
((equipos+2)->estadisticas.penaltis)++;
generarResultado(*equipos,2);
break;
case 7:
printf("El equipo: %s ha cometido un penalti\n", (equipos+1)->estadisticas.tirosDeEsquinaConGol);
((equipos+1)->estadisticas.tirosDeEsquinaConGol)++;

break;
case 8:
printf("El equipo: %s ha cometido un penalti\n", (equipos+2)->estadisticas.tirosDeEsquinaConGol);
((equipos+2)->estadisticas.tirosDeEsquinaConGol)++;

break;

}

}

void generarResultado(struct Equipo *equipos, int beneficiado){
	int totalEventos = rand () % 4 + 1;
switch (totalEventos){
case 1:
	printf("El equipo %s ha anotado el penalti",(equipos+beneficiado)->estadisticas->nombre);
((equipos+beneficiado)->estadisticas.goles)++;
	break;
case 2:
	printf("El equipo %s ha fallado el penalti",(equipos+beneficiado)->estadisticas->nombre);

	break;	
case 3:
	printf("El equipo %s ha anotado el penalti",(equipos+beneficiado)->estadisticas->nombre);
((equipos+beneficiado)->estadisticas.goles)++;
	break;
case 4:
	printf("El equipo %s ha anotado el penalti",(equipos+beneficiado)->estadisticas->nombre);

	break;
}

}
void ejecutarPrograma(){
	struct Equipo *equipos=asignarMemoria(2);
	cargarEquipos(equipos);
}




int main(int argc, char const *argv[])
{	
	srand(time(NULL));
	ejecutarPrograma();
	return 0;
}