
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char **argv){
<<<<<<< HEAD

    int code=0;
    Code* c = creationCodeInit(65);
=======
    Code* c1 = malloc(sizeof(Code*));
    Code* c2 = malloc(sizeof(Code*));
    int l=0;
    unsigned char* test = NULL;
    
    c1 = creationCodeInit("uk",2);
    c2 = creationCodeInit("ukt",3);
    
>>>>>>> c0bc75ec92640c83d6cf5d5e4e271c1b770cbf6c
    initialiser();
    ajouterElement(*c1,"t");
    test = codeVersChaine(*c2,&l);
    if(test==NULL)
        printf("va te pendre y a rien");
    else{
        afficherChaine(test,l);
        printf(" %d",l);
    }
    //afficherListe();

    return 1;
}

