#include <wctype.h>
#include <wchar.h>
#include <stdlib.h>
#include <ctype.h>

#include "argParser.h"
#include "controleEntree.h"
#include "vigenère.h"

#define BUFF 2048


char *cesarPart(action cOd, int cle,  char *messageClair) {
	switch (cOd)	{
    case 0:			//cas encode
        printf("@ encode, cesar\n");
        break;
    case 1:			//cas decode
        printf("@ decode, cesar\n");

        break;
	default:
        printf("Il y a un probléme avec l'algo choisi\n");
		break;
	}

	exit(EXIT_FAILURE);
}

char *vigenerePart(action cOd, char* cle, char *message) {

	switch (cOd)	{
    case 0:			//cas encode
        	printf("@ encode, vig\n");
        	printf("%s\n", chiffrementVigenere(cle, message));
        	return chiffrementVigenere(cle, message);
        break;
    case 1:			//cas decode
        	printf("@ decode, vig\n");
			return déchiffrementVigenere(cle, message);
        break;
	default:
        printf("Il y a un probléme avec l'algo choisi\n");
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

	printParamters(p);

	size_t bufsize = BUFF;
    char mes[BUFF];
	printf("SVP, Donnez lz message.\t(si c'est pour un chiffrement, il peut contenir des accents)\nLes accents seront convertis en lettre classiques\n\nVotre message:\n");
    scanf("%s", mes);

	wchar_t wmessage[BUFF];
	mbstowcs(wmessage, mes, BUFF);

	if(!verifierAlphanumérique(wmessage)) {
		printf("Erreur: le message contient de charactéres contre-indiqués\n");
		exit(EXIT_FAILURE);
	}

	char *message = convertirEspaces( convertirAccents(wmessage));

	switch (p.chosenAlgo)	{
	    case 0:			//cas ou l'on cesar
	    	int dcle = 0;
	    	printf("Entrez la clé pour l'algorithme de césar\n");
	    	scanf("%d", &dcle);
	    	message = cesarPart(p.codeOrDecode, dcle,  message);
	        break;
	    case 1:			//cas ou l'on vigenère
    	    size_t bufsize = BUFF;
		    char ccle[BUFF];
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
	    	printf("clé valide\n");
		    message = vigenerePart(p.codeOrDecode, ccle, message);

	        break;
		default:
	        printf("Il y a un probléme avec l'action choisie\n");
			break;
	}

	printf("final: %s\n", message);

	return 0;
}