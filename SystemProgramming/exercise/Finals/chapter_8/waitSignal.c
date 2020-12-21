#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void func(int number){
    printf("I'm SIGCONT\n");
}

int main(){
    pid_t myPid = getpid();
    struct sigaction act;

    act.sa_flags = 0;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    sigaction(SIGCONT, &act, NULL);

    printf("My pid : %d\n", myPid);
    pause(); // user-defined handler를 실행시키거나 process를 종료시키는 signal이 올때까지 정지됨
             // 만약 signal이 signal handler를 실행시키면 signal handler return 이후에 pause가 return 된다.
    // for(;;);
    printf("Hello~\n");
    return 0;
}