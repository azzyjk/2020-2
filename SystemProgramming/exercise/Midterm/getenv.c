#include<stdio.h>
#include<stdlib.h> // getenv function

int main(){
    char* env = "PWD";
    printf("%s\n",getenv(env)); // 없으면 NULL을 준다., ubuntu에서는 null이 아니라 segment fault가 뜬다.
    return 0;
}