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
int ajouterElement(unsigned char* car,int taille){
    int i =0;
    Arbre* tmp = d.beginp;
    Arbre* tmpPrecedent;
    Arbre* nouvelElem = (Arbre*)malloc(sizeof(Arbre));
    nouvelElem->mot = (Code*)malloc(sizeof(Code));
    nouvelElem->mot->valeur = (unsigned char*)malloc(sizeof(unsigned char*));
    nouvelElem->filsd = NULL;
    nouvelElem->filsg = NULL;
    cpt++;
    nouvelElem->val = cpt;
    if(tmp == NULL){
        *nouvelElem->mot->valeur=*car;
        d.beginp=nouvelElem;
        return 0;
    }
    while((tmp!=NULL)&&(i<taille)){
        tmpPrecedent=tmp;
        if(*(car+i)>*(tmp->mot->valeur)){
            tmp = tmp->filsg;
            if(tmp==NULL){
                *nouvelElem->mot->valeur = *(car+i);
                tmpPrecedent->filsg = nouvelElem;
            }
            else{
                if(*(car+i)<*tmp->mot->valeur){
                    *nouvelElem->mot->valeur = *(car+i);
                    nouvelElem->filsg = tmp;
                    tmpPrecedent->filsg = nouvelElem;
                    i++;
                }
            }
        }
        else{
            tmp = tmp->filsd;
            i++;
            if(tmp==NULL){
                *nouvelElem->mot->valeur = *(car+i);
                tmpPrecedent->filsd = nouvelElem;
            }
            else{
                if(*(car+i)<*tmp->mot->valeur){
                    *nouvelElem->mot->valeur = *(car+i);
                    nouvelElem->filsg = tmp;
                    tmpPrecedent->filsd = nouvelElem;
                    i++;
                }
            }
        }
    }
    return 1;
}

int initialiser(){
    cpt=-1;
    ajouterElement("a",1);
    ajouterElement("b",1);
    //ajouterElement("b",1);
    ajouterElement("ac",2);
    ajouterElement("ab",2);
    return 0;
}

int afficherArbre(){
    Arbre* tmp1 = d.beginp;
    Arbre* tmp2 = d.beginp;
    while(tmp1!=NULL){
        printf("%c %d\n",*tmp1->mot->valeur,tmp1->val);
        tmp1=tmp1->filsg;
    }
    printf("%c%c %d\n",*tmp2->mot->valeur,*tmp2->filsd->mot->valeur, tmp2->filsd->val);
    printf("%c%c %d",*tmp2->mot->valeur,*tmp2->filsd->filsg->mot->valeur, tmp2->filsd->filsg->val);
    return 0;
}






/*
 * va permettre d'inserer à gauche un noeud pour l'initialisation
 */
/*
int insertionGaucheInit(Code prefix){
    Arbre* nouvelElement = (Arbre*)malloc(sizeof(Arbre));
    cpt++;
    nouvelElement->val=cpt;
    nouvelElement->mot = malloc(sizeof(Code*));
    nouvelElement->mot->taille = prefix.taille;
    nouvelElement->mot->valeur = prefix.valeur;
    nouvelElement->filsd = NULL 
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
    nouvelElement->filsd = NULL;
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
    d.beginp->filsd = NULL;
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
    //printf("%d",c.taille);
    Code* cheat = (Code*)malloc(sizeof(Code));
    Arbre* tmp = (Arbre*)malloc(sizeof(Arbre));
    tmp = d.beginp;
    while((tmp!=NULL)&& (i<c.taille)){
        if(*(c.valeur+i)>(*tmp->mot->valeur)){
            printf("%c",*tmp->mot->valeur);
            printf("%d\n",i);
            tmp=tmp->filsg;
        }
        else{
            printf("RENTRER DANS LE ELSE\n");
            tmp=tmp->filsd;
            i++;
            if(tmp->filsg==NULL){
                printf("pointeur null dans le if\n");
                if(i<c.taille){
                    printf("va ajouter un truc\n");
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
        if(tmp==NULL)
            printf("pointeur null\n");
    }
    free(cheat);
    free(tmp);
    return 0;
}


 */