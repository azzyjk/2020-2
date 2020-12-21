#include<stdio.h>
#include<sys/time.h>
#include<signal.h>

struct itimerval value, ovalue;

void func(int number){
    printf("Alarm!!\n");
    // value.it_value.tv_sec=0;
    // setitimer(ITIMER_REAL, &value, NULL);
}

int main(){
    struct sigaction act;

    act.sa_handler=func;
    act.sa_flags =0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGALRM, &act, NULL);

    value.it_value.tv_sec = 1; // value가 0일 경우 timer가 작동하고 있다면 종료한다.
    
    value.it_interval.tv_sec = 1; // interval 값이 0일 경우 반복하지 않는다.
                                  // 0이 아닐 경우 interval 시간이 지나면 반복한다.
                                  

    // getitimer(ITIMER_REAL, &value);
    setitimer(ITIMER_REAL, &value, NULL); // 3번쨰 인자에 이전 timver의 값이 들어간다.

    for(;;);

    return 0;
}