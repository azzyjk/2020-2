#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char** argv){
	char* ptr = NULL;
	char* next[2];
	char delimiter[4];
	int now = 1;

	strcpy(delimiter, " \t"); // can write multiple element

	// check argc number
	if(argc != 3){
		printf("usage : ./test {string} {string}\n");
		return -1;
	}

	ptr = strtok_r(argv[1], delimiter, &next[0]); // strtok_r을 거치면 argvp[1]은 token의 첫번째만 남는다.
	printf("argv : %s, ptr : %s, next : %s\n", argv[1], ptr, next[0]);
	
	ptr = strtok_r(argv[2], delimiter, &next[1]); // next애 다음 ptr이 들어가서 기존 strtok_r에 영향을 주지 않음

	while((ptr = strtok_r(NULL, delimiter, &next[0])) != NULL){
		printf("argv : %s, %d : %s, next : %s\n", argv[0], ++now, ptr, next[1]);
	}
	
	return 0;
}
