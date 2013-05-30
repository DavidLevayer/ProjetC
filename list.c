#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

static Dico d;

Code* creationCodeInit(unsigned char* car,int taille){
    int i=0;
    Code* mot = malloc(sizeof(Code*));
    mot->valeur = malloc(taille*sizeof(unsigned char));
    while(i<taille){
        mot->valeur[i]=car[i];
        i++;
    }
    mot->longueur =taille;
    return mot;
}



/*int ajoutEnQueue(int valeur){
    unsigned char* cheat =NULL;
    *cheat = valeur;
    List* nouvelElement = malloc(sizeof(List*));
    nouvelElement->val = valeur;
    nouvelElement->mot = creationCodeInit(cheat,1);
    nouvelElement->nextp = NULL;
    d.finalp->nextp=nouvelElement;
    d.finalp=d.finalp->nextp;
    return 1;
}*/

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

int initialiser(){
    int i=1;
    unsigned char* cheat =malloc(sizeof(char));
    Code* code = malloc(sizeof(Code*));
    d.beginp =malloc(sizeof(List*));
    d.beginp->val=0;
    *cheat =0;
    code = creationCodeInit(cheat,1);
    d.beginp->mot = code;
    d.beginp->nextp=NULL;
    d.finalp=d.beginp;
    while(i<256){
        *cheat = i;
        code = creationCodeInit(cheat,1);
        ajouterElement(*code,NULL);
        i++;
    }
    free(cheat);
    return 1;
}

int afficherChaine(unsigned char* chaine,int taille){
    int i=0;
    while(i<taille){
        printf("%c",*(chaine+i));
        i++;
    }
    return 1;
}
int afficherListe(){
    List* tmp = d.beginp;
    while(tmp != NULL){
        printf("%d ",tmp->val);
        afficherChaine(tmp->mot->valeur,tmp->mot->longueur);
        printf("\n");
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


<<<<<<< HEAD
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



unsigned char *codeVersChaine (int code, int* longueur){
    unsigned char* c =NULL;
    List* pointeur = d.beginp;
    while((pointeur!=NULL)&&(pointeur->val!=code)){
        pointeur= pointeur->nextp;
    }
    if(pointeur==NULL)
        return NULL;
    else{
        *longueur = pointeur->mot->longueur;
        c= pointeur->mot->valeur;
        return c;
    }
}
