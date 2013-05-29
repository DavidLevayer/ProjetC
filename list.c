#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
/*
 * structure avec un pointeur fonctionne
 */
static Dico d;

Code* creationCodeInit(int i){
    Code* mot = malloc(sizeof(Code*));
    mot->valeur = malloc(sizeof(char));
    *mot->valeur = i;
    mot->longueur =1;
    return mot;
}
/*Code creationCodeInit(int i){
    Code mot;
    mot.valeur=malloc(sizeof(char));
    *mot.valeur=i;
    mot.longueur=1;
    return mot;
}*/

/*List* ajoutEnQueu(List* l, int valeur){
    List* nouvelElement = malloc(sizeof(List*));
    List* temp=l;
    nouvelElement->val = valeur;
    nouvelElement->mot = creationCodeInit(valeur);
    nouvelElement->nextp = NULL;
  
    if(l == NULL){
        return nouvelElement;
    }
    else{
        while(temp->nextp != NULL){
            temp = temp->nextp;
        }
        temp->nextp = nouvelElement;
        return l;
    }
}*/

int ajoutEnQueue(int valeur){
    List* nouvelElement = malloc(sizeof(List*));
    nouvelElement->val = valeur;
    nouvelElement->mot = creationCodeInit(valeur);
    nouvelElement->nextp = NULL;
    d.finalp->nextp=nouvelElement;
    d.finalp=d.finalp->nextp;
    return 1;
}

int initialiser(){
    int i=1;
    d.beginp =malloc(sizeof(List*));
    d.beginp->val=0;
    d.beginp->mot =creationCodeInit(0);
    d.beginp->nextp=NULL;
    d.finalp=d.beginp;
    while(i<256){
        ajoutEnQueue(i);
        //d.beginp=ajoutEnQueu(d.beginp,i);
        i++;
    }
    return 1;
}


int afficherListe(){
    List* tmp = d.beginp;
    while(tmp != NULL){
        printf("%c", *tmp->mot->valeur);
        tmp = tmp->nextp;
    }
    return 1;
}