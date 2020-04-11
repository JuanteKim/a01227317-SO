#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void processSignal(int s){
    printf("Recibi segnal %d\n", s);
}

void processMatar(int f){
    printf("no me puedes matar%d\n", f);
}

int main(){
    signal(10, processSignal);
    signal(15, processMatar);

    while(1){
        sleep(3);
        printf("Procesando\n");
    }
    return 1;
}