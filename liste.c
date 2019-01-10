#include <stdio.h>
#include <stdlib.h>
#include "liste.h"


#define DINMAX 100
// pour les commentaires en c si ca met erreur c est quil faut retirer -ansi (pb de norme).
// LA LISTE VA DE 0 A TETE
//pour les void pas besoin de return
//les accents ca fait bugger

//typedef struct s_arc_p{ /// arc pondere
    //int orig;
    //int dest;
    //int poids;
//} t_arc_p; // cest une fleche


// nombre d'éléments
int nbEltList(liste lst){//ok
    return (lst.nbElt);
}
// renvoie une liste statique donc init une liste vide
void createList(liste *p){//ok
    (p->Tete) =-1;
    (p->nbElt) =0;
}

//pour avoir l'indice du debut qui n'est pas forcement 0
int indicedudebut(liste lst){//ok
    int temp=(lst.Tete +1)-lst.nbElt; // temp cest fin de liste - nbr elmt
    if (temp < 0) { return DINMAX+temp;}//erreur
    else{ return temp;}//indice du debut
}

char* indexTab(liste lst) {
    char* tabInd = (char*) malloc(lst.nbElt * sizeof(char));
    char index = indicedudebut(lst);
    for(int x=0; x<lst.nbElt; ++x) {
        tabInd[x] = index;
        index = (index+1)%DIMMAX;
    }
    return tabInd;
}

// ajoute un élément devant
void addFrontList(liste *p, Elementliste e){//ok
    if ((p->nbElt)==DINMAX){ return;}// void ne return pas une valeur
    (p->Tete)++;
    p->Tabliste[p->Tete]=e; //ajoute element e
    p->nbElt++;//augmente taille liste p
}

// supprime l'élément de fin
void delTailList(liste *p){//moyen ok
    //si on supp [0,1,2]
    //[0,1]
    // on vire Tabliste[tete] et cest tt l'indice tete sera 1 et p.nbelemt decremente
    if ((p->nbElt)==0){ return;}
    p->nbElt=-1;
}

// supprime l'élément de tête
void delFrontList(liste *p){
    //si on supp [0,1,2] a [1,2] :
    //on vire Tabliste[0] et on decale avc un for i=i-1 et p.nbelmt decremente
    if ((p->nbElt)==0){return;}
    (p->Tete)=-1;
    (p->nbElt)=-1;
}

//renvoie dernier element liste
void headList(liste p, Elementliste *e) {
    if ((p.nbElt)==0){return;}
     copie_element(e,p.Tabliste[p.Tete]);
}

//renvoie premier element liste
void tailList(liste p, Elementliste *e) {
    if ((p.nbElt)==0){ return;}
    copie_element(e,p.Tabliste[indicedudebut(p)]);// retourne le vrai debut de la liste
}

// renvoie true si la pile est vide, false sinon
bool emptyList(liste p){
    if ((p.nbElt)==0){return 1;}
    else{return 0;}
}

// renvoie true si la pile est pleine, false sinon
bool fullList(liste p){
    if ((p.nbElt)==DINMAX){
        return true;
    }
    else { return 0;}
}

//affiche contenu liste
void dumpList(liste p, FILE *fp) {
    if((p.nbElt)==0){return;}
    for(int i = indicedudebut(p) ; i < DIMMAX ; i++)//i le vrai indice de debut
        afficher_element(p.Tabliste[i],fp);//fprintf avec FILE
    if((p.Tete)!=-1) {//pr pas afficher jusqua -1 (de tail a tete)
        for(int j=0 ; j<=(p.Tete) ; j++)
            afficher_element(p.Tabliste[j],fp);//affiche tableau de la liste
    }
    fprintf(fp, "\n");//affiche sur fichier log ou stdout
}

//echange a et b
void swapEltList(Elementliste *a, Elementliste *b) {
    Elementliste *temp=NULL;
    *temp = *a;
    *a = *b;
    *b = *temp;
}



//renvoie l'element de e
void pickEltList(liste l, Elementliste *e, int index) {
    copie_element(e,l.Tabliste[index]);//element cest lelement tab[index] comme indice
}

// true si l'element est dans la liste
bool belongEltList(liste p, Elementliste e) {
    for(int i=0; i<p.nbElt; i++) {//parcourt liste
        if(cmp_elements(e,p.Tabliste[i])){//compare deux elements
            return true;
            }
    }
    return false;
}
//pr graphes compare voir si element si il est dans liste
//e remation entre deux candidats

//ajoute un element au debut
void addTailList(liste *p, Elementliste e) {
    if(fullList(*p))
        return;
    if(p->Tete == -1)
        addFrontList(&p, e);
    else {
        p->Tabliste[DIMMAX - (p->nbElt - p->Tete)] = e;
        p->nbElt++;
    }
}









