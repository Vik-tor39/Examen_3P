#include<stdio.h>
#include<string.h>
int main(){
    int id, num;
    char nom[20], carr[20];
    float not1, not2, not3;
    printf("INgresa un num");
    scanf("%d",num);
    FILE *archivo;
    archivo = fopen("alumnos.txt", "r");
    while(!feof(archivo)){
        fscanf(archivo, "%d;%[^;];%[^;];%f;%f;%f",&id,&nom,&carr,&not1,&not2,&not3);
        if((num==id)==0){
            printf("%d %s %s %.2f %.2f %.2f\n",id,nom,carr,not1,not2,not3);
        }
    }
    fclose(archivo);
    return 0;
}