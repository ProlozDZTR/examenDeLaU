#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAXEV 45
#define MINEV 18
#define NUMEV 8

struct Estadisticas {
    int goles;
    int tarjetaAmarilla;
    int tarjetaRoja;
    int penaltis;
    int tirosDeEsquinaConGol;
    int fueraDeJuego;
};

struct Equipo {
    char *nombre;
    struct Estadisticas *estadisticas;
};

// --- PROTOTIPOS ---
void generarEvento(struct Equipo *equipos);
void generarResultado(struct Equipo *equipos, int beneficiado, int perjudicado);

struct Equipo *asignarMemoria(int cuantos) {

    struct Equipo *equipos = (struct Equipo *)malloc(cuantos * sizeof(struct Equipo));
    
    for (int n = 0; n < cuantos; n++) {
        // Memoria para el nombre
        (equipos + n)->nombre = (char *)malloc(30 * sizeof(char));
        
        // Memoria para la estructura interna de estadísticas (ESTO FALTABA)
        (equipos + n)->estadisticas = (struct Estadisticas *)malloc(sizeof(struct Estadisticas));
        
        // Inicializar valores en cero
        (equipos + n)->estadisticas->goles = 0;
        (equipos + n)->estadisticas->fueraDeJuego = 0;
        (equipos + n)->estadisticas->penaltis = 0;
        (equipos + n)->estadisticas->tirosDeEsquinaConGol = 0;
    }
    return equipos; // FALTABA EL RETURN
}

FILE *abrirArchivo(char path[],char nombreArchivo[], char modo[]){
    char tempPath[100];
    strcpy(tempPath,path);
    strcat(tempPath, nombreArchivo);
    return fopen(tempPath,modo);
}

void guardarEnArchivo(struct Equipo *equipos, int limite, char path[],char nombre[]){
    FILE *file = abrirArchivo(path, nombre, "w");
    if(file == NULL) return;

    //AQUI VA TODO EL DESMADRE DE RESULTADOS
    fprintf(file, "Resultados del partido");

    fprintf(file,"\n--- RESULTADO FINAL ---\n");
    fprintf(file,"%s:Goles %d\n", equipos[0].nombre, equipos[0].estadisticas->goles);
    fprintf(file,"%s:Goles%d\n", equipos[1].nombre, equipos[1].estadisticas->goles);
    fprintf(file,"%s:tarjetas Amarillas %d\n", equipos[0].nombre, equipos[0].estadisticas->tarjetaAmarilla);
    fprintf(file,"%s:tarjetas Amarillas %d\n", equipos[1].nombre, equipos[1].estadisticas->tarjetaAmarilla);
    fprintf(file,"%s:tarjetas Rojas %d\n", equipos[0].nombre, equipos[0].estadisticas->tarjetaRoja);
    fprintf(file,"%s:tarjetas Rojas %d\n", equipos[1].nombre, equipos[1].estadisticas->tarjetaRoja);
    fprintf(file,"%s:penaltis %d\n", equipos[0].nombre, equipos[0].estadisticas->penaltis);
    fprintf(file,"%s:penaltis %d\n", equipos[1].nombre, equipos[1].estadisticas->penaltis);
    fprintf(file,"%s:fuera De Juego%d\n", equipos[0].nombre, equipos[0].estadisticas->fueraDeJuego);
    fprintf(file,"%s:fuera De Juego%d\n", equipos[1].nombre, equipos[1].estadisticas->fueraDeJuego);   
    fprintf(file,"%s:tiros de esquina con gol %d\n", equipos[0].nombre, equipos[0].estadisticas->tirosDeEsquinaConGol);
    fprintf(file,"%s:tiros de esquina con gol %d\n", equipos[1].nombre, equipos[1].estadisticas->tirosDeEsquinaConGol);

}



void cargarEquipos(struct Equipo *equipos) {
    printf("Introduzca el nombre del primer equipo: ");
    fgets(equipos[0].nombre, 30, stdin);
    equipos[0].nombre[strcspn(equipos[0].nombre, "\n")] = 0; // Quitar el salto de línea

    printf("Introduzca el nombre del segundo equipo: ");
    fgets(equipos[1].nombre, 30, stdin);
    equipos[1].nombre[strcspn(equipos[1].nombre, "\n")] = 0;
}

void generarEvento(struct Equipo *equipos) {
    int Evento = rand() % NUMEV + 1;
    // Usamos índices 0 y 1 porque son solo 2 equipos
    switch (Evento) {
        case 1:
            printf("¡Gol! El equipo %s ha anotado.\n", equipos[0].nombre);
            (equipos[0].estadisticas->goles)++;
            break;
        case 2:
            printf("¡Gol! El equipo %s ha anotado.\n", equipos[1].nombre);
            (equipos[1].estadisticas->goles)++;
            break;
        case 3:
            printf("%s cometió fuera de juego.\n", equipos[0].nombre);
            (equipos[0].estadisticas->fueraDeJuego)++;
            break;
        case 4:
            printf("%s cometió fuera de juego.\n", equipos[1].nombre);
            (equipos[1].estadisticas->fueraDeJuego)++;
            break;
        case 5:
            printf("¡Penalti para %s!\n", equipos[0].nombre);
            (equipos[0].estadisticas->penaltis)++;
            generarResultado(equipos, 0, 1); // 0 es el equipo beneficiado

            break;
        case 6:
            printf("¡Penalti para %s!\n", equipos[1].nombre);
            (equipos[1].estadisticas->penaltis)++;
            generarResultado(equipos, 1, 0);
            break;
        case 7:
            printf("Tiro de esquina con gol para %s.\n", equipos[0].nombre);
            (equipos[0].estadisticas->tirosDeEsquinaConGol)++;
            (equipos[0].estadisticas->goles)++;
            break;
        case 8:
            printf("Tiro de esquina con gol para %s.\n", equipos[1].nombre);
            (equipos[1].estadisticas->tirosDeEsquinaConGol)++;
            (equipos[1].estadisticas->goles)++;
            break;
    }
}

void generarResultado(struct Equipo *equipos, int beneficiado, int perjudicado) {
    int chanceBen = rand() % 4 + 0;
    int chancePer = rand() % 4 + 0;
     switch (chanceBen){
     case 1:
        printf("El equipo: %s anota el penalti",equipos[beneficiado].nombre);
        (equipos[beneficiado].estadisticas->goles)++;
        (equipos[beneficiado].estadisticas->penaltis)++;
    break;
    case 2:
    printf("El equipo: %s falla el penalti",equipos[beneficiado].nombre);
       (equipos[beneficiado].estadisticas->penaltis)++;
    break;
    case 3:
        printf("El equipo: %s anota el penalti",equipos[beneficiado].nombre);
        (equipos[beneficiado].estadisticas->goles)++;
        (equipos[beneficiado].estadisticas->penaltis)++;
    break;
    case 4:
         printf("El equipo: %s falla el penalti",equipos[beneficiado].nombre);
       (equipos[beneficiado].estadisticas->penaltis)++;

    break; }
     switch (chancePer){
    case 1:
        printf("El equipo: %s recibe una tarjeta roja",equipos[perjudicado].nombre);
        (equipos[perjudicado].estadisticas->tarjetaRoja)++;

    break;
    case 2:
        printf("El equipo: %s recibe una tarjeta amarilla",equipos[perjudicado].nombre);
        (equipos[perjudicado].estadisticas->tarjetaAmarilla)++;
    break;
    case 3:
        printf("El equipo: %s recibe una tarjeta amarilla",equipos[perjudicado].nombre);
        (equipos[perjudicado].estadisticas->tarjetaAmarilla)++;

    break;
    case 4:
        printf("El equipo: %s recibe una tarjeta roja",equipos[perjudicado].nombre);
        (equipos[perjudicado].estadisticas->tarjetaRoja)++;

    break;
     }
}

void generarTotalEventos(struct Equipo *equipos) {
    int totalEventos = rand() % (MAXEV - MINEV + 1) + MINEV;
    printf("\n--- Iniciando el partido (%d eventos) ---\n", totalEventos);
    for (int i = 0; i < totalEventos; i++) {
        generarEvento(equipos);
    }
}
void mostrarResultados(struct Equipo *equipos){
    printf("\n--- RESULTADO FINAL ---\n");
    printf("%s:Goles %d\n", equipos[0].nombre, equipos[0].estadisticas->goles);
    printf("%s:Goles%d\n", equipos[1].nombre, equipos[1].estadisticas->goles);
    printf("%s:tarjetas Amarillas %d\n", equipos[0].nombre, equipos[0].estadisticas->tarjetaAmarilla);
    printf("%s:tarjetas Amarillas %d\n", equipos[1].nombre, equipos[1].estadisticas->tarjetaAmarilla);
    printf("%s:tarjetas Rojas %d\n", equipos[0].nombre, equipos[0].estadisticas->tarjetaRoja);
    printf("%s:tarjetas Rojas %d\n", equipos[1].nombre, equipos[1].estadisticas->tarjetaRoja);
    printf("%s:penaltis %d\n", equipos[0].nombre, equipos[0].estadisticas->penaltis);
    printf("%s:penaltis %d\n", equipos[1].nombre, equipos[1].estadisticas->penaltis);
    printf("%s:fuera De Juego%d\n", equipos[0].nombre, equipos[0].estadisticas->fueraDeJuego);
    printf("%s:fuera De Juego%d\n", equipos[1].nombre, equipos[1].estadisticas->fueraDeJuego);   
    printf("%s:tiros de esquina con gol %d\n", equipos[0].nombre, equipos[0].estadisticas->tirosDeEsquinaConGol);
    printf("%s:tiros de esquina con gol %d\n", equipos[1].nombre, equipos[1].estadisticas->tirosDeEsquinaConGol);
}

void ejecutarPrograma() {
    struct Equipo *equipos = asignarMemoria(2);
    cargarEquipos(equipos);
    generarTotalEventos(equipos);
    mostrarResultados(equipos);
    char path[100],nombreArch[100];
    printf("Dame el path del archivo: ");
    fgets(path, 100, stdin);
    printf("Dame el nombre del archivo con el que lo quieres guardar");
    fgets(nombreArch,100,stdin);

    guardarEnArchivo(equipos,2,path,nombreArch);
    
    
}

int main() {
    srand(time(NULL));
    ejecutarPrograma();
    return 0;
}