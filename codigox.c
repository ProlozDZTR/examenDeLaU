#include <stdio.h>
#include <stdlib.h>

FILE *abrirArchivo(char path[],char nombreArchivo[], char modo[]){
    char tempPath[100];
    strcpy(tempPath,path);
    srcat(tempPath, nombreArchivo);
    return fopen(tempPath,modo);
}

void guardarEnArchivo(struct estructura equpos, int limite, char path[],char nombre[]){
    FILE *file = abrirArchivo(path, nombre, "w");
    if(file == NULL) return;

    //AQUI VA TODO EL DESMADRE DE RESULTADOS
    fprintf(file, "Resultados del partido");
}

void tufuncionxdd(){
    char path[100],nombreArch[100];
    printf("Dame el path del archivo: ");
    fgets(path, 100, stdin);
    printf("Dame el nombre del archivo con el que lo quieres guardar");
    fgets(nombreArch,100,stdin);

    guardarEnArchivo(equipo,2,path,nombreArch);
}



