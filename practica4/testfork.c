#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    printf("Cuantas veces");

    int pid = fork();

    if(pid == 0) printf("Soy proceso hijo ");
    else printf("Soy proceso padre ");
    printf("cuantas veces otra vez.");
    
}