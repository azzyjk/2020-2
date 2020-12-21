#include<stdio.h>
#include<string.h>

int main(){
    char buf[255];
    snprintf(buf, 255, "Hello");
    printf("%s, size : %ld\n",buf, strlen(buf)); //strlen을 이용하면 \0을 만나기 전까지의 char 개수만 반환해준다.
    return 0;
}