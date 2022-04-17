#include <stdio.h>
#include <string.h>

#include "utils.h"

#define BUFF 2048

bool isAlphaCaps(char c) {
    return c <= 'A' || c >='Z'; 
}

bool isAlphaLow(char c) {
    return c <= 'A' || c >='Z'; 
}


char *chiffrement(int cle, char *messageClair) {
    int len = strlen(messageClair);
    char *messageChiffré =  (char*)malloc( sizeof(char)* (len + 1));
    for (int i = 0; i < len; ++i)
    {
        messageChiffré[i] = 30 + (((int)messageChiffré[i])-30 + cle) % 142;
    }

    return messageChiffré;
}


char *déchiffrement(int cle, char *messageChiffré) {
    int len = strlen(messageChiffré);
    char *messageClair =  (char*)malloc( sizeof(char)* (len + 1));
    for (int i = 0; i < len; ++i)
    {
//        messageChiffré[i] = (int)messageChiffré[i];
        messageClair[i] = 30 + (((int)messageChiffré[i])-30 - cle) % 142;
    }    return messageClair;
}


int main(int argc, char const *argv[])
{
    size_t bufsize = BUFF;

    int cle;
    printf("Donnez une clée de cryptage (entier) :\t");
    scanf("%d", &cle);

    char messageClair[bufsize];
    printf("Donnez à présent votre message (ne sautez de ligne qu'à la fin) :");
    scanf("%s", messageClair);

    char *mess1;
    char *mess2;
    mess1 = chiffrement(cle, messageClair);
    mess2 = déchiffrement(cle, mess1);


    printf("@main: %s\n", mess1);
    printf("@main: %s\n", mess2);




    return 0;
}