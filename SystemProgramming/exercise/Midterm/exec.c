#include<stdio.h>
#include<unistd.h> // exec function
#include<string.h>

void makeAv(int argc, char** argv, char* delimiter, char*av[]){
    char* ptr;
    char* next;
    int now=0;

    ptr = strtok_r(argv[1], delimiter, &next);
    av[now] = ptr;
    while((ptr=strtok_r(NULL, delimiter, &next))!=NULL){
        now = now +1;
        av[now] = ptr;
    }
    av[now+1] = (char*)0;
}

int main(int argc, char** argv){
    char* env[] = {"PATH=./", (char*)0};
    // char *const av[]={"ls", "-l", (char*)0};
    char * av[10];
    char* ptr = NULL;
    char delim[4];
    int now =0;

    strcpy(delim, " \t");

    // execl("/bin/ls", "ls", "-l", (char*) 0); // (절대or상대 경로, 실행할 명령어 인자, Null)

    // execlp("ls","ls","-l", (char*)0); //(파일명, 실행할 명령어 인자, Null) 
    // 환경변수 PATH 모든 directory에 있는 프로그램을 실행함
    // /를 넣으면 execl과 똑같이 동작
    
    // printf("Hello\n");
    // execle("test", "test", (char*)0, env); //(절대or상대경로, 실행할 명령어 인자, Null, 환경변수 포인터 배열)
    // 환경변수를 넣었으므로 파일명만 입력해도 되는것 같다.
 
    // makeAv(argc, argv, delim, av);
    // execv("/bin/ls", av); //(절대or상대 경로, 실행할 명령어 인자가 들어있는 char *const 배열)

    // execvp("ls", av); // (파일명, 실행할 명령어 인자가 들어있는 char *const 배열)

    // printf("Hello\n");
    // execve("test", av, env); // (파일명, 실행할 명령어 인자가 들어있는 char *const 배열, 환경변수 포인터 배열)
    // for(int i=0; i<argc; i++){
    //     printf("%s\n", argv[i]);
    // }
    execvp(argv[1], &argv[1]); // argv[1] : "ls", &argv[1] : "ls"부터 시작하는 배열
    // *.c 와 같은 wild card 문자를 사용하면 *.c가아닌 자동으로 해당 directory의 파일들로 변경되어서 전달된다.
    // 단 "ls -l *.c"를 했을 경우 문자열 그대로 전달해준다.

    return 0;
}