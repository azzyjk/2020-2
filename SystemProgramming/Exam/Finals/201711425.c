#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<signal.h>

static pthread_t tid;  

void sighandler(){
    pthread_cancel(tid);
}

void* func(){
    int num = 0, sum=0;
    fprintf(stderr, "thread starts\n");

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    while(1){ 
        sleep(1);
        num = num + 1;
        sum = sum + num;
        fprintf(stderr, "%d ", num);
    }
    fprintf(stderr, "\nsum : %d\n", sum);
    pthread_testcancel();
}

int main(){
    pid_t pid = getpid();
    // pthread_t tid;  
    sigset_t sigset;
    struct sigaction act;

    act.sa_handler = sighandler;
    act.sa_flags=0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT, &act, NULL);

    //
    sigfillset(&sigset);
    sigdelset(&sigset, SIGINT);


    fprintf(stderr, "pid : %ld\n", (long)pid);
    pthread_create(&tid, NULL, func, NULL); // 쓰레드 생성
    sigsuspend(&sigset);
    
    pthread_join(tid, NULL);
    
    fprintf(stderr, "thread done\n");
    return 0;
}