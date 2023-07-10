#include <stdio.h>
#include <string.h>

int main() {
    int id;
    char nom[50], carr[50];
    float sum;
    float not1, not2, not3;
    char lineas[5][100];
    int cont = 0;
    FILE *archivo, *temp, *temp2;
    archivo = fopen("alumnos.txt", "r");
    temp = fopen("temp.txt", "w");

    if (archivo && temp) {
        while (fscanf(archivo, "%d;%[^;];%[^;];%f;%f;%f\n", &id, nom, carr, &not1, &not2, &not3) == 6) {
            sum=0;
            printf("%d;%s;%s;%.2f;%.2f;%.2f\n", id, nom, carr, not1, not2, not3);
            sum = ((not1+not2+not3)/3);
            printf("%.2f\n",sum);
            fprintf(temp,"%d;%s;%s;%.2f\n", id, nom, carr, sum);
        }
        fclose(archivo);
        fclose(temp);
    }
    
    temp = fopen("temp.txt", "r");
    temp2 = fopen("temp2.txt", "w");
    if (temp && temp2) {
        while (fgets(lineas[cont], sizeof(lineas[cont]), temp)) {
            cont++;
        }
        fclose(temp);
        for (int i = cont - 1; i >= 0; i--) {
            fprintf(temp2, "%s", lineas[i]);
        }
        fclose(temp2);
    }
    return 0;
}


