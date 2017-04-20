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

/*
 * Fonction qui calcule le nombre de fichiers dans le répertoire récursivement . 
 *
 * @param path : Chemin du répertoire cible. 
 * @return nombre de fichiers du répertoire.
 *
*/ 
int calculNombreFichiers(char* path);

/*
 * Fonction qui calcule la taille totale du répertoire récursivement .
 *
 * @param path : Chemin du répertoire cible. 
 * @return taille totale du répertoire. 
 *
*/ 
int calculTailleTotale(char* path);