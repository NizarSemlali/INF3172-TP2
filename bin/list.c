#include "link.h"

int main ( int argc, char *argv[]) {

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    DIR* rep = NULL;
    rep = opendir(cwd); // Ouverture du dossier 
    struct dirent* fichierLu = NULL; 

    if (rep == NULL) { 

        fprintf(stderr, "Répertoire introuvable !\n"); 

    } else if (errno == EACCES) { // Accès interdit 

        fprintf(stderr, "Accès interdit !\n"); 

    } else {

        if ( strcmp(argv[0], "-d") == 0 ) {

            printf("Sous-répertoires de %s \n", cwd);
                    
            while ((fichierLu = readdir(rep)) != NULL) {
                        
                if ( strcmp(fichierLu->d_name,".") != 0 &&
                     strcmp(fichierLu->d_name,"..") != 0) {

                        if (fichierLu->d_type == 4 ) {

                            printf("%s\n", fichierLu->d_name);

                        }
                    }
                }


        } else if ( strcmp(argv[0], "") == 0 ) {

            printf("Fichiers de %s \n", cwd);

            while ((fichierLu = readdir(rep)) != NULL) {

                if (fichierLu->d_type != 4 ) {

                    printf("%s\n", fichierLu->d_name);

                }
            }

        } else {

            fprintf(stderr, "Argmuent invalide !\n");
            
        }

        if (closedir(rep) == -1) // S'il y a eu une erreur avec la fermeture 
                    
            fprintf(stderr, "Erreur de fermeture du répertoire !\n");

    }

    return EXIT_SUCCESS;
}