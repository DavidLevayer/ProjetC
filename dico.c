#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionnaire.h"

static Dico d;

Cellule creationCell(Code mot,int num){
    Cellule newCell;
    newCell.mot.valeur = malloc(mot.taille*sizeof(char));
    *newCell.mot.valeur = *mot.valeur;
    newCell.mot.taille = mot.taille;
    newCell.num = num;
    newCell.nextp =malloc(sizeof(Cellule*));
    newCell.nextp=NULL;
    return newCell;
}

Code creationMot(int i, int taille){
    Code mot;
    mot.valeur = malloc(taille*sizeof(char));
    mot.taille=taille;
    *(mot.valeur)=i;
    return mot;
}

Cellule ajouterCellule(int i, int taille){
    Cellule newCell = creationCell(creationMot(i,taille),i);
    d.finalp->nextp=&newCell;
    d.finalp=&newCell;
    return newCell;
}

void initialiser(){
    int i=1;
    d.beginp = malloc(sizeof(Cellule*));
    d.finalp = malloc(sizeof(Cellule*));
    d.beginp=NULL; d.finalp=NULL;
    Cellule firstCell = creationCell(creationMot(0,1),0);
    d.beginp=&firstCell;
    d.finalp=&firstCell;
    d.finalp->nextp=NULL;
    ajouterCellule(1,1);
    ajouterCellule(2,1);
    ajouterCellule(3,1);
       
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

/*
 * Les fonctions d'affichage
 */


int afficherCode(Code mot){
    printf("%c\n",*mot.valeur);
    return 1;
}
int afficherCell(Cellule cell){
    printf("%c\n",*cell.mot.valeur);
    printf("%d\n",cell.num);
    printf("%d\n",cell.mot.taille);
    return 1;
}

int afficherDic(){
    Cellule* pointeur;
    pointeur= d.beginp->nextp;
    printf("%d\n",pointeur->num);
}
