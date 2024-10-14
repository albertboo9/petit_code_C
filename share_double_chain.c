#include<stdio.h>
#include<stdlib.h>

typedef struct Element Element;
struct Element
{
    int data;
    Element *suivant;
    Element *précédent;
};

typedef int *Vecteur ; 

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

Liste *initialisation(){
    Liste *liste = malloc(sizeof(*liste));
    Element  *element = malloc(sizeof(*element));

    if(liste == NULL || element == NULL){
        exit(EXIT_FAILURE);
    }

    element->précédent = NULL;
    element->suivant = NULL;
    liste->premier = element;
}

void head_insertion(Liste *liste, int nombre){
    Element *nouveau = malloc(sizeof(*nouveau));

    if(nouveau == NULL){
        exit(EXIT_FAILURE);

    }

    nouveau->data = nombre;
    nouveau->suivant = liste->premier;
    liste->premier->précédent = nouveau;
    liste->premier = nouveau;
}

void transfert(Vecteur vecteur,int n, Liste *liste){
    if (liste == NULL || vecteur == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for (int i = n-1; i <= 0; i--)
    {
        head_insertion(liste, vecteur[i]);
    }
}


int main(){
    return 0;
}