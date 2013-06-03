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
    nouvelElem->valeur = (unsigned char*)malloc(sizeof(unsigned char*));
    nouvelElem->filsd = NULL;
    nouvelElem->filsg = NULL;
    if(tmp == NULL){
        *nouvelElem->valeur=*car;
        d.beginp=nouvelElem;
        return 0;
    }
    while((tmp!=NULL)&&(i<taille)){
        tmpPrecedent=tmp;
        if(*(car+i)>*(tmp->valeur)){
            tmp = tmp->filsg;
            if(tmp==NULL){
                *nouvelElem->valeur = *(car+i);
                tmpPrecedent->filsg = nouvelElem;
            }
            else{
                if(*(car+i)<*tmp->valeur){
                    *nouvelElem->valeur = *(car+i);
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
                *nouvelElem->valeur = *(car+i);
                tmpPrecedent->filsd = nouvelElem;
            }
            else{
                if(*(car+i)<*tmp->valeur){
                    *nouvelElem->valeur = *(car+i);
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
    ajouterElement("a",1);
    //ajouterElement("b",1);
    ajouterElement("ab",2);
    return 0;
}
/*
int ajouterElement( int cle){
    Arbre* tmp = d.beginp;
    Arbre* tmpPrecedent;
    Arbre* nouvelElem = (Arbre*)malloc(sizeof(Arbre));
    nouvelElem->val = cle;
    nouvelElem->filsd = NULL;
    nouvelElem->filsg = NULL;
    if(tmp==NULL){
        d.beginp=nouvelElem;
        return 0;
    }
    while(tmp!=NULL){
        tmpPrecedent=tmp;
        if(cle>tmp->val){
            tmp=tmp->filsg;
            if(tmp==NULL)
                tmpPrecedent->filsg=nouvelElem;
        }
        else{
            tmp=tmp->filsd;
            if(tmp==NULL)
                tmpPrecedent->filsd=nouvelElem;
        }
    }
    return 1;
}
*/

/*
int initialiser(){
    int i =0;
    while(i<42){
        ajouterElement(i);
        i++;
    }
    return 0;
}

*/

int afficherArbre(){
    Arbre* tmp1 = d.beginp;
    Arbre* tmp2 = d.beginp;
    while(tmp1!=NULL){
        printf("%c\n",*tmp1->valeur);
        tmp1=tmp1->filsg;
    }
    printf("%c%c",*tmp2->valeur,*tmp2->filsd->valeur);
    return 0;
}











/*Arbre* creationFeuille(){
    Arbre* feuille = (Arbre*)malloc(sizeof(Arbre));
    feuille->filsd=NULL;
    feuille->filsg=NULL;
    feuille->val = -1;
    feuille->mot = malloc(sizeof(Code));
    feuille->mot = creationCodeInit(NULL,0);
    return feuille;
}*/

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

int afficherFuck(Code prefix){
    int i =0;
    Arbre* tmp = (Arbre*)malloc(sizeof(Arbre));
    tmp = d.beginp;
    while((tmp!=NULL)&&(i<prefix.taille)){
        if(*(prefix.valeur+i)>(*tmp->mot->valeur)){
            printf("%c",*tmp->mot->valeur);
            tmp=tmp->filsg;
        }
        else{
            printf("%c\n",*tmp->mot->valeur);
            //tmp=tmp->filsd;
            if(tmp==NULL)
                printf("pointeur null\n");
            printf("caca");
            i++;
        }
    }
}
 */