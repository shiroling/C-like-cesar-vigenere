#include "argParser.h"

void printHelp() {
	printf("The argument -h take you to this help page.\n\n");
	printf("Chose your codage algoritim with :\n\t-c\tCesar\n\t-v\tVigenere\n\n");
	printf("Then add arguments like :\n\t-k\tFor the encription key\n\t--encode / --decode\tTo code or decode the input message.\n\n");
	printf("Also you can let the output directly to a file with :\n\t-o\tFollowed by the output file path.\n");
	printf("Note\n- If the output file exist text will be append to it, if not it will be created.\n");
	printf("- The message will be asked to you during the execution time.\n");
	printf("- By default the program will encode in cesar with a key of 0.\n");
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
	struct Parameters result = {cesar, encode, 0, "a","PlaceOlder666"};
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

	printf(" clé cesar: %d\n", p.dkey);
	printf(" clé vigenère: %s\n", p.ckey);
	if (isOutputFile(p))
	{
		printf("the output will be saved at: %s\n", p.filepath);
	}
}
