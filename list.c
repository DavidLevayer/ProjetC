#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

static Dico d;

Code* creationCodeInit(char i){
    Code* mot = malloc(sizeof(Code*));
    mot->valeur = malloc(sizeof(unsigned char));
    *mot->valeur=i;
    mot->longueur =1;
    return mot;
}



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
        i++;
    }
    return 1;
}


int afficherListe(){
    List* tmp = d.beginp;
    while(tmp != NULL){
        printf("%c%c", *tmp->mot->valeur,*(tmp->mot->valeur+1));
        tmp = tmp->nextp;
    }
    return 1;
}

Code fusion (Code prefix, char* mono){
    int i=0;
    Code newCode;
    if(mono==NULL)
        return prefix;
    newCode.longueur=prefix.longueur+1;
    newCode.valeur=malloc(newCode.longueur*sizeof(unsigned int));
    while(i<prefix.longueur){
        *(newCode.valeur+i)=*(prefix.valeur+i);
        i++;
    }
    *(newCode.valeur+i)=*mono;
    return newCode;
}
int compareCode(Code c1, Code c2){
    int j;
    if(c1.longueur != c2.longueur) 
        return 0;
    for(j=0;j<c1.longueur;j++){
        if(c1.valeur[j]!=c2.valeur[j]) return 0;
    }
    return 1;

}

int rechercher(Code prefix, char* mono, int *code){
    List* pointeur = d.beginp;
    Code c =fusion(prefix,mono);
    while((pointeur!=NULL)&&(!compareCode(*pointeur->mot,c))){
        pointeur=pointeur->nextp;
    }
    if(pointeur==NULL)
        return 0;
    else{
        *code = pointeur->val;
        return 1;
    }
}

int ajouterElement (Code prefix, char* mono){
    Code c = fusion(prefix,mono);
    List* nouvelElement = malloc(sizeof(List*));
    nouvelElement->val = d.finalp->val+1;
    nouvelElement->mot = malloc(c.longueur*sizeof(unsigned char));
    nouvelElement->mot->valeur = c.valeur;
    nouvelElement->mot->longueur =c.longueur;
    nouvelElement->nextp = NULL;
    d.finalp->nextp=nouvelElement;
    d.finalp=d.finalp->nextp;
return 0;
}