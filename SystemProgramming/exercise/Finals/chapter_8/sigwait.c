#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main(){
    pid_t myPid= getpid();
    sigset_t sigset;
    int signum, signalCount = 0;

    sigemptyset(&sigset);
    sigaddset(&sigset, SIGUSR1);

    sigprocmask(SIG_BLOCK, &sigset, NULL);
    for(;;){
        sigwait(&sigset, &signum); // pending list 에서 삭제하고 반환함
                                   // 삭제하기 때문에 process로 신호가 전달되지는 않는다.
                                   // 2번째 파라미터는 받은 signal의 숫자를 저장
        signalCount++;
        printf("Signal Count : %d\n", signalCount);
    }
    return 0;
}