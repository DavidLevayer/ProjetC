/**
* Auteurs : Jérôme Barbier, Augustin Husson, Mehdi NS, David Levayer
* Date : 28/05/2013
* Projet : Compression
* Version : 1.0
**/

#include "lzw.h"

/**
*
*
**/
int compresser (FILE *fi, FILE *fo)
{
	Code w;
	char a;
	int i,code;
	long nbOctets;
	
	// On récupère la taille du fichier à compresser
	if (tailleFichier(fi, &nbOctets)!=0) return 1;

	// Initialisation du dictionnaire
	initialiser();

	w.valeur = malloc (sizeof(char));
	w.valeur[0] = fgetc(fi);
	w.taille = 1;

	for(i=1;i<nbOctets-1;i++)
	{
		a = fgetc(fi);
		if (rechercher(w,&a,&code))
		{
			w = fusion (w,&a); // w <--- w + a (avec taille++ inclu)
			continue;
		}
		else
		{
			rechercher(w,NULL,&code);
			fprintf(fo,"%d-",code);
			ajouterElement(w,&a);
			*w.valeur = a;
			w.taille = 1;
		}
		
	}

	fprintf(fo,"%d",code);
	
	return 0;
}
