#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void func(int number){
    printf("Hello I'm SIGUSR1\n");
}

int main(){
    sigset_t newsigset, oldsigset;
    struct sigaction act;
    pid_t myPid = getpid();

    act.sa_handler = func;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);

    sigaction(SIGUSR1, &act, NULL);

    sigemptyset(&newsigset);
    sigaddset(&newsigset, SIGUSR1);

    printf("My PID : %d\n", myPid);
    
    // critical section start
    sigprocmask(SIG_BLOCK, &newsigset, &oldsigset);

    for(int i=0; i<10; i++){
        sleep(1);
    }
    sigprocmask(SIG_SETMASK, &oldsigset, NULL);
    // critical section end
    return 0;
}