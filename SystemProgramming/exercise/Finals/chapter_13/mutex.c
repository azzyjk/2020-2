#include<stdio.h>
#include<pthread.h>

static pthread_mutex_t mutex;

int main(){
    // pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;// 사용하기전에 initialized 해줘야 함
    pthread_mutex_init(&mutex, NULL); // 위와 같은 방식
                                      // 성공 : 0, 실패 : error code
                                      // 초기화는 1번만 해야 된다. 그 이상은 정의되어 있지 않다.
    
    pthread_mutex_lock(&mutex); // mutex를 사용할 수 있을때 까지 block 된다.
    // pthread_mutex_trylock(&mutex); // nonblocking 함수로 바로 반환함
    pthread_mutex_unlock(&mutex); // mutex를 반환한다.

    pthread_mutex_destroy(&mutex); // mutex 삭제
                                   // 성공 : 0, 실패 : error code
                                   // mutex가 삭제된뒤에 mutex를 참조하는 거에 대한 행위는 정의되어 있지 않다.
                                   // 다른 thread가 mutex lock을 사용하고 있을 때 다른 thread가 destory하는 행위는 정의되어 있지 않다.
    return 0;
}