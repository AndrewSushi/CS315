#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *file = fopen(argv[1], "r");
    char buffer[32];
    fgets(buffer, 32, file);
    printf("%s", buffer);
    fclose(file);
    // printf("%s\n", argv[1]);
    return 0;
}