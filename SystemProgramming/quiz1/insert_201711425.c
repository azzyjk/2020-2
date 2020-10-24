#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BOTH_FLAGS (O_RDWR)
#define ONELINECHAR 7
#define BUFSIZE 10

int readline(int fd, char *buf, int nbytes);

int main(int argc, char** argv){
    int lineNumber = atoi(argv[1]);
    char *test = argv[2];
    int fd;
    char buf[4][ONELINECHAR];
    char strar[5][ONELINECHAR];
    ssize_t bytesread;
    
    if(lineNumber>4){
        fprintf(stderr, "Input line number %d > actual number of lines 4\n", lineNumber);
        return 1;
    }

    fd = open("insert.txt", BOTH_FLAGS);

    lseek(fd, -1, SEEK_SET);
    write(fd, test, sizeof(test)-3);
    close(fd);
    return 0;
}