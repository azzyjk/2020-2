#include<stdio.h>
#include<sys/sem.h> // semaphore ctl
#include<fcntl.h>
#include<unistd.h>

#define PEMRS (S_IRUSR|S_IWUSR)
#define KEY ((key_t)99887)

int main(){
    int semid;
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } arg;
    int res=0;

    arg.val = 3;

    // semid = semget(IPC_PRIVATE, 3, PEMRS); // 커널에서 키 값을 자동을 만들어 준다.
    semid = semget(KEY, 1 ,PEMRS|IPC_CREAT);

    semctl(semid, 0, SETVAL, arg);

    res = semctl(semid, 0, GETVAL); // get 관련된 CMD는 return값이 결과이다.
    printf("%d\n", res);

    semctl(semid, 0, IPC_RMID); // semaphore set 삭제
    return 0;
}