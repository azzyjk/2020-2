#include<stdio.h>
#include<time.h>

int main(){
    char* buf;
    time_t now = time(NULL);

    // buf = asctime(localtime(&now)); // sturct tm 을 string으로 변환
                                       // localtime은 time_t pointer를 받고 sturct tm pointer로 반환
    buf = asctime(gmtime(&now)); 
    printf("%s", buf);
    return 0;
}