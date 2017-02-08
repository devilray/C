#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char s1 = "hola";
    char s2 = "mundo";
    char *s = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(s, s1);
    strcat(s, s2);

    free(s);

    return 0;
}
