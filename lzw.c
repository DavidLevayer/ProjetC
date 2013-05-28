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

	fgets(w.valeur,1,fi);

	for(i=1;i<nbOctets-1;i++)
	{
		fgets(&a,1,fi);
		if (rechercher(w,&a,&code))
		{
			// w <--- w + a
			w.taille++;
			continue;
		}
		else
		{
			//fprintf(fo,code); // à débugger
			ajouterElement(w,&a);
			*w.valeur = a;
			w.taille = 1;
		}
		
	}

	//fprintf(fo,w); // à débugger
	
	return 0;
}
