#include "argParser.h"

int main(int argc, char const *argv[])
{
	//printHelp();
	struct Parameters p =	getParameters(argc, argv);
	printParamters(p);
	return 0;
}