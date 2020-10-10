#include<stdio.h>
#include<string.h>
#include<unistd.h>

void strtokTest(char* charar, char* delimiter){
	strtok(charar, delimiter);
}

int main(int argc, char** argv){
	char* ptr = NULL;
	char delimiter[4];

	strcpy(delimiter, " \t"); // can write multiple element

	// check argc number
	if(argc != 3){
		printf("usage : ./test {string} {string}\n");
		return -1;
	}

	ptr = strtok(argv[1], delimiter); // strtok호출하면 argv[1]이 내부 정적변수에 들어감
	printf("argv : %s, ptr : %s\n", argv[1], ptr);
	
	strtokTest(argv[2], delimiter); // strtok를 호출하면 정적변수의 값이 바뀜

	while((ptr = strtok(NULL, delimiter)) != NULL){
		printf("ptr : %s\n", ptr); // 원하는 결과가 아닌 마지막에 strtok한 값으로 토큰화가 일어남
	}
	
	return 0;
}
