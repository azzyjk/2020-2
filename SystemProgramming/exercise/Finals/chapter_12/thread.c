#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define RFLAG (O_RDONLY)
#define WPERM (S_IRUSR|S_IWUSR)
#define WFLAG (O_WRONLY | O_CREAT | O_EXCL)

#define BLKSIZE 255

// compile시 -pthread 붙여야 함

int readwrite(int fromfd, int tofd) {
   char buf[BLKSIZE];
   int bytesread;

   if ((bytesread = read(fromfd, buf, BLKSIZE)) < 0)
      return -1;
   if (bytesread == 0)
      return 0;
   if (write(tofd, buf, bytesread) < 0)
      return -1;
   return bytesread;
}

int copyfile(int fromfd, int tofd) {
   int bytesread;
   int totalbytes = 0;

   while ((bytesread = readwrite(fromfd, tofd)) > 0)
      totalbytes += bytesread;
   return totalbytes;
}

void *copyFile(void * arg){ // thread use
   int src, des, *res = 0;
    
   res = (int *)malloc(sizeof(int));

   src = *(int*)arg;
   des = *((int*)(arg)+1);

   *res = copyfile(src, des);

   printf("I'm thread %d %d\n", src, des);
   close(src);
   close(des);

   return res;
}

int main(int argc, char*argv[]){
   pthread_t *tid;
   int fds[2];
   int* returnval;

   fds[0] = open(argv[1], RFLAG);
   fds[1] = open(argv[2], WFLAG, WFLAG);

   printf("I'm file decriptor %d %d\n", fds[0], fds[1]);
   tid = (pthread_t *)calloc(1, sizeof(pthread_t));

   pthread_create(tid, NULL, copyFile, fds); // tid+i에 새로 만들어진 thread의 ID가 저장된다.

   pthread_join(tid[0], (void**)&returnval);

   printf("Return value : %d\n", *returnval);

   return 0;
}