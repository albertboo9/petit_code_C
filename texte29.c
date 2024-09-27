#include <stdio.h>
#include <string.h>

int main(){
    char* text[100];
    char table[]={'a', 'e', 'i', 'o', 'u', 'y'}, esp=' ';
    int l=0;


    printf("veuillez entrer votre texte \n");
    scanf("%s", text);

    l = strlen(text);

    printf("%d", l);



}
