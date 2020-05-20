#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>

int main(int argn, char **argv){
    char espacio = 0;
    char *searchWord = argv[1];
    char *replaceWord = argv[2];
    char *fileName = argv[3];
    char word[100];
    int i = 0;
    char character;
    int fd = open(fileName, O_RDONLY);
    if(fd < 0) {
        printf("No se puede abrir \n");
        exit(1);
    }
    while(read(fd, &character, 1)){
        if((character == ' ' || character == '\n' || character == EOF) && espacio == 0){
            espacio = 1;
            word[i] = '\0';
            i = 0;
            if(strcmp(word, searchWord) == 0){
                printf("%s \n" , replaceWord);
            }else{
                printf("%s \n", word);
            }
            
        }else if(character != ' ' && character != '\n' && character != EOF){
            espacio = 0;
            word[i++] = character;
        }
    }
    word[i] = '\0';
    printf("%s \n", word);
    close(fd);
    exit(0);
}