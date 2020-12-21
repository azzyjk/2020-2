#include<stdio.h>
#include<pthread.h>

static int x=10, y=0;

int main(){
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER; // initialzed 하고 사용해야 한다.
                                                    // static으로 초기화 가능

    
    // pthread_cond_t cond;
    // pthread_cond_init(&cond, NULL); // 위와 결과는 같다.
    //                                 // 1번만 초기화 해야 한다.
    //                                 // 성공 : 0, 실패 : error code
    
    pthread_mutex_lock(&mutex);
    while(x!=y){
        pthread_cond_wait(&cond, &mutex); // mutex lock과 항상 같이 사용해야 한다.
    }
    pthread_mutex_unlock(&mutex);


    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond); // condition variable 삭제
                                 // 성공 : 0, 실패 : error code
                                 // 삭제된 후 참조, 다른 thread가 사용중일 때 삭제하는 행위는 정의되어 있지 않다.
    return 0;
}