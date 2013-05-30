
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char **argv){
    Code* c1 = malloc(sizeof(Code*));
    Code* c2 = malloc(sizeof(Code*));
    int l=0;
    unsigned char* test = NULL;
    
    c1 = creationCodeInit("uk",2);
    c2 = creationCodeInit("ukt",3);
    
    initialiser();
    
    ajouterElement(*c1,"t");
    afficherListe();
    test = codeVersChaine(256,&l);
    if(test==NULL)
        printf("va te pendre y a rien");
    else{
        afficherChaine(test,l);
        printf(" %d",l);
    }
    //afficherListe();
    return 1;
}

