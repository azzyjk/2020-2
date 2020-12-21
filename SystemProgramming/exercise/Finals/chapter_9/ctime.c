#include<stdio.h>
#include<time.h>

int main(){
    time_t now;
    now = time(NULL);
    printf("%s\n", ctime(&now)); // time_t *을 받고 문자열로 변환
    
    return 0;
}