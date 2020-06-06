# Message_Encryption

Message_Encryption est un programme en C permettant le chiffrement et déchiffrement de messages.

## Objectif

L'objectif de ce programme est de pouvoir proposer un (dé)chiffrement de messages simples en faisant le choix entre 2 algorithmes.

* Algorithme de César
    * Le chiffrement de César fonctionne par décalage des lettres dans l'alphabet. Cette longueur de décalage correspond à la clé de chiffrement.
    * Pour plus d'informations : https://fr.wikipedia.org/wiki/Chiffrement_par_d%C3%A9calage

* Algorithme de Vigenère
    * La clé de chiffrement se présente sous forme d'un mot ou d'une phrase. Pour pouvoir chiffrer notre texte, à chaque caractère nous utilisons une lettre de la clé pour effectuer la substitution.
    * Pour plus d'informations : https://fr.wikipedia.org/wiki/Chiffre_de_Vigen%C3%A8re

## Utilisation

Pour pouvoir utiliser ce programme, il faudra exécuter ces commandes dans la console au niveau du répertoire où se trouve le programme.

```bash
make all
./main
```

## Documentation des Fonctions
```c 
int verifAlphaNum(wchar_t *message)
```
* Retourne 0 s'il y a des caractères spéciaux et 1 sinon.
* Paramètres :
    * *message* représente le message à (dé)chiffrer.

```c
int verifAlpha(wchar_t *message)
```
* Retourne 0 s'il y a des caractères non alphabetiques et 1 sinon.
* Paramètres :
    * *message* représente le message à (dé)chiffrer.

```c   
void replaceAccents(wchar_t *message)
```
* Remplace les accents du message par son équivalence sans accents.
* Paramètres :
    * *message* représente le message à (dé)chiffrer

```c 
void chiffrageCesar(wchar_t *message, int code)
```
* Chiffre le message selon le code
* Paramètres :
    * *message* représente le message à chiffrer
    * *code* représente la clé de chiffrement 

```c
void dechiffrageCesar(wchar_t *message, int code)
```
* Dechiffre le message selon le code
* Paramètres
    * *message* représente le message à déchiffrer
    * *code* représente la clé de déchiffrement 

```c   
void chiffrageVigenere(wchar_t *message, wchar_t *code)
```
* Chiffre le message selon le code
* Paramètres :
    * *message* représente le message à chiffrer
    * *code* représente la clé de chiffrement 

```c  
void dechiffrageVigenere(wchar_t *message, wchar_t *code)
```
* Dechiffre le message selon le code
* Paramètres :
    * *message* représente le message à déchiffrer
    * *code* représente la clé de déchiffrement 

```c   
void saveFile(wchar_t *message);
```
* Enregistre le message dans un fichier texte
* Paramètres :
    * *message* représente le message à (dé)chiffrer

## Cas d'erreurs

A cause de quelques incompréhensions, quelques erreurs de buffer concernant le dépassement des entrées utilisateurs sont présentes.

## Auteurs

* ROUX Ludovic
* PROSDOCIMI Yoan

https://framagit.org/LudOo/message_encryption
