#include<stdio.h>
#include<semaphore.h>
#include<sys/sem.h>
#include<fcntl.h>

void setsembuf(struct sembuf *s, int num, int op, int flg);

int main(){
    int semid;
    struct sembuf sops[3];
    int res=0;

    semid = semget(IPC_PRIVATE, 3, S_IRUSR|S_IWUSR);

    for(int i = 0; i<3; i++){
        setsembuf(&sops[i], i, i+3, 0);
    }

    semop(semid, sops, 3); // operation 적용

    for(int i = 0; i<3; i++){
        printf("%d번째 : %d\n", i, semctl(semid, i, GETVAL));
    }
    
    return 0;
}