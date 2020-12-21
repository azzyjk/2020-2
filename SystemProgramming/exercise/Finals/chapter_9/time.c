#include<stdio.h>
#include<time.h>

int main(){
    time_t now;
    time(&now); // 현재 시간을 초로 알려준다.
                // NULL값이 아닌 time_t 변수가 들어있으면 저장해준다.
                // return으로도 값을 알려준다.
                
    printf("%ld\n", time(&now)); 
    printf("%ld\n", now);
    return 0;
}