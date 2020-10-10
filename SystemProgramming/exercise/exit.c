#include<stdio.h>
#include<unistd.h> // fork function
#include<stdlib.h> // exit function

int main(){
    int stat_loc=0;

    fork();
    fork();
    wait(&stat_loc);
    printf("pid : %ld, %d\n", (long)getpid(), WEXITSTATUS(stat_loc));
    exit(1);
    return 0;
}