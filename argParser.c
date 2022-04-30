#include "argParser.h"

void printHelp() {
	printf("l'argument -h vous amméne su cette belle page d'aide.\n\n");
	printf("pour choisir un algorithme de codage : \n\t-c\tCesar\n\t-v\tVigenere\n\n");
	printf("Choisissez si vous voulez encoder ou décoder :\n\t--encode / --decode\t\n\n");
	printf("Pour enregistrer le résultat dans un fichier faites :\n\t-o\tSuivit par le chemin du fichier.\n");
	printf("Note\n- Le fichier de sortie peut étre créé en écrasant un fichier exixtant du méme nom.\n");
	printf("- Votre message et la clé vous seront demandés pendant l'éxécution du script.\n");
	printf("- Par défaut le programme encoderas en cesar avec une clé de 0.\n");
}

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

bool isOutputFile(struct Parameters p) {
	if (strcmp(p.filepath, "PlaceOlder666")== 0)
		return false;

	return true;
}



parameters getParameters(int argc, char const *argv[]) {
	struct Parameters result = {cesar, encode,"PlaceOlder666"};
	for (int i = 1; i < argc; ++i)
	{
		if (getArgId(argv[i]) == -1)
		{
			printf("%s is not a valid argument\n", argv[i]);
			exit(EXIT_FAILURE);
		}else
		{
			switch (getArgId(argv[i]))
			{
			    case 0:
			        printHelp();
			        exit(1);
			        break;
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
			    		printf("Missing argument after: %s\n", argv[i-1]);
						exit(EXIT_FAILURE);
			    	}

			        strcpy(result.filepath, argv[i]);
			        break;
			    default:
			        printf("Error fall into default statement\n");
					exit(EXIT_FAILURE);

			}
		}


	}
	return result;
}


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
