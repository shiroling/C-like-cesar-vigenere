#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define ARG_MAX_LEN 8

typedef enum 
{
	cesar = 0,
	vigenere = 1
}algo;

typedef enum 
{
	encode = 0,
	decode = 1
}action;

typedef struct Parameters{
    algo chosenAlgo;
    action codeOrDecode;
    int key;
    char filepath[1024];
} parameters;

static const char* const arguments[] = {"-h", "-c", "-v", "-k", "--encode", "--decode", "-o"};
void printHelp();
void printParamters(struct Parameters p);

bool isOutputFile(struct Parameters p);
bool isComplete(struct Parameters p);

int getArgId(const char *arg);

struct Parameters getParameters(int argc, char const *argv[]);