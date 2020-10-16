#include<stdio.h>
#include<unistd.h> // close function, read function, write function
#include<sys/stat.h>
// #include<sys/type.h>
#include<fcntl.h> // open function

#define READ_FLAGS O_RDONLY
#define WRITE_FLAGS (O_WRONLY | O_CREAT | O_EXCL | O_APPEND) // EXCL은 file exist시 -1 반환
#define BOTH_FLAGS O_RDWR
#define WRITE_PERMS (S_IRUSR | S_IWUSR)
#define BUF_SIZE 2

int main(){
    int temp;
    int fd, fd2;
    char buf[BUF_SIZE], writeBuf[BUF_SIZE];
    ssize_t bytesread; 

    fd = open("test.txt", READ_FLAGS);
    fd2 = open("test2.txt", WRITE_FLAGS, WRITE_PERMS);

    bytesread = read(fd, buf, BUF_SIZE);
    printf("%s\n", buf);

    scanf("%s", writeBuf);
    write(fd2, writeBuf, sizeof(writeBuf));

    close(fd);
    close(fd2);
    return 0;
}