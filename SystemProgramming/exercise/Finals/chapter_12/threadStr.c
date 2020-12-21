#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void* func(void* arg){
    char*buf;
    int param = *((int*)arg);
    int *res;

    res = (int*)malloc(sizeof(int));
    buf = (char*)calloc(20, sizeof(char));

    *res=1;

    printf("I get value %d\n", param);
    snprintf(buf, 20, "I'm thread\n");
    
    return buf;
}

int main(){
    pthread_t tid;
    int value = 20;
    char* str;
    int *res;

    pthread_create(&tid, NULL, func, (void*)&value);
    printf("I'm main I'm waiting for thread...\n");
    pthread_join(tid, (void**)&str);
    
    printf("%s", str);
    return 0;
}