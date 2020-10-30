#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    pid_t childPid, endPid;

    int stat_loc=0;

    childPid = fork();
    if(childPid==0){
        // sleep(3);
        printf("I'm child Good Bye~\n");
        exit(255);
    }
    else{
        printf("I'm waiting for child %ld...\n", (long)childPid);
        endPid = waitpid(childPid, &stat_loc, WNOHANG);
        printf("Child %ld give me %d\n", (long)endPid, WIFEXITED(stat_loc));
    }
    return 0;
}