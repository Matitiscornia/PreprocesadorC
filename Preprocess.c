#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "SymbolTable.h"

int estaEnTabla(char* );

typedef enum {
    Precomentario,
    comentarioGrande,
    puedeCerrarComentario,
    comentarioCerrado,
    comentarioLinea,
    Numeral,
    d,
    de,                     //El 1 es para las letras del undef
    def,
    defi,
    defin,
    define,
    u,
    un,
    und,
    unde,
    undef,
    IndicadorDef,
    IndicadorUndef,
    valorDef,
    enPalabra,
    fueraDePalabra,
    include

    
}state;

struct palabra{
    char nombre[100];
    int tamanio;
}indicador, valor, palabra,indicadorUndef;


void imprimirPalabra(char *reemplazo);
void vaciarPalabra(char *palabra);

int main(){
    char c;
 
    state s= enPalabra;
    int contador=0;



    char *reemplazo;
    struct nlist *variable;
    struct nlist *variable2;
    variable = (struct nlist *) malloc(sizeof(*variable));  
    variable2 = (struct nlist *) malloc(sizeof(*variable2)); 
   // int z=0;
    unsigned ashex;


    while((c=getchar())!=EOF){
        switch(s){

            case fueraDePalabra:
                switch(c){
                    case '#':
                        s=Numeral;
                        break;
                    
                    case '/':
                        s=Precomentario;
                        break;

                    case ' ': 
                    case '\n':
                    case '\t':
                    case ';':
                    case '[':
                    case ']':
                    case '(':
                    case ')':
                    case '{':
                    case '}':
                        putchar(c);
                        break;

                    default: 
                        palabra.nombre[palabra.tamanio]=c;
                        palabra.tamanio++;

                        s = enPalabra;
                        break;
                }
                break;
            
            case enPalabra:
                switch(c){
                    case '#':
                        s=Numeral;
                        break;
                    
                    case '/':
                        s=Precomentario;
                        break;


                    case ' ':
                    case '\n':
                    case '\t':
                    case ';':
                    case '[':
                    case ']':
                    case '(':
                    case ')':
                    case '{':
                    case '}':
                        variable2 = lookup(palabra.nombre);             //comparar a ver si esta en la tabla
                        

                        if(variable2 != NULL){
                            imprimirPalabra(variable2->defn);
                            
                        }
                        else{
                            imprimirPalabra(palabra.nombre);
                        }

                        
                        vaciarPalabra(palabra.nombre);
                        
                        putchar(c);
                        palabra.tamanio=0;
                        s=fueraDePalabra;
                        break;

                    default:                                       
                        palabra.nombre[palabra.tamanio]=c;
                        palabra.tamanio++;
                        break;
                }
                break;


            case Precomentario:
                
                switch(c){
                    case '/':
                        s=comentarioLinea;
                        break;
                    
                    case '*':
                        s=comentarioGrande;
                        break;
                    default:
                        s=enPalabra;
                }
                break;

            case comentarioLinea:
                switch(c){
                    case '\n':
                        putchar(c);
                        s=enPalabra;
                        break;
                }
                break;
            
            case comentarioGrande:
                switch(c){
                    case '*':
                        s=puedeCerrarComentario;
                        break;
                }
                break;

            case puedeCerrarComentario:
                switch(c){
                    case '/':
                        s=comentarioCerrado;
                        break;
                    default:
                        comentarioGrande;
                        break;
                }
                break;
            
            case comentarioCerrado:
                switch(c){
                    case '#':
                        s=Numeral;
                        break;
                    default:
                        s=enPalabra;
                        break;
                }
                break;

            case Numeral:
                switch(c){
                    case 'd':
                        s=d;
                        break;
                    
                    case 'u':
                        s=u;
                        break;
                        
                    default:
                        palabra.nombre[palabra.tamanio]=c;
                        palabra.tamanio++;
                        s=enPalabra;
                        break;
                }
                break;



            case u:
                switch(c){
                    case 'n':
                        s=un;
                        break;
                    default:
                        s=enPalabra;
                        break;
                }
                break;
            
            case un:
                switch(c){
                    case 'd':
                        s=und;
                        break;
                    default:
                        s=enPalabra;
                        break;
                }
                break;
            
            case und:
                switch(c){
                    case 'e':
                        s=unde;
                        break;
                    default:
                        s=enPalabra;
                        break;
                }
                break;
                
            case unde:
                switch(c){
                    case 'f':
                        s=undef;
                        break;
                    default:
                        s=enPalabra;
                        break;
                }
                break;

            case undef: 
                switch(c){
                    case ' ':
                        s=IndicadorUndef;
                        break; 
                    default:
                        s=enPalabra;
                        break;  
                }
                break;



            case IndicadorUndef:
                switch(c){
                    case ' ':                   // se termino de ingresar el identificador
                    case '\n':
                    case '\t':    
                        

                        putchar(c);
                        undefine(indicadorUndef.nombre);


                        indicadorUndef.tamanio=0;
                        vaciarPalabra(indicadorUndef.nombre);
                        s=fueraDePalabra;
                        break;
                    default:
                        indicadorUndef.nombre[indicadorUndef.tamanio]=c;
                        indicadorUndef.tamanio++;
                        break;
                }
                break;



            case d:
                switch(c){
                    case 'e':
                        s=de;
                        break;
                    default:
                        s=enPalabra;
                        break;
                }
                break;

            case de:
                switch(c){
                    case 'f':
                        s=def;
                        break;
                    default:
                        s=enPalabra;
                        break;
                }
                break;

            case def:
                switch(c){
                    case 'i':
                        s=defi;
                        break; 
                    default:
                        s=enPalabra;
                        break;  
                }
                break;

            case defi:
                switch(c){
                    case 'n':
                        s=defin;
                        break; 
                    default:
                        s=enPalabra;
                        break;  
                }
                break;

            case defin:
                switch(c){
                    case 'e':
                        s=define;
                        break; 
                    default:
                        s=enPalabra;
                        break;  
                }
                break;

            case define:
                switch(c){
                    case ' ':
                        s=IndicadorDef;
                        break; 
                    default:
                        s=enPalabra;
                        break;  
                }
                break;

            case IndicadorDef:
                switch(c){
                    case ' ':                   // se termino de ingresar el identificador
                        s=valorDef;
                        break;
                    default:
                        indicador.nombre[indicador.tamanio]=c;
                        indicador.tamanio++;
                        break;
                }
                break;
            
            case valorDef:
                switch(c){
                    case ' ':                   // se termino de ingresar el valor 
                    case '\n':
                    case '\t':
                        putchar(c);
                        indicador.tamanio=0;
                        valor.tamanio=0;
                        

                        
                        variable=install(indicador.nombre,valor.nombre);
                        

                        vaciarPalabra(indicador.nombre);
                        vaciarPalabra(valor.nombre);
                        s=fueraDePalabra;


                        break;
                    default:
                        valor.nombre[valor.tamanio]=c;
                        valor.tamanio++;
                        break;
                }
                break;


            

        }


        
        if(s!= Precomentario && s!= comentarioGrande && s!= comentarioLinea && s!= puedeCerrarComentario && s!= comentarioCerrado && s!= enPalabra && s!=fueraDePalabra){   //putchar para los define
            putchar(c);
        }



        }
    return 0;
}



void imprimirPalabra(char *reemplazo){           //Le paso la direccion de memoria de c
    
    while(*reemplazo!='\0'){
        putchar(*reemplazo);
        reemplazo++;
    }

}



void vaciarPalabra(char *palabra){ //Se vacia porque si no lo vacio los caracteres que no se sobreescriban van a molestar para calcular el hash
    int b;
    while(palabra[b]!='\0'){
        palabra[b] = '\0';
        b++;
    }
} 