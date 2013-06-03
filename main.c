#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"

int main(int argc, char **argv){
    Code * c = (Code*) malloc(sizeof(Code));
    c = creationCodeInit("ab",2);
    initialiser();
    ajouterElement(*c,NULL);
    afficherFuck(*c);
    return 0;
}
