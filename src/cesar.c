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
*  Nom du fichier : cesar.c                                                   *
*                                                                             *
******************************************************************************/

#include "../includes/cesar.h"

// fonction chiffrant le message de type char * en César avec la clé donné (int cle). 
char *chiffrementCesar(char *text,int cle) {
    int i = 0;
    char *messageChiffré =  (char*)calloc( sizeof(char),  strlen(text) + 1);

    while (text[i] != '\0') {
        if  (isupper(text[i])){
            messageChiffré[i]= (text[i]+ cle - 'A') % 26 + 'A';
        }else 
        if  (islower(text[i])) {
            messageChiffré[i]= (text[i] + cle - 'a') % 26 + 'a';
        }else
        if  (isdigit(text[i])) {
            messageChiffré[i]= (text[i] + cle - '0') % 10 + '0';
        }else 
        if (text[i] == ' ') {       // Les espaces sont reportéstels quel.
            messageChiffré[i]= ' ';
        }
    i++;
    }
    return messageChiffré;
}

// fonction déchiffrant le message de type char * en César avec la clé donné (int cle). 
char *déchiffrementCesar(char *messageChiffré, int cle) {
    int len = strlen(messageChiffré);

    char *messageClair =  (char*)calloc( sizeof(char), len + 1);

    for (int i = 0; i < len; ++i)
    {
        if  (isupper(messageChiffré[i])){
            messageClair[i]= 'A' + (messageChiffré[i] - cle - 'A' + 26) % 26;
        }else 
        if (islower(messageChiffré[i])){
            messageClair[i]= 'a' + (messageChiffré[i] - cle - 'a' + 26) % 26;
        }else
        if  (isdigit(messageChiffré[i])) {
            messageClair[i]= '0' + (messageChiffré[i] - cle - '0' + 10) % 10;
        }else 
        if (messageChiffré[i] == ' ') { // Les espaces sont reportéstels quel.
            messageClair[i]= ' ';
        }   
    }
    return messageClair;
}