#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int argn, char **argv){
    unsigned int countChar = 0;
    unsigned int countLine = 0;
    unsigned int numWords = 0;
    char espacio = 0;
    char *fileName = argv[1];
    char buffer;
    int fd = open(fileName, O_RDONLY);
    if(fd < 0) {
        printf("No se puede abrir \n");
        exit(1);
    }
    while(read(fd, &buffer, 1)){
        countChar += 1;
        if(buffer == '\n'){
            countLine += 1;
        }
        if((buffer == ' ' || buffer == '\n' || buffer == EOF) && espacio == 0){
            espacio = 1;
            numWords += 1;
        }else if(buffer != ' ' && buffer != '\n'){
            espacio = 0;
        }
    }

    printf("%d %d %d %s" "\n", countLine, countChar, numWords, fileName);
    close(fd);
    exit(0);
}