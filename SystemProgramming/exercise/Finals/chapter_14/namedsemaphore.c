#include<stdio.h>
#include<semaphore.h>
#include<fcntl.h>

int main(){
    sem_t *sem;
    int val=0;

    // sem_unlink("/sem");
    sem = sem_open("/sem", O_CREAT, (S_IRUSR|S_IWUSR), 0); // 이름에 /가 붙어야함
                                                           // 삭제하지 않으면 모든 프로세스나 쓰레드 들이 종료되어도 남아있다.
    sem_getvalue(sem, &val);

    printf("sem : %d\n",val);

    sem_wait(sem);
    printf("Hello\n");
    sem_post(sem);

    sem_close(sem); // semaphore pointer를 넣어주면 된다. 삭제가 아닌 그만 사용하겠다는 의미
    sem_unlink("/sem"); // 이름을 넣어주면 된다. 삭제
    return 0;
}