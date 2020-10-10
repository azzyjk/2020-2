#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    fork();
    int stat_loc;
    wait(&stat_loc);
    printf("parent pid : %ld, my pid : %ld, uid : %ld, euid : %ld, gid : %ld, egid : %ld\n", (long)getppid(), (long)getpid(), (long)getuid(), (long)geteuid(), (long)getgid(), (long)getegid());
    return 0;
}