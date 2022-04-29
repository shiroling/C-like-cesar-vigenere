#include "controleEntree.h"

//------------------------------
//---------VERIFICATION---------
//------------------------------

int isAccent(wchar_t wstrIn) {
    wchar_t accent[53] = L"ÀÁÂÃÄÅàáâãäåÒÓÔÕÖØòóôõöøÈÉÊËèéêëÌÍÎÏìíîïÙÚÛÜùúûüÿÑñÇç";

    for (int i = 0; i < 53; ++i)
    {
        if (wstrIn == accent[i])
            return i;
    }
    return -1;
}

bool verifierAlphanumérique(wchar_t *wstr) {
    for (int i = 0; i < wcslen(wstr); ++i)
    {
        if (!iswalnum(wstr[i]) && isAccent(wstr[i]) == -1 && wstr[i] != L' ' && wstr[i] != L'\n')
        {
            wprintf(L"Le char : '%c' n'est pas alphaNum\n", wstr[i]);
            return false;
        }
    }
    return true;
}


//------------------------------
//----------TRAITEMRNT----------
//------------------------------

char *convertirAccents(wchar_t *wstrIn) {
    // 2nd partie de la table de correspondance des accents, la premiére étant dans int isAccent(wchar_t wstrIn).
    char sansAccent[53] = "AAAAAAaaaaaaOOOOOOooooooEEEEeeeeIIIIiiiiUUUUuuuuyNnCc";
    int taille = wcslen(wstrIn), index;                                 //taille de la chaine et index pour la table de correspondace des accents.
    char *messageNonAccent = (char*)calloc(sizeof(char), taille);       // Allocation dynamique de la chaine de charactére en entrée.
    
    for (int i=0;i<taille;i++)              // on parcourt la chaine d'entrée
    {
        index = isAccent(wstrIn[i]);        // on teste si il y a un accent à la position courante
        if (index != -1)
        {                                   // Si oui on le remplace 
            messageNonAccent[i] = sansAccent[index];
        }else                               // Si non on convertis la charactére pour le bon type
        {
            messageNonAccent[i] = wstrIn[i];
        }

    }
    return messageNonAccent;
}

char *convertirEspaces(char* str) {
    for (int i = 0; i < strlen(str); ++i)
        if (str[i] == ' ')
            str[i] = '`'; 

    return str;
}