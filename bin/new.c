#include "link.h"

int main ( int argc, char *argv[]) {


    char path[BUFFER_SIZE];         // Chemin ou le fichier sera créé
    char fileName[BUFFER_SIZE];     // Nom du fichier texte à créer

    char *last = strrchr(argv[0], '/');
         
    strcpy(fileName,last+1);
    int tailleChemin = strlen(argv[0]) - strlen(fileName) + 1  ; 
    
    strncpy(path, argv[0], tailleChemin );
    // Ajout du '\0' à la fin de la chaine
    if ( strlen( path ) >= tailleChemin ) {
        path[ tailleChemin -1 ] = '\0';
    }

    // On garde l'adresse courante de notre dossier : 
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    if( chdir( path ) != 0 ) {

        fprintf(stderr, "Répertoire introuvable\n");

    } else if (errno == EACCES) { // Accès interdit 

        fprintf(stderr, "Accès interdit !\n"); 

    } else {

        FILE *fichier = NULL;
        fichier = fopen(fileName,"r");
 
        if (fichier != NULL) {

             fprintf(stderr, "Impossible de créer le fichier!\n");

        } else {

            fichier = fopen(fileName, "a");
            printf("Fichier créé!\n");

        }

        chdir(cwd);

    }


    return EXIT_SUCCESS;
}
