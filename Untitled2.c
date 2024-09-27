#include <stdio.h>
#include <string.h>

struct article {
    char* Nom; /*nom de l'article*/
    int Nb; /*Nombre d'article*/
    float prix; /*Prix unitaire de l'article*/
    int Nbmin; /*Nombre d'articles minimum à avoir en stock*/
};

int main(){
   struct article nido;

   nido.Nb=100;
   nido.Nom='ido';

   printf("%c", nido.Nom);
}
