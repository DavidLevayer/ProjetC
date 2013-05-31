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
    feuille->val = NULL;
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
