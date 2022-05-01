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
*  Nom du fichier :  argParser.h                                              *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define ARG_MAX_LEN 8

// enumérations pour simplifier les structures de contrôles du programme
// il est possible grace a cette structure de faire des switch/case plustot que des if(strcmp()) par exemple.
typedef enum {
	cesar = 0,
	vigenere = 1
} algo;

typedef enum {
	encode = 0,
	decode = 1
} action;

// Structure renvoyé par le parser d'argument de main.
typedef struct Parameters{
    algo chosenAlgo;
    action codeOrDecode;
    char filepath[1024];
} parameters;

static const char* const arguments[] = {"-h", "-c", "-v", "--encode", "--decode", "-o"};

void printHelp();
void printParamters(struct Parameters p);

bool isOutputFile(struct Parameters p);

int getArgId(const char *arg);

struct Parameters getParameters(int argc, char const *argv[]);