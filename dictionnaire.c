#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void refaire(char *mots, int nombreMots);

int dictionnaire(char *motSecret)
{
    int nombreMots = 0, nombreCaracteres = 0, compteur;
    char mots[1000][100] = {0};
    char *caractere = NULL;

    FILE *fichier = NULL;
    fichier = fopen("data/dictionnaire.pdu", "r");
    if(fichier == NULL)
        exit(EXIT_FAILURE);

    while(fgets(mots[nombreMots], 100, fichier)!= NULL)
        nombreMots++;

    compteur = (rand() % (nombreMots) );//Tirage du numéro du nombre
    caractere = strchr(mots[compteur], '\n');//On cherche '\n' et on le remplace par '\0'
    if(caractere != NULL)
       *caractere = '\0';

    strcpy(motSecret, mots[compteur]);//Copie le mot final dans le motSecret
    nombreCaracteres = strlen(motSecret);


    fclose(fichier);
    return nombreCaracteres;
}

void afficherDictionnaire()
{
    char chaine[100] = {0};
    FILE *fichier = NULL;
    fichier = fopen("data/dictionnaire.pdu", "r");
    if(fichier == NULL)
        exit(EXIT_FAILURE);

    while((fgets(chaine, 100, fichier)) != NULL)
          printf("%s", chaine);

    fclose(fichier);
}
