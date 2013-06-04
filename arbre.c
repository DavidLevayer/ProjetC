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

/*
 * va permettre d'inserer à gauche un noeud pour l'initialisation
 */

int* insertionGauche(Code prefix){
    Arbre* nouvelElement = (Arbre*)malloc(sizeof(Arbre));
    cpt++;
    nouvelElement->val=cpt;
    nouvelElement->mot = malloc(sizeof(Code*));
    nouvelElement->mot->taille = prefix.taille;
    nouvelElement->mot->valeur = (unsigned char*)malloc(sizeof(unsigned char*));
    nouvelElement->mot->valeur =prefix.valeur;
    nouvelElement->filsd = NULL;
    nouvelElement->filsg = NULL;
    nouvelElement->pere = d.finalp;
    d.finalp->filsg = nouvelElement;
    d.finalp = d.finalp->filsg;
    return 0;
}


int ajouterElement (Code prefix,unsigned char* mono){
    cpt= cpt +1;
    Code c = fusion(prefix,mono);
    int i =0;
    int taille = c.taille;
    unsigned char* car =c.valeur;
    Arbre* tmp = d.beginp;
    Arbre* tmpPrecedent = NULL;
    Arbre* nouvelElem = (Arbre*)malloc(sizeof(Arbre));
    
    
    nouvelElem->mot = (Code*)malloc(sizeof(Code));
    nouvelElem->mot->valeur = (unsigned char*)malloc(sizeof(unsigned char*));
    nouvelElem->mot->taille = taille;
    nouvelElem->filsd = NULL;
    nouvelElem->filsg = NULL;
    nouvelElem->pere = NULL;
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
                nouvelElem->pere = tmpPrecedent;
            }
            
            else{
                if(*(car+i)<*tmp->mot->valeur){
                    *nouvelElem->mot->valeur = *(car+i);
                    nouvelElem->filsg = tmp;
                    tmpPrecedent->filsg = nouvelElem;
                    nouvelElem->pere = tmpPrecedent;
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
                nouvelElem->pere = tmpPrecedent;
            }
            else{
                if(*(car+i)<*tmp->mot->valeur){
                    *nouvelElem->mot->valeur = *(car+i);
                    nouvelElem->filsg = tmp;
                    tmpPrecedent->filsd = nouvelElem;
                    nouvelElem->pere = tmpPrecedent;
                    i++;
                }
            }
        }
    }
    return 1;
}

int initialiser(){
    int i=1;
    cpt=0;
    unsigned char* cheat =malloc(sizeof(unsigned char));
    Code* code = (Code*)malloc(sizeof(Code));
    d.beginp =(Arbre*)malloc(sizeof(Arbre));
    d.finalp =(Arbre*)malloc(sizeof(Arbre));
    *cheat =0;
    code = creationCodeInit(cheat,1);
    d.beginp->mot = code;
    d.beginp->filsd=NULL;
    d.beginp->filsg=NULL;
    d.beginp->pere = NULL;
    d.finalp=d.beginp;
    
    // creation des 254 cellules acceuillant les monos caracteres ascii
    while(i<256){
        *cheat = i;
        code = creationCodeInit(cheat,1);
        insertionGauche(*code);
        i++;
    }

    
    // reservation de 10 cellule pour les caractères spéciaux

    while(i<266){
        code = creationCodeInit(NULL,0);
        insertionGauche(*code);
        i++;
    }
    
    free(cheat);
    free(code);
    return 1;
}

int rechercher(Code prefix, unsigned char* mono, int *code){
    int i = 0;
    Code c =fusion(prefix,mono);
    Arbre* tmpPred = NULL;
    Arbre* tmp = d.beginp;
    while((tmp!=NULL)&&(i<c.taille)){
        tmpPred = tmp;
        if(*(c.valeur+i)>*(tmp->mot->valeur)){
            tmp=tmp->filsg;
        }
        else{
            tmp=tmp->filsd;
            i++;
        }
    }
    if(i>= c.taille){
        *code = tmpPred->val;
        return 1;
    }
    else return 0;
}

unsigned char *remonteArbre(Arbre* abr){
    int i = abr->mot->taille;
    Arbre* tmp = abr;
    unsigned char* car = (unsigned char*)malloc(i*sizeof(unsigned char));
    i--;
    *(car + i) = *tmp->mot->valeur;
    tmp=tmp->pere;
    while((tmp!=NULL)&&(i>0)){
        if(i>=tmp->mot->taille){
            i--;
            *(car + i) = *tmp->mot->valeur;
        }
        tmp=tmp->pere;
    }
    return car;
}

Arbre* parcoursLargeur(int code, Arbre* pointeur, Arbre** save){
    if(pointeur == NULL)
        return NULL;
    if(pointeur->val == code){
        //printf("J'AI TROUVE TON POINTEUR\n");
        *save = pointeur;
        //printf("%d\n", (*save)->val);
        return pointeur;
    }
    parcoursLargeur(code,pointeur->filsg, save);
    parcoursLargeur(code,pointeur->filsd, save);
}

unsigned char *codeVersChaine (int code, int* longueur){
    Arbre* test = (Arbre*) malloc(sizeof(Arbre));
    unsigned char* car=NULL;
    parcoursLargeur(code,d.beginp,&test);
    *longueur = test->mot->taille;
    //printf("%c",*test->mot->valeur);
    printf("%c\n",*test->pere->mot->valeur);
    printf("%d\n",test->mot->taille);
    car = remonteArbre(test);
    afficherChaine(car,*longueur);
    
    return car;

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
        printf("%d %d\n",tmp->val,tmp->mot->taille);
        //printf("carac :%c num :%d taille :%d\n",*tmp->mot->valeur,tmp->val,tmp->mot->taille);
        tmp=tmp->filsg;
    }
    return 0;
}
int reinitialiser(){
    return 0;
}
int supprimerDico(){
    return 0;
}