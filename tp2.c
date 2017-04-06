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

#include "tp2.h"
#define BUFFER_SIZE 128

                        //  --------------------------------  //
                        //                                    //
                        //           Fonction main            //
                        //                                    //
                        //  --------------------------------  //


int main ( int argc, char *argv[]) {

    //int pid;
    char command[BUFFER_SIZE];
    char func[BUFFER_SIZE],arg1[BUFFER_SIZE],arg2[BUFFER_SIZE];

    while (1) {
    // PRINT THE SHELL HEADER

        printf("tsh> ");
        fflush(stdin);
        memset(command,'\0',BUFFER_SIZE);
        memset(func,'\0',BUFFER_SIZE);
        memset(arg1,'\0',BUFFER_SIZE);
        memset(arg2,'\0',BUFFER_SIZE);

        fgets(command, BUFFER_SIZE, stdin);
        //extract first three strings in command (delimited by spaces)      
        sscanf(command ,"%s %s %s",func,arg1,arg2);

        if ( strcmp(func, "exit") == 0 ) {
            break;
        } else if ( strcmp (func, "cdir") == 0 ) {

            char cwd[1024];
            getcwd(cwd, sizeof(cwd));
            printf("Répertoire courant : %s\n", cwd);
 
        } else if ( strcmp (func, "cd") == 0 ){

            if ( strcmp(arg1, "") == 0 ) {

                fprintf(stderr, "La commande cd doit absolument avoir un paramètre!\n");

            } else if( chdir( arg1 ) != 0 ) {

                fprintf(stderr, "Répertoire introuvable\n");

            }

        } else if ( strcmp (func, "list") == 0 ) {

            pid_t pid;
            char *arguments[] = { arg1, arg2, NULL };    
            // FORK
            pid = fork();
                
            if (pid == -1) {
                perror("fork error");
                exit(EXIT_FAILURE);
            }
                
            if (pid == 0) {
                puts("child process");
                if (execvp("./bin/list", arguments) == -1) {
                    perror("execvp error");
                }
                
                puts("parent process");

            } else {
                wait(NULL);
            }


        } else if (strcmp (func, "") != 0 ) {

            printf( "Commande inconnue ! \n" );

        }

    }    

    return EXIT_SUCCESS;

}