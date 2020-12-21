#include<stdio.h>
#include<time.h>
#define MILLION 1000000L

int main(){
    struct timespec tpstart, tpend;
    double timediff;

    clock_gettime(CLOCK_REALTIME, &tpstart);
    for(int i=0; i<100000; i++);
    clock_gettime(CLOCK_REALTIME, &tpend);

    timediff = MILLION*(tpend.tv_sec- tpstart.tv_sec)+
                (tpend.tv_nsec-tpstart.tv_nsec)/1000; // 마이크로초로 맞추기 위해 곱함

    printf("%f\n", timediff);
    return 0;
}