#include<stdio.h>
#include<signal.h>
#include<unistd.h> // getpid()

void func(int number){
    // printf("%d\n", number);
    printf("11!!\n");
}

int main(){
    struct sigaction newact;
    pid_t myPid = getpid();

    newact.sa_handler = func; // SIG_DFL : default 값으로 사용, SIG_IGN : signal 무시, void(*sa_handler)(int) : 사용자 정의 함수 사용
    newact.sa_flags=0; // 0 : sa_handler 사용, SA_SIGINFO : realtime handler인 sa_sigaction 사용
    sigemptyset(&newact.sa_mask); // signal handler가 실행되는 동안 block되는거 초기화

    sigaction(SIGINT, &newact, NULL);

    printf("My PID : %d\n", myPid);
    for(;;);
    return 0;
}