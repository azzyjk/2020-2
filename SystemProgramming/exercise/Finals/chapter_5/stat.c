#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main(){
    char *buf = "/home/2020-2/SystemProgramming/exercise/Finals/stat.c";
    struct stat statbuf;

    stat(buf, &statbuf); //stat(포인터, 포인터)
    printf("%s last access time\n", ctime(&statbuf.st_atime)); // ctime(포인터)
    printf("%d\n",statbuf.st_mode); // directory면 1 아니면 0 반환
    return 0;
}