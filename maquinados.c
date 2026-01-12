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

// Se corrigió srcat por strcat y se manejan los saltos de línea
FILE *abrirArchivo(char path[], char nombreArchivo[], char modo[]){
    char tempPath[200];
    strcpy(tempPath, path);
    strcat(tempPath, nombreArchivo);
    return fopen(tempPath, modo);
}

// Se cambió a puntero struct Moneda* para usar ->
void guardarEnArchivo(struct Moneda *monedas, char path[], char nombre[]){
    FILE *file = abrirArchivo(path, nombre, "w");
    if(file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(file, "Resultados del cambio para: %.2f\n", monedas->entrada);
    fprintf(file, "Monedas de 50 centavos: %i\n", monedas->ctvs50);
    fprintf(file, "Monedas de 20 centavos: %i\n", monedas->ctvs20);
    fprintf(file, "Monedas de 10 centavos: %i\n", monedas->ctvs10);
    fprintf(file, "Monedas de  5 centavos: %i\n", monedas->ctvs5);
    
    fclose(file); // IMPORTANTE: Siempre cerrar el archivo
    printf("Datos guardados con exito.\n");
}

void validarEntrada(struct Moneda *monedas){
    monedas->ctvs50 = 0;
    monedas->ctvs20 = 0;
    monedas->ctvs10 = 0;
    monedas->ctvs5 = 0;

    int Numero = (int)(monedas->entrada * 100 + 0.5);

    if(Numero >= 5){
        while(Numero >= 50){
            (monedas->ctvs50)++;
            Numero -= 50;
        }
        while(Numero >= 20){
            (monedas->ctvs20)++;
            Numero -= 20;    
        }
        while(Numero >= 10){
            (monedas->ctvs10)++;
            Numero -= 10;    
        }
        while(Numero >= 5){
            (monedas->ctvs5)++;
            Numero -= 5;    
        }    
    } else {
        printf("la entrada no es valida\n");
    }
}

void mostrarResultados(struct Moneda *monedas){
    printf("Resultados: \n");
    printf("Monedas de 50 centavos: %i\n", monedas->ctvs50);
    printf("Monedas de 20 centavos: %i\n", monedas->ctvs20);
    printf("Monedas de 10 centavos: %i\n", monedas->ctvs10);
    printf("Monedas de  5 centavos: %i\n", monedas->ctvs5);
    printf("\n");
}

void ejecutarPrograma(){
    struct Moneda monedas;
    char aux[10], path[100], nombreArch[100];

    printf("Escribe la entrada del cambio: \n");
    fgets(aux, 10, stdin);
    monedas.entrada = atof(aux);

    validarEntrada(&monedas);
    mostrarResultados(&monedas);

    // Pedir datos del archivo dentro de la misma funcion para que las variables existan
    printf("Dame el path del archivo (ejemplo: ./ ): ");
    fgets(path, 100, stdin);
    path[strcspn(path, "\n")] = 0; // Quitar el salto de linea de fgets

    printf("Dame el nombre del archivo: ");
    fgets(nombreArch, 100, stdin);
    nombreArch[strcspn(nombreArch, "\n")] = 0; // Quitar el salto de linea de fgets

    guardarEnArchivo(&monedas, path, nombreArch);
}

int main(int argc, char const *argv[])
{
    ejecutarPrograma();
    return 0;
}