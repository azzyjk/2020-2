#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char** argv){
	char* ptr = NULL;
	char* next = NULL;
	char delimiter[4];
	int now = 1;

	strcpy(delimiter, " \t"); // can write multiple element

	// check argc number
	if(argc != 2){
		printf("usage : ./test {string}\n");
		return -1;
	}

	ptr = strtok_r(argv[1], delimiter, &next); // strtok_r을 거치면 argvp[1]은 token의 첫번째만 남는다.
	printf("argv : %s, ptr : %s, next : %s\n", argv[1], ptr, next);
	
	while((ptr = strtok_r(NULL, delimiter, &next)) != NULL){
		printf("argv : %s, %d : %s, next : %s\n", argv[1], ++now, ptr, next);
	}
	
	return 0;
}
