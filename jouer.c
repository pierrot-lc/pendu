#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "constantes.h"
#include "jouer.h"
#include "dictionnaire.h"

void menuJouer()
{
    int choix = 0;

    while(choix < 1 || choix > 3)
    {
        system(CLEAR);
        printf("Choississez votre mode de jeu :\n");
        printf("1. Jouer solo\n2. Jouer duo\n3. Menu principal\n\n");

        printf("Votre choix : ");
        scanf("%d", &choix);
        viderBuffer();
    }

    switch(choix)
    {
    case 1:
        jouer(1);
        break;
    case 2:
        jouer(0);
        break;
    case 3:
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }
}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    viderBuffer();

    return caractere;
}


void jouer(int solo)
{
    char mot[100] = {0};
    char *motSecret = NULL, *motCache = NULL;
    char caractere = 0;
    char *positionEntree = NULL;
    int partie = 1, nombreCaracteres = 0, i = 0, vies = 10, caractereTrouve = 0;

    if(solo)
    {
        nombreCaracteres = dictionnaire(mot);//Initilisation
    }
    else if(!solo)
    {
        system(CLEAR);
        printf("Tapez le mot mystere : ");
        fgets(mot, 100, stdin);
        majuscule(mot);
        if((positionEntree = strchr(mot, '\n')) != NULL)
            *positionEntree = '\0';
        nombreCaracteres = strlen(mot);
    }

    motSecret = malloc((nombreCaracteres + 1) * sizeof(char));//Plus 1 pour le '\0'
    motCache = malloc((nombreCaracteres + 1) * sizeof(char));
    if(motCache == NULL || motSecret == NULL)
        exit(EXIT_FAILURE);

    strcpy(motSecret, mot);
    for(i = 0; i < nombreCaracteres; i++)
    {
        motCache[i] = '_';
        if(motSecret[i] == ' ' || motSecret[i] == '-')
            motCache[i] = motSecret[i];
    }

    motCache[nombreCaracteres] = '\0';

    while(partie)
    {
        system(CLEAR);
        caractereTrouve = 0;

        printf("Trouvez le mot mystere !\n");
        printf("Nombre de vies restants : %d\n", vies);

        dessinerPendu(vies);

        for(i = 0; i < nombreCaracteres; i++)
        {
            printf("%c ", motCache[i]);
        }

        printf("\nVotre proposition : ");
        caractere = lireCaractere();

        for(i = 0; i < nombreCaracteres; i++)
        {
            if(caractere == motSecret[i])
            {
                motCache[i] = motSecret[i];
                caractereTrouve = 1;
            }
        }
        if(!caractereTrouve)
            vies--;
        if(strchr(motCache, '_') == NULL || vies == 0)
            partie = 0;
    }

    system(CLEAR);
    if(vies == 0)
    {
        dessinerPendu(vies);
        printf("Perdu ! Le mot mystere etait '%s' !\n\n", motSecret);
    }
    else if(strchr(motCache, '-') == NULL)
    {
        dessinerPendu(vies);
        printf("Bravo ! Le mot mystere etait bien '%s' ! Il vous restait %d de vies !\n\n", motSecret, vies);
    }

    printf("Appuyez sur entree pour continuer ...");
    getchar();

    free(motCache);
    free(motSecret);
}

void dessinerPendu(int vie)
{
    switch(vie)
    {
    case 10:
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        break;
    case 9:
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("_____________\n\n");
        break;
    case 8:
        printf("\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("_|____________\n\n");
        break;
    case 7:
        printf("_____________\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("_|____________\n\n");
        break;
    case 6:
        printf("_____________\n");
        printf(" | /\n");
        printf(" |/\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("_|____________\n\n");
        break;
    case 5:
        printf("_____________\n");
        printf(" | /       |\n");
        printf(" |/\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("_|____________\n\n");
        break;
    case 4:
        printf("_____________\n");
        printf(" | /       |\n");
        printf(" |/        O\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf("_|____________\n\n");
        break;
    case 3:
        printf("_____________\n");
        printf(" | /       |\n");
        printf(" |/        O\n");
        printf(" |         |\n");
        printf(" |\n");
        printf(" |\n");
        printf("_|____________\n\n");
        break;
    case 2:
        printf("_____________\n");
        printf(" | /       |\n");
        printf(" |/        O\n");
        printf(" |        -|-\n");
        printf(" |\n");
        printf(" |\n");
        printf("_|____________\n\n");
        break;
    case 1:
        printf("_____________\n");
        printf(" | /       |\n");
        printf(" |/        O\n");
        printf(" |        -|-\n");
        printf(" |         /\\\n");
        printf(" |\n");
        printf("_|____________\n\n");
        break;
    case 0:
        printf("_____________\n");
        printf(" | /       |\n");
        printf(" |/        O\n");
        printf(" |        -|-\n");
        printf(" |         /\\\n");
        printf(" |\n");
        printf("_|____________\n\n");
        break;
    }
}
