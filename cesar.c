#include "cesar.h"

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
        if (text[i] == ' ') {       // espaces
            messageChiffré[i]= ' ';
        }
        else {
            printf("FAILURE : Can't manage the %c character\n", text[i]);
            exit(EXIT_FAILURE);
        }
    i++;
    }
    return messageChiffré;
}


char *déchiffrementCesar(char *messageChiffré,int cle) {
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