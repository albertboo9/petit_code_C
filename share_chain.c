#include<stdio.h>
#include<stdlib.h>

// des éléments contenus dans la liste  simplement chainée
typedef struct Element Element ;
struct Element{
    int data;
    Element *suivant;
};


// structure qui contiendra le premier élément de la liste simplement chainée
typedef struct Liste Liste ;
struct Liste{
    Element *premier;
};


typedef int *Vecteur; 

// initialisation de notre liste chainée
Liste *initialisation(){
    Liste *liste = malloc(sizeof(*liste));
    Element *element  = malloc(sizeof( *element));

    if (liste == NULL || element == NULL){
        exit(EXIT_FAILURE);
    }

    element->data = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;

}

// Insertion d'un nouvel élément dans une liste chainée
void insertion(Liste *liste, int nombre){
    Element *nouveau = malloc(sizeof(*nouveau));

    if(nouveau == NULL || liste == NULL){
        exit(EXIT_FAILURE);
    }

    nouveau->data = nombre;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

// transfert des éléments d'un vecteur vers une liste simplement chainée
void *transfert1(Liste *liste, Vecteur vecteur, int n){

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < n; i++)
    {
       insertion(liste, vecteur[i]);
    }
    
}

int main(){
    return 0;
}