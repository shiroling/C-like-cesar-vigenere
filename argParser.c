#include "argParser.h"

void printHelp() {
	printf("The argument -h take you to this help page.\n\n");
	printf("Chose your codage algoritim with :\n\t-c\tCesar\n\t-v\tVigenere\n\n");
	printf("Then add arguments like :\n\t-k\tFor the encription key\n\t--encode / --decode\tTo code or decode the input message.\n\n");
	printf("Also you can let the output directly to a file with :\n\t-o\tFollowed by the output file path.\n");
	printf("Note\n- If the output file exist text will be append to it, if not it will be created.\n");
	printf("- You can pipe the message to this program or it will be asked to you during the execution time.\n");
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
	struct Parameters result = {cesar, encode, 0, "PlaceOlder666"};
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
			    	i++;
			    	for (int j = 0; j< strlen(argv[i]); ++j)
			    	{
			    		if (!isdigit(argv[i][j]))
			    		{
			    			printf("Key %s is not a digit\n", argv[i]);
			    			exit(EXIT_FAILURE);
			    		}
			    	}
			        result.key = atoi(argv[i]);
			        if (result.key == 0)
			        {
			        	printf("Warning, the key has been interpreted as 0.\n");
			        }
			        break;
			    case 4:
			        result.codeOrDecode = encode;
			        break;
			    case 5:
			        result.codeOrDecode = decode;
			        break;
			    case 6:
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
	if (p.chosenAlgo == cesar) {
		printf("code : Cesar\n");
	}
	else if(p.chosenAlgo == vigenere) {
		printf("code : Vigenere\n");
	}
	else printf("code : UNDEFINED\n");

	if (p.codeOrDecode == encode) {
		printf("to encode\n");
	}
	else if (p.codeOrDecode == decode) {
		printf("to decode\n");
	}
	else printf("action: UNDEFINED\n");

	printf("The key is %d\n", p.key);
	if (isOutputFile(p))
	{
		printf("output file %s\n", p.filepath);
	}else {
		printf("No output file defined\n");
	}

}
