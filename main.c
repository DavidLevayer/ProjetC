
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char **argv){

    int code=0;
    Code* c = creationCodeInit(65);
    initialiser();
    ajouterElement(*c,"u");
    ajouterElement(*c,"k");
    if(rechercher(*c, "xD", &code))
        printf("%d",code);
    else printf("bouh t'es moche");
    //afficherListe();

    return 1;
}

