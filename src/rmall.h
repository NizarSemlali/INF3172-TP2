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
 * Vide le répertoire courant avant de le supprimer .
 * Effectue le travail récursivement, s'assure donc de supprimer tout les sous répertoires
 * et leur contenu avant de supprimer le répertoire parent .  
 *
 * @param path : Chemin du répertoire à vider . 
 *
*/ 
void vider_repertoire(char* path);