#include<stdio.h>
#define HOLA 5
#define perro 10
HOLA

//Archivos
/*asdd
*/
int main(){
    char caracter;
    FILE *f;
    int variable = HOLA;
    
    f= fopen("Archivo.txt","r"); //Abro (no hace falta que sea un txt)
    if(f ==NULL){
        printf("No se ha podido abrir el fichero. \n"); //puede pasar porque escribimos mal el nombre
    }

    while(caracter !=EOF){
        caracter=fgetc(f);
        printf("%c",caracter);
    }

    #undef HOLA
    fclose(f); HOLA //Cierro

    getch();
    return 0;
}