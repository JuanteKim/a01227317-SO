#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int pid = fork();
    if(pid == 0) printf("Soy proceso hijo ");
    else printf("Soy proceso padre ");
}