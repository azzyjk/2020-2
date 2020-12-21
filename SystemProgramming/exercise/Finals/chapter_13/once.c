#include<stdio.h>
#include<pthread.h>

static pthread_once_t once_control = PTHREAD_ONCE_INIT; // PTHREAD_ONCE_INIT으로 초기화 해줘야 한다.
                                                        // static 초기화만 가능하다.
static void printHello(void){
    printf("Hello~\n");
}

int execute_once(void){
    pthread_once(&once_control, printHello);
}

int main(){
    
    execute_once();
    execute_once();
    execute_once();
    execute_once();

    return 0;
}