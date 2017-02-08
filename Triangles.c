#include <stdio.h>
#include <stdlib.h>

int main(void){
    int lado, base, opcion;

    printf("Introduzca el lado del triángulo: ");
    scanf("%d",&lado);
    printf("Introduzca la base del triángulo: ");
    scanf("%d",&base);

    printf("Seleccione opción: \n");
    printf("1 - Equilátero\n");
    printf("2 - Isósceles\n");
    printf("3 - Escaleno\n");
    scanf("%d",&opcion);

    switch(opcion){
        case 1:
            printf("El pérímetro es %d\n",3*lado);
            break;
        case 2:
            printf("El pérímetro es %d\n",(2 * lado) + base);
            break;
        case 3:
            printf("El pérímetro es %d\n",lado + lado + lado);
            break;
        default:
            printf("Opción no válida.");
            break;
    }

    system("PAUSE");
    return 0;
}
