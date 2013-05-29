#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
/*
 * structure avec un pointeur fonctionne
 */
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

List* ajoutEnQueu(List* l, int valeur){
    List* nouvelElement = malloc(sizeof(List*));
    List* temp=l;
    nouvelElement->val = valeur;
    nouvelElement->mot = creationCodeInit(valeur);
    nouvelElement->nextp = NULL;
  
    if(l == NULL){
        /* Si la liste est videé il suffit de renvoyer l'élément créé */
        return nouvelElement;
    }
    else{
        while(temp->nextp != NULL){
            temp = temp->nextp;
        }
        temp->nextp = nouvelElement;
        return l;
    }
}

Dico initialiser(){
    int i=1;
    Dico d;
    d.beginp =malloc(sizeof(List*));
    d.beginp->val=0;
    d.beginp->mot =creationCodeInit(0);
    d.beginp->nextp=NULL;
    //List* l = malloc(sizeof(List*));
    //l->val=0;
    //l->nextp=NULL;
    while(i<255){
        d.beginp=ajoutEnQueu(d.beginp,i);
        i++;
    }
    return d;
}


void afficherListe(Dico l){
    List* tmp = l.beginp;
    while(tmp != NULL){
        printf("%c", *tmp->mot->valeur);
        tmp = tmp->nextp;
    }
}