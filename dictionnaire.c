#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionnaire.h"


Cellule creationCell(Code mot,int num){
    Cellule newCell;
    newCell.mot.valeur = malloc(mot.taille*sizeof(char));
    newCell.mot.taille = malloc(sizeof(int));
    newCell.mot = mot;
    newCell.num = malloc(sizeof(int));
    newCell.num = num;
    newCell.nextp = NULL;
    return newCell;
}
Code creationMot(int i, int taille){
    Code mot;
    mot.taille=taille;
    *mot.valeur=i;
    return mot;
}


Dico initialiser(){
    Dico dico;
    int i=1;
    Cellule* currentp=NULL;
    Cellule newCell;
    dico.beginp = NULL;
    dico.finalp = NULL;
    
    newCell = creationCell(creationMot(1,1),0);
    dico.beginp = &newCell;
    while(i<256){
        currentp= &newCell;
        newCell=creationCell(creationMot(i,1),i);
        (*currentp).nextp=&newCell; // equivalent à currentp->nextp
        currentp = &newCell;
        i++;
    }
    dico.finalp = currentp;
    return dico;
}

int ajouterElement (Code prefix, char* mono){
    return 0;
};

int rechercher(Code prefix, char* mono, int *code){
    return 0;
}

char *codeVersChaine (Code code, int longueur){
    return "coco";
}

Code sequenceVersCode (Code sequence, int longueur){
    return sequence;
}

Code fusion (Code prefix, char* mono){
    return prefix;
}