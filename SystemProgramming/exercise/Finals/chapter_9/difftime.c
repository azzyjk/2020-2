#include<stdio.h>
#include<time.h>
#include<unistd.h>

int main(){
    double howDiff=0;
    time_t time1, time2;

    time(&time1);
    sleep(2);
    time(&time2);

    howDiff = difftime(time1, time2); // 앞에서 뒤에걸 뺸다
                                      // error는 정의되어 있지 않다.

    printf("diff : %f\n", howDiff);
    return 0;
}