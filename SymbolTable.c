#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymbolTable.h"



#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* tabla de apuntadores */  

int hash(char *s)                                                              //Es un unsigned int la funcion 
{
    int hashval;
    for (hashval = 0; *s != '\0'; s++)                                                 // recorre el array y termina cuando el array llega a su ultima posicion '\0', con el ++ pasa de posicion el puntero
        hashval = *s + 31 * hashval;
    return (hashval % HASHSIZE);
}

struct nlist *lookup(char *s)                                                               //duda: por que se declara como puntero pero despues no se pone el * para sacar el dato en strcmp
{
    struct nlist *np;
    for (np=hashtab[hash(s)]; np!=NULL; np=np->next){
        if (strcmp(s, np->name) == 0){                                                               //stcmp devuelve 0 si las 2 cadenas son iguales(strcmp compara todas las letras)
            return np; /* se encontró */                                                            //que la funcion retorne np
        }
    }
    return NULL; /* no se encontró */                                                           //que la funcion retorne NULL
}


char *stringcopy(char *palabra){        //duplica el puntero
    char *copia;
    copia= (char *) malloc(strlen(palabra) + 1); //el + 1 es para \0 
    if(copia != NULL){                          //significa que hay lugar en memoria y se puede realizar la asignación
        strcpy(copia,palabra);
    }

    return copia;
}









   //duplica la cadena dada
/* install: coloca (name, defn) dentro de hashtab */

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* no fue encontrado */
        np = (struct nlist *) malloc(sizeof(*np));                          //le asignamos memoria
        if (np == NULL || (np->name = stringcopy(name)) == NULL)            //En caso de que no se haya podido asignar memoria correctamente o no se haya podido copiar el nombre
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab [hashval] = np;
    } else /* ya está allí */
        free((void *) np->defn); /* libera la anterior defn */
    if ((np->defn = stringcopy(defn)) == NULL)
        return NULL;

    return np;
}


/* struct nlist *unistall(char *name)
{
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL){
        return NULL; // No se encontro en la tabla
    }
    else 
    {
        hashval = hash(name);
        hashtab [hashval]= 
    }
    
} */









void undefine(char *s) {
    struct nlist *actual, *anterior;

    for (anterior = NULL, actual = hashtab[hash(s)];actual != NULL;anterior = actual, anterior = actual->next) {

        if (strcmp(actual->name, s) == 0) {
            if (anterior == NULL) 
            {
                hashtab[hash(s)] = actual->next;
            }
            else 
            {
                anterior->next = actual->next;
            }
            
            free(actual->name);
            free(actual->defn);
            free(actual); 
            return;
        }

    }
}



