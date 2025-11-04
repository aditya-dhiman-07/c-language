#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    
    int a = 1;
    char name[] = "";
    char * ptr = &name;
    ptr = (char*) malloc(1 * sizeof(char)); // Initially allocate for a char

    do{
        fgets(name,sizeof(name),stdin);
        name[strlen(name) - 1 ] = '\0';
        ptr = (char*) realloc(ptr, a * sizeof(char)); // Reallocate to store a char
        if (ptr == NULL) {
        exit(0);
        
    }
    a++;

    }
    while(name[strlen(name) - 1 ] != '\n');

return 0;
}