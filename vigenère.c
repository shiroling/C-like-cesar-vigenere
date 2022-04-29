#include "vigenère.h"

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
        }else {
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
        }else {
            printf("FAILURE : Can't manage the %c character\n", messageChiffré[i]);
            exit(EXIT_FAILURE);
        }    
    }
    return messageClair;
}

/*
int main(int argc, char const *argv[])
{
    size_t bufsize = BUFF;

    char cle2[BUFF];
    printf("Donnez une clée de cryptage (lettre) :\t");
    scanf("%s", cle2);

    char messageClair[BUFF];
    printf("Donnez à présent votre message (ne sautez de ligne qu'à la fin) :");
    scanf("%s", messageClair);

    char mess1[BUFF], mess2[BUFF];

    strncpy(mess1, chiffrementVigenere(cle2, messageClair), BUFF);
    printf("chiffré:\t %s\n", mess1);

    strcpy(mess2, déchiffrementVigenere(cle2, mess1));
    printf("déchiffré:\t .%s.\n", mess2);


    return 0;
}

*/