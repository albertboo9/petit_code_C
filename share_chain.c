#include<stdio.h>

// des éléments contenus dans la liste  simplement chainée
typedef struct Element{
    int data;
    Element *suivant;
} Element ;


// structure qui contiendra le premier élément de la liste simplement chainée
typedef struct Liste{
    Liste *premier;
} Liste ;


typedef int *Vecteur; 



int main(){
    return 0;
}