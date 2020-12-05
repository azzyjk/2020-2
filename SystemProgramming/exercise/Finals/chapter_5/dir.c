#include<stdio.h>
#include<dirent.h>

int main(int argc, char *argv[]){
    struct dirent *direntp; // readdir을 사용해서 반환되는 타입, 다음 directory 정보를 가지고 있음
    DIR *dirp; // opendir를 사용해서 반환되는 타입, directory entries들이 들어있음

    dirp = opendir(argv[1]);

    while((direntp = readdir(dirp))!=NULL){ // DIR 포인터에서 파일 하나 하나를 읽어온다.
        printf("%s\n", direntp->d_name);
    }
    rewinddir(dirp); // DIR 포인터를 처음으로 이동시킨다.
    closedir(dirp);
    return 0;
}