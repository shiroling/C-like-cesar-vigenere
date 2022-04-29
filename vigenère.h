#include <stdio.h>
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFF 2048

int getOffcet(char c);

char *chiffrementVigenere(char *cle, char *messageClair);

char *déchiffrementVigenere(char *cle, char *messageChiffré);