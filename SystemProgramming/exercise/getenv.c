#include<stdio.h>
#include<stdlib.h> // getenv function

int main(){
    char* env = "PWD";
    printf("%s\n",getenv(env)); // 없으면 NULL을 준다.
    return 0;
}