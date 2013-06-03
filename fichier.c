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


static int reste = 0;
static int nbReste = 0;
static int nbBits = 9;

int ecrire(FILE* f, int v)
{
	int buffer = v;
	char aEcrire;

	unsigned int restePrecedent,ajoutCourant;
	unsigned int codeSpecial=0;
	
		
	printf("NBRESTE %d ",nbReste);
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

	
	printf("DEBUG ###### ");
	printf("nbBits : %d ",nbBits);
	printf("Buffer : (hexa : %x (v: %x)) ",buffer,v);
	printf("restePrecedent :  (hexa : %x de taille %d) ",restePrecedent,nbReste);
	printf("ajoutCourant :  (hexa : %x) ",ajoutCourant);
	printf("aEcrire :  (hexa : %x) ",aEcrire);
	printf("Reste :  (hexa : %x) ",reste);
	printf("nbReste : %d ",nbReste);
	printf("############ ");
	

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

	if (v==FIN)
	{
			while(nbReste < 8)
			{
				printf("CACCCAAAAAAAAAAAAAAAA %d %d &&&&&&&&",v,FIN);
				reste = reste << 1;
				nbReste++;
			}
			reste = reste & 0xFF;

			fwrite(&reste,1,1,f);
	}
	printf("=== NB RESTE %d ===",nbReste);
	return 0;

}

int lire (FILE* f, int* value)
{
	unsigned int buffer;	
	unsigned int aLire;
	
	while(nbReste<nbBits)
	{
		fread(&buffer,1,1,f);
		reste = (reste << 8) | (buffer & 0xFF);
		nbReste = nbReste + 8;
	}
	
	aLire = reste >> (nbReste-nbBits);
	*value = aLire;

	/*
	printf("Valeur du reste : %d (hexa: %x)\n",reste,reste);
	printf("Valeur de nbReste : %d\n",nbReste);
	printf("Valeur aLire : %d (hexa: %x)\n",aLire,aLire);
	*/

	reste = reste & creerMasque(nbReste-nbBits);
	nbReste = nbReste - nbBits;

	/*
	printf("Valeur du nouveau reste : %d (hexa: %x)\n",reste,reste);
	printf("Valeur de nouveau nbReste : %d\n",nbReste);
	*/

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

int setNbBits (int valeur)
{
	nbBits = valeur;
	//printf("Nouvelle valeur de nbBits : %d\n",nbBits);
	return 0;
}

int incNbBits ()
{
	nbBits++;
	//printf("Nouvelle valeur de nbBits : %d\n",nbBits);
	return 0;
}

int getNbBits ()
{
	return nbBits;
}
