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

  char path[BUFFER_SIZE];          

	char fileName[BUFFER_SIZE];
    // On garde l'adresse courante de notre dossier : 
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    
     if(strncmp(argv[1],"/",1) != 0 ) {
        
        strcpy(path, cwd);
        strcpy(fileName,argv[1]);

    } else {

        char *last = strrchr(argv[1], '/');
         
        strcpy(fileName,last+1);

        int tailleChemin = strlen(argv[1]) - strlen(fileName) + 1  ; 
        strncpy(path, argv[1], tailleChemin );
        
        if ( strlen( path ) >= tailleChemin ) {
            path[ tailleChemin -1 ] = '\0';
        }

    }
    
    int target = atoi(argv[0]);
    
    if( chdir( path ) != 0 ) {

        fprintf(stderr, "Répertoire introuvable\n");

    } else if (errno == EACCES) { // Accès interdit 

        fprintf(stderr, "Accès interdit !\n"); 

    } else {

        FILE *fichier = NULL;
        fichier = fopen(fileName,"r");
 
        if (fichier == NULL) {

             fprintf(stderr, "Fichier introuvable\n");

        } else {

        	char c;
        	
        	int nLignes1 = 0;
        	int nLignes2 = 0;
        	bool flag = false;

			while((c=fgetc(fichier)) != EOF) {
				flag =true;
				if(c=='\n'){

					nLignes1++;

				}
			}

			if (flag) {
				nLignes1++ ; 
			}
			rewind(fichier);

			if( nLignes1 <= target){

				while( (c = fgetc(fichier)) != EOF){

					printf("%c", c );

				}
				printf("\n");

			} else {

				while((c=fgetc(fichier)) != EOF ){

					if(c =='\n') {
						
						nLignes2++;

					}

					if( nLignes2 == (nLignes1-target) ){
						
						while( (c = fgetc(fichier)) != EOF){

							printf("%c", c );

						}
					    printf("\n");
						break ; 

					}
				}
		    }	
        }
    }


        // On se repositionne dans le dossier ou on était initialement

        chdir(cwd);

}


