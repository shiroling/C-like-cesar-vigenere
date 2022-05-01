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
*  Nom du fichier :  cesar.h                                                  *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// fonction chiffrant le message de type char * en César avec la clé donné (int cle). 
char *chiffrementCesar(char *text,int cle);

// fonction déchiffrant le message de type char * en César avec la clé donné (int cle). 
char *déchiffrementCesar(char *text,int cle);