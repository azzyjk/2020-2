#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int a=3;
    pid_t childPid;
    int stat_loc;
    childPid = fork();// fork 를 호출 시 자식 프로세스는 부모 프로세스의 메모리를 복사해서 가지게 됨
    // 부모에겐 자식프로세스 pid가 자식에겐 0이 return 됨
    if(childPid==0) a =4; // 호출 이후 코드부터는 각자의 메모리를 사용하여 실행됨

    if(childPid==-1){ // fork를 실패한 경우
        perror("Can't fork process\n");
        return 1;
    }

    // sleep(1); // second 단위 sleep
    // usleep(100); // ms단위 sleep

    wait(&stat_loc);
    printf("%ld a : %d\n", (long)childPid, a);
    return 0;
}