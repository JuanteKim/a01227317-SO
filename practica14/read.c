#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


typedef struct s {
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];

} 

Student;

int main(){
    int src;

    Student *myStudent1;
    myStudent1 = (Student *) malloc(sizeof(Student));

    src = open("class.bin", O_RDWR);
    read(src, myStudent1, sizeof(Student));
    printf("My student is: %d, %d, %s, %s", myStudent1 -> id, myStudent1 -> semester, myStudent1 -> firstName, myStudent1 -> lastName);
    sprintf(myStudent1 -> lastName, "%s%d", "Kim", 1);
    for(int i = strlen(myStudent1 -> lastName); i < 20; i++){
        myStudent1 -> lastName[i] = 0;
    }


    lseek(src, -1*sizeof(Student), SEEK_CUR);
    write(src, myStudent1, sizeof(Student));
    close(src);
    free(myStudent1);
    
    return 0;




}