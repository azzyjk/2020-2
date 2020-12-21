#include<stdio.h>
#include<signal.h>

int main(){
    raise(9); // 자기 자신에게 보낸다.
    printf("Hello\n");
    return 0;
}