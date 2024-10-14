#include<stdio.h>
#include<stdlib.h>

typedef struct Element Element;
struct Element
{
    int data;
    Element *suivant;
    Element *précédent;
};

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

void insertion(Liste *liste, int nombre){
    
}






int main(){
    return 0;
}