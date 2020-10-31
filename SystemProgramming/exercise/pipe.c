#include<unistd.h>
#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

int main(){
    int pipefd[2];
    char buf[1000];
    char* str;
    
    str = "Hello";

    pipe(pipefd);
    write(pipefd[1], str, strlen(str));
    read(pipefd[0], buf, MAXLEN);
    
    printf("%s\n", buf);
    return 0;
}