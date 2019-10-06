#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "main.h"
#include "jouer.h"
#include "options.h"

int main(int argc, char** argv)
{
    int continuer = 1;
    lancement();
    while(continuer)
    {
        continuer = menuPrincipal();
    }

    system(CLEAR);
    printf("Bye bye !");

    return 0;
}

int menuPrincipal()
{
    int choix = 0;

    while(choix < 1 || choix > 3)
    {
        system(CLEAR);
        printf("========== Pendu ===========\n\n");
        printf("Menu principal :\n");
        printf("1. Jouer\n2. Options\n3. Quitter\n\n");

        printf("Votre choix : ");
        scanf("%d", &choix);
        viderBuffer();

        if(choix < 1 || choix > 3)
        {
            system(CLEAR);
            printf("Erreur, selectionnez un chiffre entre 1 et 3 pour selectionnez une entree valide.\n");
            printf("Appuyez sur entree pour continuer ...");
            getchar();
        }
    }

    switch(choix)
    {
    case 1:
        menuJouer();
        break;
    case 2:
        menuOptions();
        break;
    case 3:
        return 0;
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }

    return 1;;
}

void lancement()
{
    char color[9];
    FILE* fichier = NULL;
    fichier = fopen("data/color.pdu", "r");
    if(fichier == NULL)
        exit(EXIT_FAILURE);

    fgets(color, 9, fichier);
    system(color);

    srand(time(NULL));

    fclose(fichier);
}
