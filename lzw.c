/**
* Auteurs : Jérôme Barbier, Augustin Husson, Mehdi NS, David Levayer
* Date : 28/05/2013
* Projet : Compression
* Version : 1.0
**/


#include "lzw.h"
#include "fichier.h"
#include "dictionnaire.h"

/**
*
*
**/
int compresser (char *nom, int entreeStandard)
{
	char *w;
	char a;
	int i,taillePrefixe=1;
	long nbOctects;

	// On récupère la taille du fichier à compresser
	if (fsize(nom, &nbOctets)!=0) return 2;

	// Ouverture du fichier à compresser
	FILE* f = ouvrir(nom);	
	if (f==NULL) return 1;

	// Initialisation du dictionnaire
	Dico d = initialiser();

	fgets(&w,taillePrefixe,f);

	for(i=1;i<nbOctets-1;i++)
	{
		fgets(&a,1,f);
		
	}
		
	return 0;
}
