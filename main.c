#include "argParser.h"

int main(int argc, char const *argv[])
{
	if(argc < 2) {
		printf("Missing arguments try -h to see the help page\n");
		return 1;
	}

	struct Parameters p =	getParameters(argc, argv);

	printParamters(p);

	printf("Please, Can you give your message in one line.\t(It must be alphanumeric an it can have accentuate characters in it)\nNote that accentuate characters will be replace by ASCII letters\n\nYour message:\n");



	//printHelp();
	return 0;
}