#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int isReceive=0;

void func(int number){
    printf("number : %d\n", number);
    isReceive = 1;
}

int main(){
    sigset_t sigset, newmask, oldmask;
    struct sigaction act;
    pid_t myPid= getpid();

    sigfillset(&sigset);
    sigdelset(&sigset, SIGCONT);
    sigdelset(&sigset, SIGUSR1);

    sigfillset(&newmask);

    act.sa_flags=0;
    sigemptyset(&act.sa_mask);
    act.sa_handler = func;
    sigaction(SIGCONT, &act, NULL);
    sigaction(SIGURG, &act, NULL);

    printf("My pid : %d\n", myPid);
    
    // if문 확인과 sigsuspend사이에 signal이 들어올 수 있으므로 sigprocmask로 막고 suspend시켜준다.
    sigprocmask(SIG_SETMASK, &newmask, &oldmask);
    if(!isReceive){
        printf("I'm suspend now\n");
        sigsuspend(&sigset);
    }
    sigprocmask(SIG_SETMASK, &oldmask, NULL);
    // for(;;);
    return 0;
}