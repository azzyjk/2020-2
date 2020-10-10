#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    fork();
    pid_t parentPid = getppid();
    pid_t mypid = getpid();
    int stat_loc;
    wait(&stat_loc);
    printf("parent pid : %ld, my pid : %ld\n", (long)parentPid, (long)mypid);
    return 0;
}