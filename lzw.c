/**
* Auteurs : Jérôme Barbier, Augustin Husson, Mehdi NS, David Levayer
* Date : 28/05/2013
* Projet : Compression
* Version : 1.0
**/

#include "lzw.h"

void ecrireBinaire(FILE* fo, int v)
{
	
}
/**
*
*
**/
int compresser (FILE *fi, FILE *fo)
{
	Code w;
	char a;
	int code;
	long nbOctets;
	
	// On récupère la taille du fichier à compresser
	//if (tailleFichier(fi, &nbOctets)!=0) return 1;

	// Initialisation du dictionnaire
	initialiser();

	w.valeur = malloc (sizeof(char));
	w.valeur[0] = fgetc(fi);
	w.taille = 1;
	while ((a = getc(fi)) != EOF)
	{
		printf("valeur de a : %c (hexa: %x)\n",a,a);
		if (rechercher(w,&a,&code))
		{
			w = fusion (w,&a); // w <--- w + a (avec taille++ inclu)
			continue;
		}
		else
		{
			rechercher(w,NULL,&code);
			//fprintf(fo,"%d.",code);
			ecrire(fo,code);
			ajouterElement(w,&a);
			*w.valeur = a;
			w.taille = 1;
		}
		
	}
	rechercher(w,NULL,&code);
	//fprintf(fo,"%d",code);
	ecrire(fo,code);
	
	// Fin de fichier
	ecrire(fo,FIN);
	return 0;
}

/**
*
*
**/
int decompresser(FILE* fi, FILE* fo)
{
	return 0;
}
