#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionnaire.h"

static Dico d;
int supprimerMemoire(List* listp);

/*
 * @param : car --> chaine de caractere que l'on souhaite voir intégré à une cellule Code
 * @param : taille ---> longueur de la chaine de caractere car
 * la fonction permet de créer une nouvelle cellule de type Code
 * on peut avoir une chaine vide ---> permet d'ajouter les caracteres spéciaux lors de l'initialisation du dico 
 */

Code* creationCodeInit(unsigned char* car,int taille)
{
	int i=0;
	Code* mot = malloc(sizeof(Code*));
	mot->valeur = malloc(taille*sizeof(unsigned char));
	if(car==NULL)
	{
		mot->valeur=NULL;
		mot->taille=0;
    return mot;
  }
  else
	{
  	while(i<taille)
		{
    	mot->valeur[i]=car[i];
      i++;
    }
    mot->taille =taille;
    return mot;
  }    
}

/*
 *cette fonction ajoute uniquement en queue
 * il y a une incrémentation de la valeur associée au code grâce au pointeur finalp
 * une fois que tous les parametres nécessaires à la création du nouvelle cellule sont en place, 
 * on décale le pointeur finalp sur cette nouvelle cellule.
 */
int ajouterElement (Code prefix, char* mono)
{
	Code c = fusion(prefix,mono);
	List* nouvelElement = malloc(sizeof(List*));
	nouvelElement->val = d.finalp->val+1;
	nouvelElement->mot = malloc(sizeof(Code*));
	nouvelElement->mot->valeur = c.valeur;
	nouvelElement->mot->taille =c.taille;
	nouvelElement->nextp = NULL;
	d.finalp->nextp=nouvelElement;
	d.finalp=d.finalp->nextp;
	return 0;
}

/*
 * permet de créer pour la premiere fois un dico
 * il contient les 255 caracteres ascii
 * il y a ensuite ajout de 10 caractères spéciaux nécessaires (par exemple end of file de code Ox100 ie 256)
 * Pour éviter de rendre priver des chaines de caracteres pour les caracteres spéciaux on met la chaine NULL lors de chaque 
 * cellule crée.
 */
int initialiser()
{
	int i=1;
	unsigned char* cheat =malloc(sizeof(char));
	Code* code = malloc(sizeof(Code*));
    
	// creation de la premiere cellule pour amorcer l'initialisation
	d.beginp =malloc(sizeof(List*));
	d.finalp =malloc(sizeof(List*));
	d.middlep=malloc(sizeof(List*));
	d.beginp->val=0;
	*cheat =0;
	code = creationCodeInit(cheat,1);
	d.beginp->mot = code;
	d.beginp->nextp=NULL;
	d.finalp=d.beginp;
    
	// creation des 254 cellules acceuillant les monos caracteres ascii
	while(i<256)
	{
		*cheat = i;
		code = creationCodeInit(cheat,1);
		ajouterElement(*code,NULL);
		i++;
  }

	// reservation de 10 cellule pour les caractères spéciaux
	while(i<266)
	{
		code = creationCodeInit(NULL,0);
		ajouterElement(*code,NULL);
		i++;
  }
	d.middlep=d.finalp;
	free(cheat);
  free(code);
  return 0;
}


/*
 * Affiche la chaine passée en paramètre
 * (fonction de confort)
 */
int afficherChaine(unsigned char* chaine,int taille)
{
	int i=0;
	while(i<taille)
	{
  	printf("%c",*(chaine+i));
    i++;
  }
  return 0;
}

/*
 * Affiche la liste chainée qui symbolise le dictionnaire
 * (fonction de confort)
 */
int afficherListe()
{
  List* tmp = d.beginp;
  while(tmp != NULL)
	{
  	printf("%d ",tmp->val);
    afficherChaine(tmp->mot->valeur,tmp->mot->taille);
    printf("\n");
    tmp = tmp->nextp;
  }
  return 0;
}


/*
 * Affiche la chaine passée en paramètre
 * (fonction de confort)
 */
Code fusion (Code prefix, char* mono){
    int i=0;
    Code newCode;
    if(mono==NULL)
        return prefix;
    newCode.taille=prefix.taille + 1;
    newCode.valeur=malloc(newCode.taille*sizeof(unsigned char));
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
    {
      *code = 0;
      return 0;
    }
    else
    {
        *code = pointeur->val;
        return 1;
    }
}


/*
 * @ code : valeur de la chaine de caractere que l'on recherche 
 * exemple : on veut la chaine associée au code 65 on trouve donc A
 * @ longueur : valeur fictive. Elle ne sert qu'à retourner la longueur de la chaine de caractere trouvée
 */

unsigned char *codeVersChaine (int code, int* longueur){
    unsigned char* c =NULL;
    List* pointeur = d.beginp;
    while((pointeur!=NULL)&&(pointeur->val!=code)){
        pointeur= pointeur->nextp;
    }
    if(pointeur==NULL){
        *longueur = 0;
        return NULL;
    }
        
    else{
        *longueur = pointeur->mot->taille;
        c= pointeur->mot->valeur;
        return c;
    }
}


int supprimerMemoire(List* listp)
{
	List* save= malloc(sizeof(List*));
	save=listp;
	listp=listp->nextp;
	while(listp!=NULL)
	{
		List* aSupprimer = listp;
		listp=aSupprimer->nextp;
		free(aSupprimer);
	}
	save->nextp=NULL;
	d.finalp=save;
	return 1;
}

int reinitialiser()
{
	supprimerMemoire(d.middlep);
	return 1;
}

int supprimerDico()
{
	supprimerMemoire(d.beginp);
	free(d.beginp);
	d.beginp=d.finalp=d.middlep=NULL;
	return 1;
}

