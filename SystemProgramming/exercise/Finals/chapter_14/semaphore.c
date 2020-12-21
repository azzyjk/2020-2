#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>

sem_t sem;

void*func(){
    sem_wait(&sem);
    for(int i=0; i<5; i++){
        printf("I'm thread!!\n");
        sleep(1);
    }
    sem_post(&sem);
}

int main(){
    pid_t childpid;
    pthread_t tid;

    sem_init(&sem, 0, 1); // (semphore pointer, 공유 여부, 초기값)
    
    pthread_create(&tid, NULL, func, NULL);

    sem_wait(&sem);
    for(int i=0; i<5; i++){
        printf("I'm main!!\n");
        sleep(1);
    }
    sem_post(&sem);
    
    pthread_join(tid, NULL);

    sem_destroy(&sem);
    return 0;
}