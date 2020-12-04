#include<stdio.h>
#include<unistd.h> // fork function
#include<stdlib.h> // atoi function
#include<sys/wait.h> // wait function

#define MAXLEN 1000

int isPrimeNumber(int n){
    int i=0;
    int last = n/2;

    if(n <=1) return 0;

    for(i = 2; i<=last; i++){
        if((n%i)==0) return 0;
    }
    return 1;
}

int main(int argc, char** argv){
    int num = atoi(argv[1]);
    int children = atoi(argv[2]);
    int res = 0, start=0, end=0, cnt = 0;
    char buf[MAXLEN];
    int pipefd[2];
    pid_t childpid = getpid();

    pipe(pipefd);

    for(int i=0; i<children; i++){
        childpid = fork();
        if(childpid==0){
            start = ((num/children) * i)+1;
            if((i==children-1)&&(num%children!=0)) end = (num/children) * (i+1)+(num%children);
            else end = (num/children) * (i+1);
            break;
        }
    }
    


    if(childpid){
        while(wait(NULL) != -1){
            read(pipefd[0], buf, MAXLEN);
            res += atoi(buf);
        } 
        printf("[%ld] has found %d prime numbers in (%d ~ %d)\n", (long)getpid(), res, 1, num);
    }
    else{
        for(int i = start; i<=end; i++) cnt += isPrimeNumber(i);
        printf("[%ld] has found %d prime numbers in (%d ~ %d)\n", (long)getpid(), cnt, start, end);
        snprintf(buf, MAXLEN, "%d", cnt);
        write(pipefd[1], buf, MAXLEN);
        exit(1);
    }
    return 0;
}