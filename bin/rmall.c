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
Discription:
La classe rmall supprime un répertoire et tout son contenu récursivement (tous les sousrépertoires)
sans demander de confirmation. Le nom du répertoire peut être un chemin relatif ou
absolu. Si le répertoire est inexistant, un message doit être affiché. Si l'utilisateur ne possède pas les
droits pour supprimer le répertoire, un message doit être affiché mais le contenu doit rester intacte.
****************************************************************************/
#include "rmall.h"

int main ( int argc, char *argv[]) {

     // Chemin du dossier à supprimer 
	char path[BUFFER_SIZE];         

    // On garde l'adresse courante de notre dossier : 
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    // Validation du chemin : Relatif ou absolu 
    if(strncmp(argv[0],"/",1) == 0 ) {

        strcpy(path, argv[0]);

    } else {

        strcpy(path, cwd);
        strcat(path,"/");
        strcat(path,argv[0]);

    }



    DIR* rep = NULL;
    rep = opendir(path); // Ouverture du dossier 

    // Si le chemin absolu ou relatif n'existe pas
    if (rep == NULL) { 

        fprintf(stderr, "Répertoire introuvable !\n"); 

    } else if (errno == EACCES) { // Accès interdit 

        fprintf(stderr, "Permissions insuffisantes !\n"); 

    } else {
        
        // Appel récursif
        vider_repertoire(path);
        printf("Répertoire supprimé! \n");
           
    }

    // On se repositionne dans le dossier ou on était initialement
    chdir(cwd);
    
    return EXIT_SUCCESS;



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

            // Appel récursif, suppression des sous-répertoires
            vider_repertoire(cible);
        	

        } else {

            // Suppression des fichiers du répertoire 
        	remove(cible);

        }
    }
    
    // Suppression du répertoire cible 
    rmdir(path);
                
}