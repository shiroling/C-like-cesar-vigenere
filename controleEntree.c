#include "controleEntree.h"

#define BUFF 2048

char *getInputMessage() {
    size_t bufsize = BUFF;
    char mess[BUFF];
    printf("SVP, Donnez le message. (Il peut contenir des accents)\nLes accents seront convertis en lettre classiques\nVotre message:\n");
    scanf("%[^\n]s", mess);
    mess[strlen(mess)] = '\0';

    if(!verifierAlphanumérique(mess)) {
        printf("Erreur: le message contient de charactéres contre-indiqués\n");
        exit(EXIT_FAILURE);
    }

    char *message = calloc(sizeof(char), strlen(mess));
    strcpy(message, mess);
    return message;
}

//------------------------------
//---------VERIFICATION---------
//------------------------------
// Fonctionnel mais pas utilisé car l'accisition de la chaine d'entrée en wchar_t ne marche pas

int isAccent(wchar_t wcIn) {
    wchar_t *accent = L"ÀÁÂÃÄÅàáâãäåÒÓÔÕÖØòóôõöøÈÉÊËèéêëÌÍÎÏìíîïÙÚÛÜùúûüÿÑñÇç";
                     //"AAAAAAaaaaaaOOOOOOooooooEEEEeeeeIIIIiiiiUUUUuuuuyNnCc"
    for (int i = 0; i < 53; ++i)
    {
        if (wcIn == accent[i])
            return i;
    }
    return -1;
}

bool verifierAlphanumérique(char *str) {
    for (int i = 0; i < strlen(str); ++i)
    {
        if (!(isalnum(str[i]) || str[i] == ' '))
        {
            printf("%d, %c\n", i, str[i]);
            return false;
        }
    }
    return true;
}


//------------------------------
//----------TRAITEMRNT----------
//------------------------------
// Cette partie là du code mache mais n'est pa utilisé car l'accisition de la chaine d'entrée en wchar_t ne marche pas

char *convertirAccents(wchar_t *wcstr) {
    // 2nd partie de la table de correspondance des accents, la premiére étant dans int isAccent(wchar_t wstrIn).
    char sansAccent[53] = "AAAAAAaaaaaaOOOOOOooooooEEEEeeeeIIIIiiiiUUUUuuuuyNnCc";
    int taille = wcslen(wcstr);
    int index;                                 //taille de la chaine et index pour la table de correspondace des accents.

    char *messageNonAccent = (char*)calloc(sizeof(char), taille);       // Allocation dynamique de la chaine de charactére en entrée.
    
    for (int i=0;i<taille;i++)              // on parcourt la chaine d'entrée
    {
        index = isAccent(wcstr[i]);        // on teste si il y a un accent à la position courante
        if (index != -1)
        {                                   // Si oui on le remplace 
            messageNonAccent[i] = sansAccent[index];
            printf("%d", index);
        }else                               // Si non on convertis la charactére pour le bon type
        {
            messageNonAccent[i] = wcstr[i];
        }

    }
    return messageNonAccent;
}