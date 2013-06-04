/*
 * Auteurs : Jérôme Barbier, Augustin Husson, David Levayer, Mehdi NS
 * Date : 03/06/2013
 * Projet : Compression de fichiers
 * Version : 1.0
 */

#include <stdlib.h>
#include <stdio.h>
#include "fichier.h"

/*
 * Ouvre le fichier dont le nom est passé en paramètre avec le mode souhaité
 * @param nomFichier le nom du fichier à ouvrir
 * @param mode le mode d'ouverture : 0 pour lecture, 1 pour écriture
 * @return le pointeur de fichier
 */
FILE* ouvrir (char* nomFichier, int mode)
{
	FILE* f = NULL;
	if (mode==0) f = fopen(nomFichier, "r");	
	else f = fopen(nomFichier, "w");
	
	if (f != NULL)
  	return f;
	else
	{
		printf("Erreur lors de l'ouverture du fichier %s\n",nomFichier);
		return NULL;
	}
}



/*
 * Ferme le fichier
 * @param fichier le pointeur de fichier à fermer
 * @return 0 si la fermeture s'est bien déroulée, != 0 sinon
 */
int fermer (FILE* fichier)
{
	return fclose(fichier);
}


static unsigned int reste = 0; // représente les bits restants (à ajouter au prochain code...)
static unsigned int nbReste = 0; // taille (en bit) du reste
static unsigned int nbBits = 9; // taille (en bit) sur laquelle est codée tout caractère (variable au cours du temps)

/*
 * Ecrit (en binaire) l'entier v dans le fichier pointé par f
 * @param f le pointeur sur le fichier (le fichier doit etre ouvert !)
 * @param v l'entier à écrire
 * @return 0 si OK
 */
int ecrire(FILE* f, int v)
{
	unsigned int buffer = v;
	char aEcrire;

	unsigned int restePrecedent,ajoutCourant;
	unsigned int codeSpecial=0;
	
	// On extrait les bits de poids faibles necessaires
	buffer = buffer & (~0>>(sizeof(int)*8-nbBits)); //creerMasque(nbBits);

	// On constitue ensuite l'octet à écrire, en fonction :
	// 	 - d'un eventuel reste précédent
	//   - des bits de poids forts extraits ci-dessus
	restePrecedent = (reste << (8-nbReste)) & 0xFF;
	ajoutCourant = (buffer >> (nbReste+nbBits-8)) & 0xFF;

	aEcrire = (restePrecedent | ajoutCourant);

	// On sauvegarde les bits restants (écriture future)
	nbReste = (nbReste + nbBits - 8);
	reste = buffer & (~0>>(sizeof(int)*8-nbReste)); //creerMasque(nbReste);

	fwrite(&aEcrire,1,1,f);

	// On imprime le reste (octets entiers disponibles dans reste
	while(nbReste > 7)
	{
		buffer = reste & (~0>>(sizeof(int)*8-(nbReste-8))); //creerMasque(nbReste-8);
		aEcrire = (reste >> (nbReste-8)) & 0xFF;
		fwrite(&aEcrire,1,1,f);
		reste = buffer;
		nbReste = nbReste - 8;
	}

	// Traitement spécifique si l'entier symbolise la fin du fichier
	// On complète avec des 0 pour terminer l'octet restant (et on l'écrit).
	if (v==FIN)
	{
			while(nbReste < 8)
			{
				reste = reste << 1;
				nbReste++;
			}
			reste = reste & 0xFF;

			fwrite(&reste,1,1,f);
	}
	
	return 0;

}

/*
 * Lit (en binaire) la valeur courante présente dans le fichier pointé par f
 * @param f le pointeur sur le fichier (le fichier doit etre ouvert !)
 * @param value la valeur de l'entier lu
 * @return 0 si OK
 */
int lire (FILE* f, int* value)
{
	unsigned int buffer;	
	unsigned int aLire;

	// On complète le reste courant jusqu'à avoir un code complet (ou plus)
	while(nbReste<nbBits)
	{
		fread(&buffer,1,1,f);
		reste = (reste << 8) | (buffer & 0xFF);
		nbReste = nbReste + 8;
	}
	
	// On extrait le code courant
	aLire = reste >> (nbReste-nbBits);
	*value = aLire;

	// On sauvegarde le reste pour la prochaine lecture
	//printf("nbReste %d nbBits %d Masque %d\n",nbReste,nbBits,(~0>>(sizeof(int)*8-(nbReste-nbBits))));
	reste = reste &  creerMasque(nbReste-nbBits);//(~(unsigned)0>>(sizeof(int)*8-(nbReste-nbBits)));//
	nbReste = nbReste - nbBits;

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

/*
 * Modifie la valeur de nbBits
 * @param valeur la nouvelle valeur de nbBits
 * @return 0 si OK
 */
int setNbBits (int valeur)
{
	nbBits = valeur;
	return 0;
}

/*
 * Incrémente nbBits
 * @return 0 si OK
 */
int incNbBits ()
{
	nbBits++;
	return 0;
}

/*
 * Récupère la valeur de nbBits
 * @return nbBits
 */
int getNbBits ()
{
	return nbBits;
}
