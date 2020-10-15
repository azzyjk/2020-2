#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main(){
    while(1){
        if(errno == EINTR) {
            printf("Have interupt\n");
            return -1;
        }
        printf("%s\n", (char*)stderror(EINTR));
        printf("1\n");
        sleep(1);
    }
    return 0;
}