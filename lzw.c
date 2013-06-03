/**
* Auteurs : Jérôme Barbier, Augustin Husson, Mehdi NS, David Levayer
* Date : 28/05/2013
* Projet : Compression
* Version : 1.0
**/

#include "lzw.h"

void ecrireCode (Code c, char *a)
{
	int i;
	/*for(i=0;i<c.taille;i++)
	{
		if(c.valeur[i]==0xD&&c.valeur[i]==0xA)printf("_"); 
		else printf("%c",c.valeur[i]);
	}
	if(*a==0xD&&*a==0xA)printf("_"); 
	else printf("%c (en hexa: ",*a);*/
	for(i=0;i<c.taille;i++)
	{
		printf("%x",c.valeur[i]);
	}
	printf("%x)",*a);
}

/**
*
*
**/
int compresser (FILE *fi, FILE *fo)
{
	Code w;
	int a;
	int code;
	int nbBitsCourant = 0;
	int nbOctetsCompresses = 0;
	int tailleFichierSortie = 0;

	// Initialisation du dictionnaire
	initialiser();

	// Initialisation des places disponibles dans le dictionnaire (pour un nombre de bits donné)
	int placesDisponibles = 512 - 256 - 10; // 2^9 - 2^8 (mono-octets) - 10 (reservé)

	w.valeur = malloc (sizeof(char));
	w.valeur[0] = fgetc(fi);
	w.taille = 1;
	while ((a = fgetc(fi)) != EOF)
	{
		nbOctetsCompresses++;
		tailleFichierSortie+=getNbBits();

		if (rechercher(w,(char*)&a,&code))
		{
			w = fusion (w,(char*)&a); // w <--- w + a (avec taille++ inclu)
			continue;
		}
		else
		{
			if(!rechercher(w,NULL,&code)) { printf("Erreur fatale\n");exit(0);}
			nbBitsCourant+=getNbBits();
			printf("%d (nbBits %d) ",code,nbBitsCourant);
			ecrire(fo,code);	
			if (placesDisponibles==0) 
			{
				if (getNbBits()<100)
				{
					//printf("Places disponibles sur %d bits : %d\n",getNbBits(),placesDisponibles);
					placesDisponibles = 1 << getNbBits();
					nbBitsCourant+=getNbBits();
					ecrire(fo,INC);
					printf("%d\n",INC);
					incNbBits();
					//printf("Nouvelle valeur de PlacesDispos : %d (sur %d bits)\n",placesDisponibles,getNbBits());
				}
				else
				{
					//printf("Réinitialisation du dictionnaire\n");
					placesDisponibles = 512 - 256 - 10;
					ecrire(fo,RAZ);
					//printf("%d\n",code);
					setNbBits(9);
				}
			}

			ajouterElement(w,(char*)&a);
			printf(" (ajout du mot :");
		  ecrireCode(w,(char*)&a);
			*w.valeur = a;
			w.taille = 1;
			placesDisponibles--;
			printf(") (places disponibles : %d)\n",placesDisponibles);
		}
	}

	// Traiter dernier
	rechercher(w,NULL,&code);
	nbBitsCourant+=getNbBits();
	ecrire(fo,code);
	printf("%d\n",code);
	nbOctetsCompresses++;

	// Fin de fichier
	nbBitsCourant+=getNbBits();
	ecrire(fo,FIN);

	printf("%d\n",FIN);
	// Statistiques
	printf("Nombre d'octets traités : %d\n",nbOctetsCompresses);
	afficherListe();
	return 0;
}

/**
*
*
**/
int decompresser(FILE* fi, FILE* fo)
{

	int i,i2,lg,lg2,j;
	int a;
	Code w,w2;
	unsigned char *buffer;

	int nbOctetsExtraits = 0;
	
	int arret = 0;
	
	int placesDisponibles = 512 - 256 - 10;
	// Initialisation du dictionnaire
	initialiser();
	
	// Traitement du premier caractère
	lire(fi,&i); 
	a = codeVersChaine(i,&lg)[0];
	w.valeur = malloc(lg*sizeof(char));
	*w.valeur = a;
	w.taille = lg;
	fwrite(w.valeur,1,1,fo);

	printf("%d\n",a);

	
	while (!arret)
	{


		lire(fi,&i2); nbOctetsExtraits++;
		printf("%d",i2);
		if(i2==FIN) 
		{	arret = 1; }		
		else if(i2==INC) 

		{
			printf("Augmentation du nombre de bits : %d --> ",getNbBits());
			placesDisponibles = 1 << getNbBits();
			incNbBits();
			printf("%d\n",getNbBits());
		}
		else if(i2==RAZ) 
		{
			setNbBits(9);
		}
		else {
		codeVersChaine(i2,&lg2);
		if (i2==0) printf("####################################");
		if (lg2==0)
		{
			buffer = codeVersChaine(i,&lg);
			w2.valeur = malloc(lg*sizeof(char));

			w2.taille = lg;
			for(j=0;j<w2.taille;j++)
				w2.valeur[j] = buffer[j];
			
			w2 = fusion(w2,(char*)&a);
		}
		else
		{	
			buffer = codeVersChaine(i2,&lg2);
			w2.valeur = malloc(lg2*sizeof(char));
		
			w2.taille = lg2;
			for(j=0;j<w2.taille;j++)
				w2.valeur[j] = buffer[j];

		}
		
		buffer = codeVersChaine(i,&lg);
		w.valeur = malloc(lg*sizeof(char));
		
		w.taille = lg;
		for(j=0;j<w.taille;j++)
			w.valeur[j] = buffer[j];


		//fwrite(w2.valeur,w2.taille,1,fo);
		for(j=0;j<w2.taille;j++)
		{
			fwrite(w2.valeur+j,1,1,fo);
		}
		a = w2.valeur[0];
		ajouterElement(w,(char*)&a);
		placesDisponibles--;
		printf(" (ajout du mot :");
		ecrireCode(w,(char*)&a);
		printf(" (places disponibles après ajout : %d)\n",placesDisponibles);
		i = i2;
		lg = lg2;
		}
		
	}

	printf("Nombre d'octets traités : %d\n",nbOctetsExtraits);

	afficherListe();
	return 0;
}
