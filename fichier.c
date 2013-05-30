#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"

/**
*
* mode = 0 --< fichier existe "r" sinon "w"
**/
FILE* ouvrir (char* nomFichier, int mode)
{
	FILE* f = NULL;
	if (mode==0) f = fopen(nomFichier, "r");	
	else f = fopen(nomFichier, "w");
	
	if (f != NULL)
  {
  	return f;
  }
	else
	{
		printf("Erreur lors de l'ouverture du fichier %s\n",nomFichier);
		return NULL;
	}
}



/**
*
*
**/
int fermer (FILE* fichier)
{
	fclose(fichier);
}


int tailleFichier(FILE* f, long* taille)
{
	{
    /* Cette fonction retourne 0 en cas de succes, une valeur differente dans le cas contraire. */
    /* La taille du fichier, si elle a pu etre calculee, est retournee dans *taille                */

    int ret = 0;  

    if (f != NULL)
    {
        fseek(f, 0, SEEK_END); /* aller a la fin du fichier */
        *taille = ftell(f); /* lire l'offset de la position courante par rapport au debut du fichier */
 				rewind(f);
    }
    else
        ret = 1;
 
    return ret;
	}
}

static int reste = 0;
static int nbReste = 0;
static int nbBits = 9;

int ecrire(FILE* f, int v)
{
	int buffer = v;
	char aEcrire;

	int restePrecedent,ajoutCourant;
	int codeSpecial=0;

	if (v & creerMasque(9) == FIN)
		codeSpecial = 1;
	if (v & creerMasque(9) == INC)
		codeSpecial = 2;
	if (v & creerMasque(9) == RAZ)
		codeSpecial = 3;	

	// On extrait les bits de poids faibles necessaires
	buffer = buffer & creerMasque(nbBits);
	// On constitue ensuite l'octet à écrire, en fonction :
	// 	 - d'un eventuel reste précédent
	//   - des bits de poids forts extraits ci-dessus
	restePrecedent = (reste << (8-nbReste)) & 0xFF;
	//ajoutCourant = buffer & (~0>>(sizeof(int)*8-(nbBits+nbReste-8)));
	ajoutCourant = (buffer >> (nbReste+nbBits-8)) & 0xFF;
	aEcrire = (restePrecedent | ajoutCourant);
	// On sauvegarde les bits restants (écriture future)
	nbReste = (nbReste + nbBits - 8);
	reste = buffer & creerMasque(nbReste);

	/*
	printf("DEBUG ######\n");
	printf("nbBits : %d\n",nbBits);
	printf("Buffer : %d (hexa : %x (v: %x))\n",buffer,buffer,v);
	printf("restePrecedent : %c (hexa : %x)\n",restePrecedent,restePrecedent);
	printf("ajoutCourant : %c (hexa : %x)\n",ajoutCourant,ajoutCourant);
	printf("aEcrire : %c (hexa : %x)\n",aEcrire,aEcrire);
	printf("Reste : %d (hexa : %x)\n",reste,reste);
	printf("nbReste : %d\n",nbReste);
	printf("############\n");
	*/

	fwrite(&aEcrire,1,1,f);

	// On imprime le reste (octets entiers disponibles dans reste
	while(nbReste > 7)
	{
		buffer = reste & creerMasque(nbReste-8);
		aEcrire = (reste >> (nbReste-8)) & 0xFF;
		fwrite(&aEcrire,1,1,f);
		reste = buffer;
		nbReste = nbReste - 8;
	}

	switch(codeSpecial)
	{
		case 0:
			break;

		case 1:
			// Cas de fin de fichier
			while(nbReste < 8)
			{
				reste = reste << 1;
				nbReste++;
			}
			reste = reste & 0xFF;
			fwrite(&reste,1,1,f);
			break;

		case 2:
			// Cas Incrémentation de la taille des éléments
			nbBits++;
			break;

		case 3:	
			// Cas de remise à zéro du dictionnaire
			nbBits = 9;
			break;
	}
	return 0;

}

int creerMasque (int nbUn)
{
	int i,res=0;
	for(i=0;i<nbUn;i++)
	{
		res = res << 1;
		res = res | 0x1;
	}
	return res;
}
