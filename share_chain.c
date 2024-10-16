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

typedef int* Vecteur; 

// initialisation de notre liste chainée  Liste l = initialisation()
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
void transfert1(Liste *liste, int tab[], int n){

    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    for (int i = n-1; i >= 0; i--)
    {
       insertion(liste, tab[i]);
    }
    
}
void afficher(Liste *liste, int n){
    Element *element =malloc(sizeof(*element));

    element = liste->premier;
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", element->data);
        element= element->suivant;
    }
    

}

int main(){
   
    int n= 10;
    int v[n];
    Liste *liste = initialisation();


    for (int i = 0; i < n; i++)
    {
        v[i]= i +1 ;
    }

    transfert1(liste, v, n);
    afficher(liste, n);



    

    return 0;
}