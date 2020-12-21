#include<stdio.h>
#include<setjmp.h>
#include<unistd.h>
#include<signal.h> // sig_atomic_t가 들어있다.

static sigjmp_buf jmpbuf;
static volatile sig_atomic_t jmpok = 0;

void func(int number){
    if(!jmpok) return;
    else siglongjmp(jmpbuf, 1); // sigsetjmp로 이동하고 sigsetjmp가 1 return 하도록 함
                                // jmpbuf는 여러 지점 중 어디로 점프할지
}

int main(){
    struct sigaction act;

    act.sa_handler=func;
    act.sa_flags=0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);

    printf("My PID : %ld\n", (long)getpid());
    if(sigsetjmp(jmpbuf, 1)){
        printf("SIGUSR1 is coming!\n");
    }
    jmpok=1;
    for(;;);

    return 0;
}