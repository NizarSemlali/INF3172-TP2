/****************************************************************************
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
*   Copyright [2016] [Nizar Semlali]
*   Copyright [2016] [Othmane Bouaddi]
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
****************************************************************************/

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

        // Affichage des sous-répertoires avec l'option -d
        
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

        // Affichage des fichiers

        } else if ( strcmp(argv[0], "") == 0 ) {

            printf("Fichiers de %s \n", cwd);

            while ((fichierLu = readdir(rep)) != NULL) {

                if (fichierLu->d_type != 4 ) {

                    printf("%s\n", fichierLu->d_name);

                }
            }

        // Argument passé invalide 
        } else {

            fprintf(stderr, "Argmuent invalide !\n");
            
        }

        if (closedir(rep) == -1) // S'il y a eu une erreur avec la fermeture 
               
            fprintf(stderr, "Erreur de fermeture du répertoire !\n");

    }

    return EXIT_SUCCESS;
}