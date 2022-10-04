#pragma once

struct nlist { /* entrada de la tabla: */
    struct nlist *next; /* siguiente entrada en la cadena */
    char *name; /* nombre definido */
    char *defn; /* texto de reemplazo */
};

int hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
char *stringcopy(char *palabra);
void undefine(char *s);
