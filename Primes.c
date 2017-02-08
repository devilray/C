#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    printf("Introduzca número del 1 al 100 --> ");
    scanf("%d",&i);

    if(i % 1 == 0 || i % i == 0)
        printf("Es primo");
    else
        printf("No es primo");

    system("PAUSE");
    return 0;
}
