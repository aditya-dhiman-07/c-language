#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// incomplete

int main() {
    int a = 1;
    char name[100];      // buffer for input
    char *ptr = NULL;    // dynamic pointer

    ptr = (char*) malloc(1 * sizeof(char));

    do {
        fgets(name, sizeof(name), stdin);

        if(name[strlen(name)-1] == '\n')
            name[strlen(name)-1] = '\0';

        ptr = (char*) realloc(ptr, a * sizeof(char));
        if(ptr == NULL) {
            exit(0);
        }
        a++;

    } while(name[strlen(name) - 1] != '\0');

    printf("%s",name);
    return 0;
}
