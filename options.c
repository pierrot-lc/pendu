#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "constantes.h"
#include "dictionnaire.h"

void menuOptions()
{
    int choix = 0;

    while(choix < 1 || choix > 3)
    {
        system(CLEAR);
        printf("Menu options :\n");
        printf("1. Ajouter un mot\n2. Reinitialiser le dictionnaire\n3. Changer la couleur du texte\n4. Menu principal\n\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        viderBuffer();
    }

    switch(choix)
    {
    case 1:
        ajouterMot();
        break;
    case 2:
        reinitialiserDictionnaire();
        break;
    case 3:
        changerCouleur();
        break;
    case 4:
        break;
    default:
        break;
    }
}

int ajouterMot()
{
    char mot[100] = {0};
    char *positionEntree = NULL;

    FILE *fichier = NULL;
    fichier = fopen("data/dictionnaire.pdu", "r+");
    if(fichier == NULL)
        exit(EXIT_FAILURE);

    system(CLEAR);
    afficherDictionnaire();
    printf("\n\nTapez le mot que vous voulez ajouter.\n");
    printf("Votre mot : ");
    fgets(mot, 99, stdin);
    positionEntree = strchr(mot, '\n');
    if(positionEntree != NULL)
        *positionEntree = '\0';
    viderBuffer();

    fseek(fichier, 0, SEEK_END);

    majuscule(mot);
    fprintf(fichier, "\n%s", mot);

    fclose(fichier);
    return 1;
}

int changerCouleur()
{
    int choix = 0, continuer = 1;
    char color[9];

    color[0] = 'c';
    color[1] = 'o';
    color[2] = 'l';
    color[3] = 'o';
    color[4] = 'r';
    color[5] = ' ';
    color[6] = '0';
    color[8] = '\0';

    while(continuer)
    {
        choix = 0;
        while(choix < 1 || choix > 9)
        {
            system(CLEAR);
            printf("Couleur du texte :\n");
            printf("1. Blanc\n2. Bleu\n3. Vert\n4. Rouge\n5. Cyan\n6. Jaune\n7. Marron\n8. Kaki\n9. Menu principal\n");
            printf("Votre choix : ");
            scanf("%d", &choix);
            viderBuffer();
        }
        switch(choix)
        {
        case 1:
            color[7] = '7';
            system(color);
            inscrireCouleur(color);
            break;
        case 2:
            color[7] = '1';
            system(color);
            inscrireCouleur(color);
            break;
        case 3:
            color[7] = '2';
            system(color);
            inscrireCouleur(color);
            break;
        case 4:
            color[7] = 'c';
            system(color);
            inscrireCouleur(color);
            break;
        case 5:
            color[7] = 'b';
            system(color);
            inscrireCouleur(color);
            break;
        case 6:
            color[7] = 'e';
            system(color);
            inscrireCouleur(color);
            break;
        case 7:
            color[7] = '4';
            system(color);
            inscrireCouleur(color);
            break;
        case 8:
            color[7] = '6';
            system(color);
            inscrireCouleur(color);
            break;
        case 9:
            continuer = 0;
            break;
        }
    }
    return 1;
}

int inscrireCouleur(char color[])
{
    FILE* fichier = NULL;
    fichier = fopen("data/color.pdu", "w+");

    if(fichier == NULL)
        return 0;

    fprintf(fichier, "%s", color);

    fclose(fichier);
    return 0;
}

void reinitialiserDictionnaire()
{
    char mots[1000][100] = {0};
    int i = 0;
    FILE* dictionnaire = NULL, *save = NULL;
    dictionnaire = fopen("data/dictionnaire.pdu", "w");
    save = fopen("data/dictiosave.pdu", "r");
    if(dictionnaire == NULL || save == NULL)
        exit(EXIT_FAILURE);

    while(fgets(mots[i], 100, save))
    {
        fprintf(dictionnaire, "%s", mots[i]);
        i++;
    }
}
