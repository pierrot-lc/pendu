#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#ifndef WIN32
    #define CLEAR "clear"
    //system("clear") pour UNIX
#else
    #define CLEAR "cls"
    //system("cls") pour Windows
#endif // WIN32

void viderBuffer();
void majuscule(char *chaine);

#endif // CONSTANTES_H_INCLUDED
