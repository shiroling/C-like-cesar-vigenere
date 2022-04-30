#include "vigenere.h"

int getOffcet(char c) {
    return tolower(c) - 'a';
}

char *chiffrementVigenere(char *cle, char *messageClair) {

    int len = strlen(messageClair);
    int lencle =strlen(cle);
    int c;
    char *messageChiffré =  (char*)calloc( sizeof(char),  len + 1);
    
    for (int i = 0; i < len; ++i)
    {
        if  (isupper(messageClair[i])){
            messageChiffré[i]= (messageClair[i]+ getOffcet(cle[i% lencle])- 'A') % 26 + 'A';
        }else 
        if  (islower(messageClair[i])) {
            messageChiffré[i]= (messageClair[i] + getOffcet(cle[i% lencle]) - 'a') % 26 + 'a';
        }else
        if  (isdigit(messageClair[i])) {
            messageChiffré[i]= (messageClair[i] + getOffcet(cle[i% lencle]) - '0') % 10 + '0';
        }else 
        if (messageClair[i] == ' ') { // espaces
            messageChiffré[i]= ' ';
        }
        else {
            printf("FAILURE : Can't manage the %c character\n", messageClair[i]);
            exit(EXIT_FAILURE);
        }
    }
    return messageChiffré;
}


char *déchiffrementVigenere(char *cle, char *messageChiffré) {
    int len = strlen(messageChiffré);
    int lencle =strlen(cle);

    char *messageClair =  (char*)calloc( sizeof(char), len + 1);

    for (int i = 0; i < len; ++i)
    {
        if  (isupper(messageChiffré[i])){
            messageClair[i]= 'A' + (messageChiffré[i] - getOffcet(cle[i% lencle]) - 'A' + 26) % 26;
        }else 
        if (islower(messageChiffré[i])){
            messageClair[i]= 'a' + (messageChiffré[i] - getOffcet(cle[i% lencle]) - 'a' + 26) % 26;
        }else
        if  (isdigit(messageChiffré[i])) {
            messageClair[i]= '0' + (messageChiffré[i] - getOffcet(cle[i% lencle]) - '0' + 10) % 10;
        }else 
        if (messageChiffré[i] == ' ') { // espaces
            messageClair[i]= ' ';
        }
        else {
            printf("FAILURE : Can't manage the %c character\n", messageChiffré[i]);
            exit(EXIT_FAILURE);
        }    
    }
    return messageClair;
}