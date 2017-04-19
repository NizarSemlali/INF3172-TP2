# Travail pratique 2

## Description

Ce programme est une simulation d'un shell .
  
Ce travail pratique est réalisé dans le cadre du cours Principes des systèmes d'exploitation ( INF3172 ), Hiver 2017 À L'université du Québec À Montréal .  

## Auteurs

Othmane Bouaddi

Nizar Semlali 
  

## Fonctionnement

### Fonctionnement général 

* Le nom de l'exécutable sera "tsh" pour Turbo-Shell.
  
* Le shell aura la responsabilité de lancer divers logiciels pour réaliser des tâches simples.
  
* Le shell doit offrir cet invite de commande pour indiquer qu'il est prêt à recevoir une nouvelle tâche.

  
  

### Fonctionnement détaillé 
  
Toutes les commandes du shell seront dans le même répertoire, c'est-à-dire ~/inf3172/bin.
Si un programme demandé n'est pas dans ce répertoire, un message d'erreur est affiché.
Toutes ces commandes doivent s'exécuter dans un nouveau processus.
Le stdout du nouveau processus doit être affiché par le shell.
  

Les commandes supportées sont :  
  
  * cd <repertoire destination>
  * cdir
  * exit
  * new <nom de fichier>
  * list <-d>
  * rmall <nom du répertoire>
  * newdir <nom du répertoire>
  * size <nom du répertoire>
  * fin <nbLignes> <fichier>
  

  
## Contenu du projet

* Fichier tp2.c contenant le code source du projet, avec la fonction main
* Fichier tp2.h contenant l'interface des méthodes
* Fichier link.h contenant les constantes et imports de bibliothèques
* Fichier liste.c sert à afficher la liste des fichiers ou répertoires dans le répertoire courant du shell
* Fichier new.c sert à créer un nouveau fichier texte vide.
* Fichier mewdir.c sert à créer un nouveau répertoire vide
* Fichier rmall.c La commande rmall supprime un répertoire et tout son contenu récursivement
* Fichier rmall.h contenant l'interface des méthodes de la classe rmall.c
* Fichier size.c doit calculer le nombre de fichier dans le répertoire et la taille du répertoire
* Fichier size.h contenant l'interface des méthodes de la classe size.c
* Fichier fin.c sert à afficher un certain nombre de lignes d'un fichier à partir de la fin du fichier
* Fichier README.md qui décrit le contenu du projet
* Fichier Makefile supportant les appels make et make clean 


## Références

Pas de références.

## Statut

Toutes les méthodes sont implémentées . 
  WIP pour la persistence du disque . 