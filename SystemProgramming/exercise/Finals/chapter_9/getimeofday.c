#include<stdio.h>
#include<sys/time.h>

int main(){
    struct timeval tval;
    char* buf;

    gettimeofday(&tval, NULL); // 2번쨰 인자는 timezone을 설정하는 것인데 NULL로 두도록 한다.
                               // 에러는 정의되어 있지 않음
                               // 성공 : 0
                               
    printf("%ld\n %ld\n", tval.tv_sec, tval.tv_usec);
    return 0;
}