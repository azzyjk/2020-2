#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main(){
    struct sigaction act;

    sigaction(SIGINT, NULL, &act); // SIGINT 시그널에 대한 old handler 가져오기

    act.sa_handler = SIG_IGN;

    sigaction(SIGINT, &act, NULL); // SIGINT 시그널에 대한 IGNORE처리
    return 0;
}