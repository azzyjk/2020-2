#include<stdio.h>
#include<unistd.h>
#define LEN 9

int main(){
    int fd[2];
    char buf[10];

    pipe(fd);
    write(fd[1], "testring!", sizeof(int));
    read(fd[0], buf, sizeof(int));    
    printf("%s\n", buf);
    return 0;
}