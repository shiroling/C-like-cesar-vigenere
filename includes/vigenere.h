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
*  Nom du fichier : vigenere.h                                                *
*                                                                             *
******************************************************************************/


#include <stdio.h>
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFF 2048

int getOffcet(char c);

// fonction chiffrant le message de type char * en Vigenère avec la clé donné en char*. 
char *chiffrementVigenere(char *cle, char *messageClair);

// fonction déchiffrant le message de type char * en Vigenére avec la clé donné en char *. 
char *déchiffrementVigenere(char *cle, char *messageChiffré);