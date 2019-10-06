#include <stdlib.h>
#include <stdio.h>

void viderBuffer()
{
    int caractere = 0;
    while(caractere != '\n' && caractere != EOF)
        caractere = getchar();
}

void majuscule(char *chaine)
{
    int i = 0, nombreCaracteres = 0;

    nombreCaracteres = strlen(chaine);
    for(i = 0; i < nombreCaracteres; i++)
        chaine[i] = toupper(chaine[i]);
}
