#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

// Liste des fonctions demandés du programme
int verifAlphaNum(wchar_t *message);
int verifAlpha(wchar_t *message);
void replaceAccents(wchar_t *message);
void chiffrageCesar(wchar_t *message, int code);
void dechiffrageCesar(wchar_t *message, int code);
void chiffrageVigenere(wchar_t *message, wchar_t *code);
void dechiffrageVigenere(wchar_t *message, wchar_t *code);
void saveFile(wchar_t *message);

// Liste des autres fonctions utiles
void clearBuffer();

// Fonction de vérification alphanumérique
// Retourne 0 s'il y a un caractère spéciale
// Si tous les caractères sont bons, cela retourne 1
int verifAlphaNum(wchar_t *message){

    wchar_t charactereSpeciaux[40]= 
        {'>','<','#','(','{','[',']','}',')','/','*','-','+','.',
        '@','|','&','~','"','_','`','^','?',';',',',':','!','%',
        '$',L'§',L'µ',L'£',L'¤','*',L'€','=',L'°',L'²','\'','\\'};

    for(unsigned i = 0; i < wcslen(message); i++){
        for(unsigned j = 0; j < 40; j++){
            if(message[i] == charactereSpeciaux[j]){
                return 0;
            }
        }
    }
    return 1;
}

// Fonction de vérification alphabétique
// Retourne 0 s'il y a un caractère non alphabétique
// Si tous les caractères sont bons, cela retourne 1
int verifAlpha(wchar_t *message){
    wchar_t numbers[10] = L"0123456789";

    for(unsigned i = 0; i < wcslen(message); i++){
        for(unsigned j = 0; j < 10; j++){
            if(message[i] == numbers[j]){
                return 0;
            }
        }
    }
    return 1;
}

// Fonction de remplacements des accents
// Demande un tableau wchar_t
void replaceAccents(wchar_t *message){
    wchar_t accents[54] = L"ÀÁÂÃÄÅàáâãäåÒÓÔÕÖØòóôõöøÈÉÊËèéêëÌÍÎÏìíîïÙÚÛÜùúûüÿÑñÇç";
    wchar_t sansAcc[54] = L"AAAAAAaaaaaaOOOOOOooooooEEEEeeeeIIIIiiiiUUUUuuuuyNnCc";

    for(unsigned i = 0; i < wcslen(message); i++){
        for(unsigned j = 0; j < 54; j++){
            if(message[i] == accents[j]){
                message[i] = sansAcc[j];
            }
        }
    }
}

// Chiffrage Cesar
// Demande un tableau wchar_t
// Demande un entier
void chiffrageCesar(wchar_t *message, int code){
    for(unsigned i = 0; i < wcslen(message); i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = 'a' + ((message[i] - 'a') + code) % 26;
        }
        if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = 'A' + ((message[i] - 'A') + code) % 26;
        }
        if(message[i] >= '0' && message[i] <= '9'){
            message[i] = '0' + ((message[i] - '0') + code) % 10;
        }
    }
}

// Déchiffrage Cesar
// Demande un tableau wchar_t
// Demande un entier
void dechiffrageCesar(wchar_t *message, int code){
    for(unsigned i = 0; i < wcslen(message); i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = 'a' + ((message[i] - 'a') + 26 - code) % 26;
        }
        if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = 'A' + ((message[i] - 'A') + 26 - code) % 26;
        }
        if(message[i] >= '0' && message[i] <= '9'){
            message[i] = '0' + ((message[i] - '0') + 10 - code) % 10;
        }
    }
}

// Chiffrage Vigénére
// Demande 2 tableaux wchar_t
void chiffrageVigenere(wchar_t *message, wchar_t *code){
    wchar_t alphaMaj[26] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(unsigned i = 0; i < wcslen(message); i++){
        int codeL;
        int nbEspaces;

        wchar_t letterCode = code[(i - nbEspaces )% wcslen(code)];

        for(unsigned j = 0; j < 26; j++){
            if(letterCode == alphaMaj[j]){
                codeL = j;
            }
        }

        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = 'a' + ((message[i] - 'a') + codeL) % 26;
        }
        if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = 'A' + ((message[i] - 'A') + codeL) % 26;
        }
        if(message[i] >= '0' && message[i] <= '9'){
            message[i] = '0' + ((message[i] - '0') + codeL) % 10;
        }
        if(message[i] == 32){
            nbEspaces++;
        }
    }
}

// Déchiffrage Vigénère
// Demande 2 tableaux wchar_t
void dechiffrageVigenere(wchar_t *message, wchar_t *code){
    wchar_t alphaMaj[26] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(unsigned i = 0; i < wcslen(message); i++){
        int codeL;

        int nbEspaces;

        wchar_t letterCode = code[(i - nbEspaces ) % wcslen(code)];

        for(unsigned j = 0; j < 26; j++){
            if(letterCode == alphaMaj[j]){
                codeL = j;
            }
        }
        if(message[i] >= 'a' && message[i] <= 'z'){
            message[i] = 'a' + ((message[i] - 'a') + 26 - codeL) % 26;
        }
        if(message[i] >= 'A' && message[i] <= 'Z'){
            message[i] = 'A' + ((message[i] - 'A') + 26 - codeL) % 26;
        }
        if(message[i] >= '0' && message[i] <= '9'){
            message[i] = '0' + ((message[i] - '0') + 10 - codeL) % 10;
        }
        if(message[i] == 32){
            nbEspaces++;
        }
    }
}

// Fonction pour sauvegarder le résultat
// Demande le message en tableau wchar_t
void saveFile(wchar_t *message){
    FILE* fichier = NULL;
    fichier = fopen("result.txt", "w");

    if(fichier != NULL){
        fwprintf(fichier, L"%ls", message);
        fclose(fichier);
    }
}

// Fonction pour vider le buffer
void clearBuffer(){
    wchar_t c;
    c = getwchar();
    while(L'\n' != c){
        c = getwchar();
    }
}

// Fonction principale
int main()
{
    // Variable Locale
    struct lconv *loc;
    setlocale(LC_ALL, "");
    loc=localeconv();

    // Tableau de caractères
    wchar_t message[200];

    // Entrée de l'utilisateur
    printf("Veuillez entrer une chaine de caractère valide (200 max): ");
    fgetws(message, 200, stdin);

    int verifAlphanum = verifAlphaNum(message);

    // Si message de l'utilisateur incorrect
    while(verifAlphanum == 0){
        printf("Message incorrect, veuillez recommencer !\n");

        printf("Veuillez entrer une chaine de caractère valide : ");
        fgetws(message, 200, stdin);
        verifAlphanum = verifAlphaNum(message);
    }

    // Choix de l'algorithme de l'utilisateur
    printf("Veuillez choisir l'algorithme voulu :\n");
    printf("- César ( c )\n");
    printf("- Vigenere ( v )\n");
    printf("Votre choix : ");

    wchar_t algo = fgetwc(stdin);

    // Si le choix de l'algorithme est incorrect
    while(algo != 'c' && algo != 'v'){
        printf("Algorithme incorrect, veuillez recommencer !\n");
        printf("Votre choix : ");
        clearBuffer();
        algo = fgetwc(stdin);
    }

    // Choix du mode de l'utilisateur
    printf("Veuillez choisir le mode voulu :\n");
    printf("- Chiffrage ( c )\n");
    printf("- Déchiffrage ( d )\n");
    printf("Votre choix : ");

    clearBuffer();
    wchar_t mode = fgetwc(stdin);

    // Si le choix du mode est incorrect
    while(mode != 'c' && mode != 'd'){
        printf("Mode incorrect, veuillez recommencer !\n");
        printf("Votre choix : ");
        clearBuffer();
        mode = fgetwc(stdin);
    }

    // Définition des codes pour les différents algorithmes
    if(algo == 'c'){

        printf("Veuillez choisir votre code : ");

        wchar_t code[10];
        wchar_t *endString;
        clearBuffer();
        fgetws(code, 10, stdin);

        int value = wcstol(code, &endString, 10);

        while(value == 0){
            printf("Code incorrect, veuillez recommencer !\n");
            printf("Veuillez choisir votre code : ");
            clearBuffer();
            fgetws(code, 10, stdin);
            value = wcstol(code, &endString, 10);
        }

        if(mode == 'c'){
            chiffrageCesar(message, value);
        } else if(mode == 'd'){
            dechiffrageCesar(message, value);
        }

        saveFile(message);
        printf("Votre message codé a été enregistré dans un fichier texte !\n");

    } else if(algo == 'v'){
        printf("Veuillez choisir votre clé (10 lettres max) : ");

        wchar_t code[10];

        clearBuffer();
        fgetws(code, 10, stdin);

        int verifAlphanum2 = verifAlpha(code);

        // Si message de l'utilisateur incorrect
        while(verifAlphanum2 == 0){
            printf("Message incorrect, veuillez recommencer !\n");

            printf("Veuillez entrer une chaine de caractère valide : ");
            fgetws(code, 10, stdin);
            verifAlphanum2 = verifAlpha(code);
        }

        replaceAccents(code);

        // Enleve le \n
        code[wcslen(code) - 1] = '\0';

        for(unsigned i = 0; i < wcslen(code); i++) {
            code[i] = towupper(code[i]);
        }

        if(mode == 'c'){
            chiffrageVigenere(message, code);
        } else if(mode == 'd'){
            dechiffrageVigenere(message, code);
        }

        saveFile(message);
        printf("Votre message codé a été enregistré dans un fichier texte !\n");

    }

    return 0;
}