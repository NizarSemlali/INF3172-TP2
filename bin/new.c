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

        // On se repositionne dans le dossier ou on était initialement
        chdir(cwd);

    }


    return EXIT_SUCCESS;
}
