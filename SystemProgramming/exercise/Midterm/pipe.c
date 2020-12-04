#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

#define MAXLEN 1000

int main(){
    int pipefd[2];
    char buf[MAXLEN];
    char* str;
    pid_t childPid;
    int randNum, res=0;

    pipe(pipefd);

    for(int i=0; i<2; i++){
        childPid = fork();
        if(childPid==0) break;
    }

    if(childPid){
        while(wait(NULL)!=-1){
            read(pipefd[0], buf, MAXLEN);
            printf("child end\n");
            res += atoi(buf);
        }
        printf("result : %d\n", res);
    }
    else{
        sleep(2);
        randNum = rand()%10;
        snprintf(buf, MAXLEN, "%d", randNum);
        write(pipefd[1], buf, MAXLEN);
        printf("[%ld] I mad number : %d\n", (long)getpid, randNum);
        exit(0);
    }
    
    
    return 0;
}