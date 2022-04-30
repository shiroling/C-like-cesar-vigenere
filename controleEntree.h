#include <stdio.h>      // I/O
#include <stdlib.h>     // exit failue

#include <string.h>     // fonction sur les cahines de charactéres
#include <stdbool.h>    // Type de donnée Boolean non natif en C
#include <ctype.h>

// support du type de donné wchar_t permettant la gestion des accents
#include <wchar.h>
#include <wctype.h>

char *getInputMessage();

//------------------------------
//---------VERIFICATION---------
//------------------------------
/*  Fonction testant si un charactére large donné est accentué (fait partie de la table prédéfinie 'accent')
    si il fait parti de la table, la fonction renvoie son indice dans la table
    Sinon -1 (0 étant pris par l'indice de la premiére case de la table 'accents')                          */
int isAccent(wchar_t wcIn);

/*  Fonction testant si une chaine charactére large donné est alphanumérique (comprenant le accents)
    si Si oui retourne vrai 
    Sinon provoque une sorte de programe comme demandé dans le sujet                                        */
bool verifierAlphanumérique(char *str);


//------------------------------
//----------TRAITEMENT----------
//------------------------------

/*  Cette fonction de traitement permet de convertir la chaine de charactéres large en chaine de charactères multibyte
    pour cela nous convertissons les accents à partir d'une table de correspondance
    puis nous copions les charactéres classiques dans la nouvelle cahines                                   */
char *convertirAccents(wchar_t *wcstr);

/*  Fonction remplacant les espaces dans une chaine de charactére simple en un charactére définit
    Afin qu'il puisse étre encodé par les fonctions de chiffrement.
    Le charactére choisit est ` car il est adjacent au 'a' dans la table ascii et qu'il permet une bonne
    lecture du message une fois qu'il remplace les espaces                                                  */
char *convertirEspaces(char *mbstr);


