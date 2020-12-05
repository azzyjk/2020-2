#include<stdio.h>
#include<unistd.h>

/*
shell 명령어로도 할 수 있다.
ln "존재하는 파일" "만들 링크 이름" (-s(소프트링크))
삭제시 rm명령어 이용
*/

int main(){
    char *path1 = "/home/2020-2/SystemProgramming/exercise/Finals/chapter_5/testing";
    char *path2 = "/home/2020-2/SystemProgramming/exercise/Finals/chapter_5/hello";
    char *path3 = "/home/2020-2/SystemProgramming/exercise/Finals/chapter_5/hi";

    link(path1, path2); //성공 : 0 실패 : -1 반환
    symlink(path1, path3);
    sleep(1);
    unlink(path2);
    unlink(path3);
    return 0;
}