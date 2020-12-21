#include<stdio.h>
#include<signal.h>

int main(){
    kill(-1, 9); // 특정 PID : 특정 PID에게 전달
                 // 0 : 호출한 process group에게 전달
                 // -1 : 보낼수 있는 권한인 모든 process들에게 전달
                 // 다른 음수 값 : |PID|값과 동일한 그룹인 애들에게 보냄
                 // 성공 0 실패 -1
    return 0;
}