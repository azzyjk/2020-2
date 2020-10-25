#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define WRITE_FLAGS (O_WRONLY | O_CREAT)
#define WRITE_PERMS (S_IRUSR | S_IWUSR)
#define BUF_SIZE 10

int main(){
    int fd;
    char buf[BUF_SIZE];

    strcpy(buf, "test\0");

    fd = open("test2.txt", WRITE_FLAGS, WRITE_PERMS);

    printf("%s\n", buf);
    dup2(fd, STDOUT_FILENO);
    write(STDOUT_FILENO, buf, BUF_SIZE);
    // printf("%s\n")
    return 0;
}