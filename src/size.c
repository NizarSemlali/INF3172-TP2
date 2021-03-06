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
La classe size doit calculer le nombre de fichier dans le répertoire et la taille du répertoire ,
c'est-à-dire la somme de la taille de tous les fichiers qu'il contient, peu importe la profondeur. Le
paramètre est un chemin relatif ou absolu vers le répertoire où calculer la taille. Un message doit
être affiché si le répertoire est inexistant.
****************************************************************************/
#include "size.h"

int main ( int argc, char *argv[]) {

	char path[BUFFER_SIZE];          // Chemin du dossier à supprimer 

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
        
        int tailleTotale = 0 ;
        int nombreFichiers = 0 ; 

        nombreFichiers = calculNombreFichiers(path);
        tailleTotale = calculTailleTotale(path);
        
        
        printf("Le répertoire %s contient %d fichiers pour un total de %d octets.\n",
                path, nombreFichiers,tailleTotale );
           
    }

    chdir(cwd);

	return EXIT_SUCCESS;

}


int calculTailleTotale(char* path){

    int taille = 0 ;
    chdir(path); 

    DIR* rep = NULL;
    rep = opendir(path); // Ouverture du dossier 
    struct dirent* fichierLu = NULL; 
    struct stat file_stats;

    while ((fichierLu = readdir(rep)) != NULL) {

        char cible[BUFFER_SIZE];
        strcpy(cible,path);
        strcat(cible,"/");
        strcat(cible,fichierLu->d_name);

        if ((strcmp(fichierLu->d_name,".") != 0) &&
            (strcmp(fichierLu->d_name,"..") != 0)) {

            // Répertoire
            if (fichierLu->d_type == 4) {

                // Appel récursif, calcul de la taille des sous répertoires
                taille += calculTailleTotale(cible);

            // Fichier
            } else {

                if (!stat(fichierLu->d_name, &file_stats))
                {
                    taille += (unsigned int)file_stats.st_size;
                }

            }
        }
    }
    
    return taille;
}







int calculNombreFichiers(char* path){

    int totalFichiers = 0 ;
    chdir(path); 

    DIR* rep = NULL;
    rep = opendir(path); // Ouverture du dossier 
    struct dirent* fichierLu = NULL; 

    while ((fichierLu = readdir(rep)) != NULL) {

        char cible[BUFFER_SIZE];
        strcpy(cible,path);
        strcat(cible,"/");
        strcat(cible,fichierLu->d_name);

        if ((strcmp(fichierLu->d_name,".") != 0) &&
            (strcmp(fichierLu->d_name,"..") != 0)) {

            // Répertoire
            if (fichierLu->d_type == 4) {
                
                // Appel récursif, calcul du nombre de fichiers dans le sous répertoire
                totalFichiers += calculNombreFichiers(cible);

            // Fichier
            } else {

                totalFichiers += 1 ; 

            }
        }
    }
    
    return totalFichiers;
}