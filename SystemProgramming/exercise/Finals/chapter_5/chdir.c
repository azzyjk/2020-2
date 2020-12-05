#include<stdio.h>
#include<unistd.h>
#ifndef PATH_MAX
#define PATH_MAX 255
#endif

int main(int argc, char *argv[]){
    char buf[PATH_MAX]; 

    // chdir("/home/");
    chdir(argv[1]);
    getcwd(buf, PATH_MAX); // 버퍼의 크기가 부족하면 경로저장을 하지 않는다.
                            // \0까지 생각해서 크기를 잡아야 한다.

    printf("%s\n", buf);
    printf("size of PATH_MAX : %d\n", PATH_MAX);
    return 0;
}