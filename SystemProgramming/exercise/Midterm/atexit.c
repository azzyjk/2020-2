#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void printHello(){
    printf("Hello\n");
}

void printHi(){
    printf("Hi\n");
}

int main(){
    fork();
    atexit(printHello); // atexit은 exit이 실행되었을 때 정의 해놓은 function이 stack 즉, FILO 형태로 동작하게 된다.
    exit(1);
    atexit(printHi);
    return 0;
}