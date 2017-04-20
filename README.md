# Travail pratique 2

## Description

Ce programme est une simulation d'un shell .
  
Ce travail pratique est réalisé dans le cadre du cours Principes des systèmes d'exploitation ( INF3172 ), Hiver 2017 À L'université du Québec À Montréal .  

## Auteurs

Othmane Bouaddi

Nizar Semlali 
  

## Fonctionnement

### Fonctionnement général 

* Le nom de l'exécutable est "tsh" pour Turbo-Shell.
  
* Le shell a la responsabilité de lancer divers logiciels pour réaliser des tâches simples.
  
* Le shell offre une invite de commande pour indiquer qu'il est prêt à recevoir une nouvelle tâche.

  
  

### Fonctionnement détaillé 
  
Toutes les commandes du shell seront dans le même répertoire, c'est-à-dire ~/inf3172/bin.
Si un programme demandé n'est pas dans ce répertoire, un message d'erreur est affiché.
Toutes ces commandes s'exécutent dans un nouveau processus.
Le stdout du nouveau processus est affiché par le shell.
  

Les commandes supportées sont :  
  
  * cd <repertoire destination>
  * cdir
  * exit
  * new <nom de fichier>
  * list <-d>
  * rmall <nom du répertoire>
  * newdir <nom du répertoire>
  * size <nom du répertoire>
  * fin <nbLignes> <fichier>
  

  
## Contenu du projet

* Fichier tp2.c :     Code source du projet, avec la fonction main.
* Fichier tp2.h :     Interface des méthodes de la classe tp2.h
* Fichier link.h :    Constantes et imports de bibliothèques.
* Fichier list.c :    Affichee la liste des fichiers ou répertoires dans le répertoire courant du shell
* Fichier new.c :     Crée un nouveau fichier texte vide.
* Fichier mewdir.c :  Crée un nouveau répertoire vide.
* Fichier rmall.c :   Supprime un répertoire et tout son contenu récursivement.
* Fichier rmall.h :   Interface des méthodes de la classe rmall.c
* Fichier size.c :    Calcule le nombre de fichier dans le répertoire et la taille de ce dernier.
* Fichier size.h :    Interface des méthodes de la classe size.c
* Fichier fin.c :     Affiche un certain nombre de lignes d'un fichier à partir de la fin du fichier.
* Fichier README.md : Décrit le contenu du projet.
* Fichier Makefile :  Supporte les appels make et make clean.


## Références

Pas de références.

## Statut

Toutes les méthodes sont implémentées . 
Tout les exécutables sont dans le dossier ~/inf3172/bin, incluant le tsh .  