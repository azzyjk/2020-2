#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>

#define READ_FLAGS O_RDONLY
#define BOTH_FLAGS O_RDWR

#define WRITE_PERM ()

#define BUF_SIZE 3

int main(){
    int fd;
    char buf[BUF_SIZE];

    fd = open("test2.txt", BOTH_FLAGS);
    lseek(fd, 15, SEEK_CUR);
    printf("%d\n", fd);
    // read(fd, buf, BUF_SIZE);
    strcpy(buf, "hi");
    write(fd, buf, BUF_SIZE);
    // printf("%s\n", buf);
    return 0;
}