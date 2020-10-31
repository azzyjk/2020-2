#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

#define MAXLEN 1000

int main(){
    int pipefd[2];
    char buf[1000];
    char* str;
    pid_t childPid;

    pipe(pipefd);

    childPid = fork();

    if(childPid){
        while(wait(NULL)!=-1){
            read(pipefd[0], buf, MAXLEN);
        }
    }
    else{
        sleep(10);
        str = "Hello";
        write(pipefd[1], str, strlen(str));
        exit(0);
    }
    
    printf("%s\n", buf);
    return 0;
}