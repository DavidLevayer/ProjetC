#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionnaire.h"

static Dico monDico;

Dico initialiser()
{

	int i;
	Code c;
	c.taille = 1;
	monDico.table = malloc (MAX_TAB * sizeof(Code));
	monDico.taille = MAX_TAB;
	for(i=0;i<MAX_TAB;i++)
	{
		c.valeur = malloc(sizeof(unsigned char));
		c.valeur[0] = i;
		monDico.table[i] = c; 
	}
	monDico.indice = MAX_TAB;
	
}

void afficher ()
{
	int i,j;
	for(i=0;i<monDico.taille;i++)
	{
		printf("num. %d : ",i);
		for(j=0;j<monDico.table[i].taille;j++)
		{
			if (monDico.table[i].valeur[j]==' ') printf("_");
			else printf("%c",monDico.table[i].valeur[j]);
		}
		printf("\n");
	}
}

void afficherCode(Code c)
{
	printf("############\n");
	printf("Valeur du code : ");
	int i;
	for(i=0;i<c.taille;i++)
		printf("%c",c.valeur[i]);
	printf("\nTaille du code : %d\n",c.taille);
	printf("############\n");
}

	

char extrairePremier(char *prefix)
{
	if (prefix != NULL) return prefix[0];
	else printf("Erreur : prefixe null !");
}

/**
*ajoute l'élément s'il n'est pas présent ne fait rien sinon... retourne le numero du code que l'on souhaite ajouter
*
**/
int ajouterElement (Code prefix, char* mono)
{
	Code c = fusion(prefix,mono);
	if (monDico.indice > monDico.taille-1)
	{
		monDico.table = realloc(monDico.table,(monDico.taille+TAILLE_TAB)*sizeof(Code));
		monDico.taille += TAILLE_TAB;
	}
	monDico.table[monDico.indice] = c;
	monDico.indice++;
	return 0;
}


int compareCode(Code c1, Code c2)
{
	int j;
	if(c1.taille != c2.taille) return 0;
	for(j=0;j<c1.taille;j++)
	{
		if(c1.valeur[j]!=c2.valeur[j]) return 0;
	}
	return 1;


/*
 * 0 si pas trouver 1 sinon
 */
int rechercher(Code prefix, char* mono, int *code)
{
	Code c = fusion(prefix,mono);
	int i = 0,j;

	while(i<monDico.taille && compareCode(monDico.table[i],c)!=1)
		i++; 
	
	if (i==monDico.taille) return 0;
	else
	{
		*code = i;
		return 1;
	}

}

/**
*
*
**/
char *codeVersChaine (Code code, int longueur)
{

}

/**
*
*
**/
Code sequenceVersCode (Code sequence, int longueur)
{

}


/**
*
*
**/
Code fusion (Code prefix, char* mono)
{

	if (mono==NULL)return prefix;

	int i=0;	
	Code c;
	c.taille = prefix.taille + 1;
	c.valeur = malloc((prefix.taille+1)*sizeof(char));
	while(i<prefix.taille)
	{
		c.valeur[i] = prefix.valeur[i];
		i++;
	}
	c.valeur[i] = *mono;
	return c;
}
