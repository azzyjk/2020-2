#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

#define LEN 10
#define FIFO_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(){
    pid_t childPid;
    char buf[LEN];
    int fd;

    mkfifo("myfifo", FIFO_PERMS);   

    childPid = fork();

    if(childPid){
        fd = open("myfifo", O_RDONLY);
        read(fd, buf, LEN); // buf 마지막에 \0이 들어가야 할 것 같다.
        printf("I'm parent : %s\n", buf);
    }
    else{
        fd = open("myfifo", O_WRONLY);
        snprintf(buf, LEN, "testing!!"); // snprintf는 자동으로 null character를 넣어준다.
        write(fd, buf, LEN); 
    }
    return 0;
}