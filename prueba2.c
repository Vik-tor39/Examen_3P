#include <stdio.h>
#include <string.h>

#define MAX_LINEAS 100

int main() {
    char lineas[MAX_LINEAS][100];
    int numLineas = 0;
    FILE *archivoEntrada, *archivoSalida;
    archivoEntrada = fopen("archivo_entrada.txt", "r");

    if (archivoEntrada) {
        // Leer las líneas del archivo de entrada y almacenarlas en el arreglo
        while (fgets(lineas[numLineas], sizeof(lineas[numLineas]), archivoEntrada)) {
            numLineas++;
        }
        fclose(archivoEntrada);

        // Escribir las líneas en orden inverso en el archivo de salida
        archivoSalida = fopen("archivo_salida.txt", "w");
        for (int i = numLineas - 1; i >= 0; i--) {
            fprintf(archivoSalida, "%s", lineas[i]);
        }
        fclose(archivoSalida);
    } else {
        printf("No se pudo abrir el archivo de entrada.\n");
    }

    return 0;
}
