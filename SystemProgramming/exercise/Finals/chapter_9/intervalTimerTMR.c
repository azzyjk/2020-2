#include<stdio.h>
#include<signal.h>
#include<time.h>

// - lrt 옵션을 붙여야 컴파일이 된다.

void func(int number){
    printf("I'm SIGUSR1\n");
}

int main(){
    struct sigevent evp;
    struct sigaction act;
    struct itimerspec tp;
    timer_t timer;

    // timer가 어떤 signal 보낼지 선택
    evp.sigev_notify = SIGEV_SIGNAL;
    evp.sigev_signo = SIGUSR1;

    // itimerspec 설정
    tp.it_value.tv_sec=1;
    tp.it_interval = tp.it_value;

    act.sa_handler= func;
    act.sa_flags =0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);

    timer_create(CLOCK_REALTIME, &evp, &timer);

    timer_settime(timer, 0, &tp, NULL);
    
    for(;;);

    return 0;
}