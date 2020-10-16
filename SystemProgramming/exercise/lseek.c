#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

#define READ_FLAGS O_RDONLY
#define BUF_SIZE 3
int main(){
    int fd;
    char buf[BUF_SIZE];

    fd = open("test2.txt", READ_FLAGS);
    lseek(fd, 1, SEEK_CUR);
    printf("%d\n", fd);
    read(fd, buf, BUF_SIZE);
    printf("%s\n", buf);
    return 0;
}