#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t childPid;

    childPid = fork();

    if(childPid==0){
        sleep(3);
        execlp("/bin/ls", "ls", "-al", (char*)0);
    }
    else{
        fprintf(stderr, "I'm waiting for child %d\n", childPid);
        wait(NULL);
        fprintf(stderr, "Child is end\n");
    }
    return 0;
}