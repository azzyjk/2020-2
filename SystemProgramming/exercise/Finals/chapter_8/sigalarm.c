#include<stdio.h>
#include<unistd.h>

int main(){
    int remain;
     alarm(1); // 프로그램이 멈추진 않는다.
               // 시간을 0으로 설정하면 이전 alram request가 취소된다.
               // default action은 시간이 지나면 프로세스 종료
               // return 값은 이전에 설정한 알람의 남은 시간
               // 알람이 설정되어 있지 않았을 경우 0 반환
               // error를 report 하지 않는다.
               
    remain = alarm(10); // 알람이 존재하는데 다시 호출하면 알람이 재설정 된다.
    printf("remain : %d\n", remain);

    for(;;){
        printf("Hello\n");
        sleep(1);
    }
    return 0;
}