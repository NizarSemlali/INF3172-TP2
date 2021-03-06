/****************************************************************************
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
*   Copyright [2017] [Nizar Semlali]
*   Copyright [2017] [Othmane Bouaddi]
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
Description:
La classe newdir sert à créer un nouveau répertoire vide. Le paramètre est un chemin relatif ou
absolu vers le répertoire à créer. Une erreur de création doit afficher un message à l'écran
****************************************************************************/

#include "link.h"

int main ( int argc, char *argv[]) {

    // On garde l'adresse courante de notre dossier : 
    char path[BUFFER_SIZE];
    char fileName[BUFFER_SIZE];
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    // Validation du chemin : Relatif ou absolu 
    if(strncmp(argv[0],"/",1) != 0 ) {
        
        strcpy(path, cwd);
        strcpy(fileName,argv[0]);

    } else {

        char *last = strrchr(argv[0], '/');
         
        strcpy(fileName,last+1);

        int tailleChemin = strlen(argv[0]) - strlen(fileName) + 1  ; 
        strncpy(path, argv[0], tailleChemin );
        
        if ( strlen( path ) >= tailleChemin ) {
            path[ tailleChemin -1 ] = '\0';
        }

    }

    // Si le chemin absolu ou relatif n'existe pas
    if( chdir( path ) != 0 ) {

        fprintf(stderr, "Répertoire introuvable\n");

    } else if (errno == EACCES) { // Accès interdit 

        fprintf(stderr, "Accès interdit !\n"); 

    } else {

        // Création du nouveau répertoire
        DIR* rep2 = NULL;
        char pathcomplet[BUFFER_SIZE];

        strcpy(pathcomplet,path);
        strcat(pathcomplet,"/");
        strcat(pathcomplet,fileName);

        rep2 = opendir(pathcomplet);
       
 
        if (rep2 != NULL) {

             fprintf(stderr, "Impossible de créer le répertoire!\n");

        }else {

            mode_t process_mask = umask(0);
            int result_code = mkdir(pathcomplet, S_IRWXU | S_IRWXG | S_IRWXO);
            umask(process_mask);
            if(result_code == 0){
                printf("repertoire créé!\n");

            }else{
                printf("repertoire non créé!\n");
            }

            if (closedir(rep2) == -1) // S'il y a eu une erreur avec la fermeture 
               
            fprintf(stderr, "Erreur de fermeture du répertoire !\n");

        } 
        
    }

    // On se repositionne dans le dossier ou on était initialement
    chdir(cwd);

    return EXIT_SUCCESS;
}
