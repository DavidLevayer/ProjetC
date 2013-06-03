#include "arbre.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


static Dico d;
/*
 * @param : cpt permet d'avoir la valeur du code sans se poser de questions sur l'ordre d'insertion
 */
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
    Arbre* feuille = (Arbre*)malloc(sizeof(Arbre));
    feuille->filsd=NULL;
    feuille->filsg=NULL;
    feuille->val = -1;
    feuille->mot = malloc(sizeof(Code));
    feuille->mot = creationCodeInit(NULL,0);
    return feuille;
}

/*
 * va permettre d'inserer à gauche un noeud pour l'initialisation
 */

int insertionGaucheInit(Code prefix){
    Arbre* nouvelElement = (Arbre*)malloc(sizeof(Arbre));
    cpt++;
    nouvelElement->val=cpt;
    nouvelElement->mot = malloc(sizeof(Code*));
    nouvelElement->mot->taille = prefix.taille;
    nouvelElement->mot->valeur = prefix.valeur;
    nouvelElement->filsd = (Arbre*)malloc(sizeof(Arbre));
    nouvelElement->filsd = creationFeuille();
    nouvelElement->filsg =NULL;
    d.finalp->filsg = nouvelElement;
    d.finalp=d.finalp->filsg;
    return 0;
}

Arbre* insertionGauche(Code prefix){
    Arbre* nouvelElement = (Arbre*)malloc(sizeof(Arbre));
    cpt++;
    nouvelElement->val=cpt;
    nouvelElement->mot = malloc(sizeof(Code*));
    nouvelElement->mot->taille = prefix.taille;
    nouvelElement->mot->valeur = prefix.valeur;
    nouvelElement->filsd = (Arbre*)malloc(sizeof(Arbre));
    nouvelElement->filsd = creationFeuille();
    nouvelElement->filsg =NULL;
    return nouvelElement;
}

int initialiser(){
    int i=1;
    unsigned char* cheat =malloc(sizeof(unsigned char));
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
        insertionGaucheInit(*code);
        i++;
    }

    
    // reservation de 10 cellule pour les caractères spéciaux

    while(i<266){
        code = creationCodeInit(NULL,0);
        insertionGaucheInit(*code);
        i++;
    }
    
    free(cheat);
    free(code);
    return 1;
}

Code fusion (Code prefix,unsigned char* mono){
    int i=0;
    Code newCode;
    if(mono==NULL)
        return prefix;
    newCode.taille=prefix.taille+1;
    newCode.valeur=malloc(newCode.taille*sizeof(unsigned char));
    while(i<prefix.taille){
        *(newCode.valeur+i)=*(prefix.valeur+i);
        i++;
    }
    *(newCode.valeur+i)=*mono;
    return newCode;
}
int ajouterElement (Code prefix,unsigned char* mono){
    int i=0;
    Code c = fusion(prefix,mono);
    Code* cheat = (Code*)malloc(sizeof(Code));
    Arbre* tmp = (Arbre*)malloc(sizeof(Arbre));
    tmp = d.beginp;
    while((tmp!=NULL)&& (i<c.taille)){
        if(*(c.valeur+i)>(*tmp->mot->valeur))
            tmp=tmp->filsg;
        else{
            tmp=tmp->filsd;
            if(tmp->filsg==NULL){
                if(i<c.taille){
                    cheat = creationCodeInit(c.valeur+i,1);
                    tmp->filsg= insertionGauche(*cheat);
                    tmp = tmp->filsg;
                    i++;
                }
            }
            else{
                i++;
                tmp=tmp->filsg;
            }
        }
    }
    free(cheat);
    free(tmp);
    return 0;
}




int afficherChaine(unsigned char* chaine,int taille){
    int i=0;
    while(i<taille){
        printf("%c",*(chaine+i));
        i++;
    }
    return 1;
}

int afficherArbre(){
    Arbre* tmp = d.beginp;
    while(tmp!=NULL){
        printf("%d ",tmp->val);
        afficherChaine(tmp->mot->valeur,tmp->mot->taille);;
        printf("\n");
        tmp = tmp->filsg;
    }
    return 1;
}