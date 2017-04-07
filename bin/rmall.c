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
#include "rmall.h"

int main ( int argc, char *argv[]) {

	char path[BUFFER_SIZE];          // Chemin du dossier à supprimer 
    //char repertoryName[BUFFER_SIZE];


    // On garde l'adresse courante de notre dossier : 
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    
    if(strchr(argv[0],'/') != NULL ) {

        strcpy(path, argv[0]);

    } else {

        strcpy(path, cwd);
        strcat(path,"/");
        strcat(path,argv[0]);

    }



    DIR* rep = NULL;
    rep = opendir(path); // Ouverture du dossier 

    if (rep == NULL) { 

        fprintf(stderr, "Répertoire introuvable !\n"); 

    } else if (errno == EACCES) { // Accès interdit 

        fprintf(stderr, "Permissions insuffisantes !\n"); 

    } else {
        
        vider_repertoire(path);
        printf("Répertoire supprimé! \n");
           
    }

    chdir(cwd);



}


void vider_repertoire(char* path){

    chdir(path); 

	DIR* rep = NULL;
    rep = opendir(path); // Ouverture du dossier 
    struct dirent* fichierLu = NULL; 


    while ((fichierLu = readdir(rep)) != NULL) {

        char cible[BUFFER_SIZE];
        strcpy(cible,path);
        strcat(cible,"/");
        strcat(cible,fichierLu->d_name);

        if (fichierLu->d_type == 4 && 
            strcmp(fichierLu->d_name,".") != 0 &&
            strcmp(fichierLu->d_name,"..") != 0) {

            vider_repertoire(cible);
        	

        } else {

        	remove(cible);

        }
    }

    rmdir(path);
                
}