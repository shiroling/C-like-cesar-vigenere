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
*  Nom du fichier :  argParser.c                                              *
*                                                                             *
******************************************************************************/

#include "../includes/argParser.h"

// Fonction d'aide pour l'utilisation du programme
void printHelp() {
	printf("l'argument -h vous amméne sur cette belle page d'aide.\n\n");
	printf("Pour choisir un algorithme de codage : \n\t-c ou -v\t Pour Cesar ou Vigenere\n\n");
	printf("Choisissez si vous voulez encoder ou décoder :\n\t--encode / --decode\t\n\n");
	printf("Pour enregistrer le résultat dans un fichier faites :\n\t-o\tSuivit par le chemin du fichier.\n");
	printf("Note\n- Le fichier de sortie peut étre créé en écrasant un fichier existant du même nom.\n");
	printf("- Votre message et la clé vous seront demandés pendant l'éxécution du script.\n");
	printf("- Par défaut le programme encoderas en cesar avec une clé de 0.\n");
}

// retourne un entier en fonction de la place de l'argument donné, -1 sinon
// Cela permet l'utilisation d'un switch/case pour le tri des arguments.
int getArgId(const char *arg) {
	for (int i = 0; i < 7; ++i)
	{
		if (strcmp(arg, arguments[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}

// Fonction de côtrole pour savoir si le fichier à été fournit.
bool isOutputFile(struct Parameters p) {
	if (strcmp(p.filepath, "PlaceOlder666")== 0)
		return false;

	return true;
}


// Cette fonction permet de gérer le argument de commande de notre programme
parameters getParameters(int argc, char const *argv[]) {
	struct Parameters result = {cesar, encode,"PlaceOlder666"};
	for (int i = 1; i < argc; ++i)
	{
		if (getArgId(argv[i]) == -1)
		{
			printf("L'argument %s est invalide.\n", argv[i]);
			exit(EXIT_FAILURE);
		}else
		{
			switch (getArgId(argv[i]))				// Ici nous prenons les argument de ligne de commande
			{										// et les stockons dans une structure dédié (voir Argparser.h)
			    case 0:
			        printHelp();
			        exit(1);
			    case 1:
			        result.chosenAlgo = cesar;
			        break;
			    case 2:
			        result.chosenAlgo = vigenere;
			        break;
			    case 3:
			        result.codeOrDecode = encode;
			        break;
			    case 4:
			        result.codeOrDecode = decode;
			        break;
			    case 5:
			    	i++;
			    	if(i >= argc) {
			    		printf("Il manque le chemin d'accés à votre fichier\n");
						exit(EXIT_FAILURE);
			    	}

			        strcpy(result.filepath, argv[i]);
			        break;
			}
		}
	}
	return result;
}

// Fonction de debug
void printParamters(struct Parameters p) {
	printf("This program will ");
	if (p.codeOrDecode == encode) {
		printf("encode");
	}
	else if (p.codeOrDecode == decode) {
		printf("decode");
	}

	printf(" your message using ");
	if (p.chosenAlgo == cesar) {
		printf("Cesar");
	}
	else if(p.chosenAlgo == vigenere) {
		printf("Vigenere");
	}
	if (isOutputFile(p))
	{
		printf("the output will be saved at: %s\n", p.filepath);
	}
}
