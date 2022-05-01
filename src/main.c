/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            * 
*******************************************************************************
*                                                                             *
*  Intitulé :    Chiffrement de messages                                      *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : COUTURIER Quentin                                            *
*                                                                             *
*  Nom-prénom2 : CHELLE Elena                                                 *
*                                                                             *
*  Nom-prénom3 : FERREIRA Iannis                                              *
*******************************************************************************
*                                                                             *
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/argParser.h"
#include "../includes/controleEntree.h"
#include "../includes/vigenere.h"
#include "../includes/cesar.h"

#define BUFFER 2048


char *cesarPart(action cOd, int cle,  char *messageClair) {
	switch (cOd)	{
    case 0:			//cas encode
        return chiffrementCesar(messageClair, cle);
        break;
    case 1:			//cas decode
    	return déchiffrementCesar(messageClair, cle);
        break;
	default:
        printf("Il y a un probléme avec l'algo de césar\n");
		break;
	}

	exit(EXIT_FAILURE);
}

char *vigenerePart(action cOd, char* cle, char *message) {

	switch (cOd)	{
    case 0:			//cas encode
        	return chiffrementVigenere(cle, message);
        break;
    case 1:			//cas decode
			return déchiffrementVigenere(cle, message);
        break;
	default:
        printf("Il y a un probléme avec l'algo de vigenère\n");
		break;
	}

	exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
	if(argc < 2) {
		printf("Il manque des arguments, faites -h pour consulter l'aide\n");
		return 1;
	}

	struct Parameters p = getParameters(argc, argv);

	char *message = getInputMessage();

	switch (p.chosenAlgo)	{
	    case 0:			//cas cesar
	    	int dcle = 0;
	    	printf("Entrez la clé pour l'algorithme de césar (nombre) : \t");
	    	scanf("%d", &dcle);
	    	message = cesarPart(p.codeOrDecode, dcle,  message);
	        break;
	    case 1:			//cas ou l'on vigenère
    	    size_t bufsize = BUFFER;
		    char ccle[BUFFER];
		    printf("Entrez la clé pour l'algorithme de vigenère (lettre) :\t");
		    scanf("%s", ccle);
	    	
	    	for (int j = 0; j < strlen(ccle); ++j)
	    	{
	    		if (!isalpha(ccle[j]))
	    		{
	    			printf("La clé vigenère n'est pas valide\n");
	    			exit(EXIT_FAILURE);
	    		}
	    	}
		    message = vigenerePart(p.codeOrDecode, ccle, message);

	        break;
		default:
	        printf("Il y a un probléme avec l'action choisie\n");
			break;
	}

	printf("Message final:\n%s\n", message);

	if (isOutputFile(p))
	{
		FILE *fic = fopen(p.filepath , "w+");
		if (fic == NULL)
		{
			printf("Le programme n'as pas pu écrire dans le fichier donné\n");
			exit(EXIT_FAILURE);
		}

		fprintf(fic, "Message final:\n%s\n", message);
		fclose(fic);
	}


	return 0;
}