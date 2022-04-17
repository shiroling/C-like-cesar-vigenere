#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>      // wide character string
#include <string.h>
#include <stdbool.h>
#include <wctype.h>


char *replaceSpaces(char* str) {
    for (int i = 0; i < strlen(str); ++i)
    if (str[i] == ' ')
        str[i] = '`';   // ici on remplace les espace pas le charactére  `  qui est adjacent dans la table à [a-z] dans la table ASCII
    return str;
}

int isAccent(wchar_t wstrIn) {
    wchar_t accent[53] = L"ÀÁÂÃÄÅàáâãäåÒÓÔÕÖØòóôõöøÈÉÊËèéêëÌÍÎÏìíîïÙÚÛÜùúûüÿÑñÇç";

    for (int i = 0; i < 53; ++i)
    {
        if (wstrIn == accent[i])
            return i;
    }
    return -1;
}

bool isAlphaNum(wchar_t *wstr) {
    bool ui = true;
    for (int i = 0; i < wcslen(wstr); ++i)
    {
        if (!iswalnum(wstr[i]) && isAccent(wstr[i]) == -1)
        {
            wprintf(L"non-alphaNum char at %d is %c\n", i, wstr[i]);
            ui = false;
        }
    }
    return ui;
}

char *retireAccent(wchar_t *wstrIn)
{
    char sansAccent[53] = "AAAAAAaaaaaaOOOOOOooooooEEEEeeeeIIIIiiiiUUUUuuuuyNnCc";
    int taille = wcslen(wstrIn), seek;
    char *messageNonAccent = (char*)calloc(sizeof(char), taille);
    for (int i=0;i<taille;i++)
    {
        for (int j = 0; j < 53; ++j)
        {
            seek = isAccent(wstrIn[i]);
            if (seek != -1)
            {
                printf("accent en pos : %i\n", i);
                messageNonAccent[i] = sansAccent[seek];
            }else
            {
                printf("'-' en pos : %i\n", i);
                messageNonAccent[i] = '-';
                break;
            }
        }
        
    }
 
    return messageNonAccent;
}


int main() {
    
    wchar_t *mess = L"ÀAZEÁOâ";
    if(isAlphaNum(mess)) {
        printf("the message is alphaNum\n");
    char * messNonAccent = retireAccent(mess);
    printf("%s\n", messNonAccent);
    }
    



}