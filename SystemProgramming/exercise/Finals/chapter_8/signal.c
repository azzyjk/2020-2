#include<stdio.h>
#include<signal.h>

int main(){
    sigset_t newsigset, oldsigset;

    sigaddset(&newsigset, SIGINT); // 시그널을 set에 추가
    // sigdelset(&newsigset, SIGINT); // 시그널을 set에서 삭제
    // sigemptyset(&newsigset);       // 초기화
    // sigfillset(&newsigset);        // 등록할 수 있는 모든 시그널 등록
                                      // 성공 : 0, 실패 : -1, errno 설정

    // sigismember(&newsigset, SIGINT); // signal이 set에 포함되는지 확인
                                        // 존재 : 1, 존재하지 않음 : 0
    
    sigprocmask(SIG_BLOCK, &newsigset, &oldsigset); // SIG_BLOCK : 추가, SIG_UNBLOCK : 삭제, SIG_SETMASK : 기존 시그널을 뺴고 새로 설정
                                                    // single thread에서만 사용 가능함
                                                    // pthread_sigmask()를 사용하면 multiple threads 환경에서도 사용 가능
                                                    // SIGSTOP, SIGKILL 시그널들은 block 시킬수 없다.
                                                    // ignore은 sigaction 사용
                                                    // 성공 : 0 실패 : -1, errno 설정



    return 0;
} 