#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"



List* ajoutEnQueu(List* l, int valeur){
    List* nouvelElement = malloc(sizeof(List*));
    List* temp=l;
    nouvelElement->val = valeur;
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

List* initialiser(){
    int i=1;
    List* l = malloc(sizeof(List*));
    l->val=0;
    l->nextp=NULL;
    while(i<255){
        l=ajoutEnQueu(l,i);
        i++;
    }
    return l;
}


void afficherListe(List* l){
    List* tmp = l;
    while(tmp != NULL){
        printf("%d ", tmp->val);
        tmp = tmp->nextp;
    }
}