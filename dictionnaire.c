#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionnaire.h"

static Dico d;

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




int ajouterElement (Code prefix, char* mono){
    Code c = fusion(prefix,mono);
    List* nouvelElement = malloc(sizeof(List*));
    nouvelElement->val = d.finalp->val+1;
    nouvelElement->mot = malloc(c.taille*sizeof(unsigned char));
    nouvelElement->mot->valeur = c.valeur;
    nouvelElement->mot->taille =c.taille;
    nouvelElement->nextp = NULL;
    d.finalp->nextp=nouvelElement;
    d.finalp=d.finalp->nextp;
    return 0;
}

int initialiser(){
    int i=1;
    unsigned char* cheat =malloc(sizeof(char));
    Code* code = malloc(sizeof(Code*));
    
    // creation de la premiere cellule pour amorcer l'initialisation
    d.beginp =malloc(sizeof(List*));
    d.beginp->val=0;
    *cheat =0;
    code = creationCodeInit(cheat,1);
    d.beginp->mot = code;
    d.beginp->nextp=NULL;
    d.finalp=d.beginp;
    
    // creation des 254 cellule acceuillant les mono caracteres ascii
    while(i<256){
        *cheat = i;
        code = creationCodeInit(cheat,1);
        ajouterElement(*code,NULL);
        i++;
    }
    
    // reservation de 10 cellule pour les caractères spéciaux
    while(i<266){
        code = creationCodeInit(NULL,0);
        ajouterElement(*code,NULL);
        i++;
    }
    free(cheat);
    free(code);
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
        afficherChaine(tmp->mot->valeur,tmp->mot->taille);
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
    newCode.taille=prefix.taille+1;
    newCode.valeur=malloc(newCode.taille*sizeof(unsigned int));
    while(i<prefix.taille){
        *(newCode.valeur+i)=*(prefix.valeur+i);
        i++;
    }
    *(newCode.valeur+i)=*mono;
    return newCode;
}
int compareCode(Code c1, Code c2){
    int j;
    if(c1.taille != c2.taille) 
        return 0;
    for(j=0;j<c1.taille;j++){
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




unsigned char *codeVersChaine (int code, int* longueur){
    unsigned char* c =NULL;
    List* pointeur = d.beginp;
    while((pointeur!=NULL)&&(pointeur->val!=code)){
        pointeur= pointeur->nextp;
    }
    if(pointeur==NULL)
        return NULL;
    else{
        *longueur = pointeur->mot->taille;
        c= pointeur->mot->valeur;
        return c;
    }
}
