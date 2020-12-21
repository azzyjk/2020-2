#include<stdio.h>
#include<unistd.h> //sleep()
#include<time.h> // nanosleep()

int main(){
    struct timespec ts, remaints;

    ts.tv_sec = 10;
    ts.tv_nsec = 200;
    // sleep(1); // unsigned seconds가 인자
                 //  시간이 모두 지나면 0
                 // interupt되면 남아있는 시간 반환

    nanosleep(&ts, &remaints); // struct timespec pointer 2개 전달
                          // 앞 인자는 시간 설정 뒤 인자는 interupt or 에러 발생시 남아있는 시간 전달
                          // 시간이 모두 지나서 끝나면 0 반환

    printf("%ld", remaints.tv_sec);
    return 0;
}