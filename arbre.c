#include "arbre.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


static Dico d;
static int cpt;


/*
 * @param : car --> chaine de caractere que l'on souhaite voir intégré à une cellule Code
 * @param : taille ---> longueur de la chaine de caractere car
 * la fonction permet de créer une nouvelle cellule de type Code
 * on peut avoir une chaine vide ---> permet d'ajouter les caracteres spéciaux lors de l'initialisation du dico 
 */

Code* creationCodeInit(unsigned char* car,int taille){
    int i=0;
    Code* mot = malloc(sizeof(Code*));
    mot->valeur = malloc(taille*sizeof(unsigned char));
    if(car==NULL){
        mot->valeur=NULL;
        mot->taille=0;
        return mot;
    }
    else{
        while(i<taille){
            mot->valeur[i]=car[i];
            i++;
        }
        mot->taille =taille;
        return mot;
    }
    
}

Arbre* creationFeuille(){
    Arbre* feuille = malloc(sizeof(Arbre*));
    feuille->filsd=NULL;
    feuille->filsg=NULL;
    feuille->val = -1;
    feuille->mot = malloc(sizeof(Code*));
    feuille->mot = creationCodeInit(NULL,0);
    return feuille;
}

/*
 * va permettre d'inserer à gauche un noeud pour l'initialisation
 */

int insertionGauche(Code prefix){
    Arbre* nouvelElement = malloc(sizeof(Arbre*));
    cpt++;
    nouvelElement->val=cpt;
    nouvelElement->mot = malloc(prefix.taille*sizeof(unsigned char));
    nouvelElement->mot->taille = prefix.taille;
    nouvelElement->mot->valeur = prefix.valeur;
    nouvelElement->filsd = malloc(sizeof(Arbre*));
    nouvelElement->filsd = creationFeuille();
    nouvelElement->filsg =NULL;
    d.finalp->filsg = nouvelElement;
    d.finalp=d.finalp->filsg;
    return 0;
}

int initialiser(){
    int i=1;
    unsigned char* cheat =malloc(sizeof(char));
    Code* code = malloc(sizeof(Code*));
    
    // creation de la premiere cellule pour amorcer l'initialisation
    d.beginp =malloc(sizeof(Arbre*));
    d.finalp =malloc(sizeof(Arbre*));
    cpt =0;
    d.beginp->val = cpt;
    *cheat =0;
    code = creationCodeInit(cheat,1);
    d.beginp->mot = code;
    d.beginp->filsd = creationFeuille();
    d.beginp->filsg =NULL;
    d.finalp=d.beginp;
    
    // creation des 254 cellules acceuillant les monos caracteres ascii
    while(i<256){
        *cheat = i;
        code = creationCodeInit(cheat,1);
        insertionGauche(*code);
        i++;
    }

    
    // reservation de 10 cellule pour les caractères spéciaux

    while(i<266){
        code = creationCodeInit(NULL,0);
        insertionGauche(*code);
        i++;
    }
    
    free(cheat);
    free(code);
    return 1;
}


int afficherArbre(){
    return 1;
}