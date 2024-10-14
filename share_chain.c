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
    Liste *premier;
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


int main(){
    return 0;
}