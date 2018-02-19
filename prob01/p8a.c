#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[]){
  if(argc != 3){
    perror("usage: p8a n1 n2");
    strerror(1);
    exit(1);
  }
  unsigned int max = atoi(argv[1]);
  unsigned int endNum = atoi(argv[2]);
  if(endNum >= max){
    perror("usage: n1 > n2");
    strerror(1);
    exit(1);
  }
  unsigned int i = 0;
  unsigned int num;
  do{
    num = rand() % max;
    i++;
    printf("%d: %d\n",i,num);
  } while(num != endNum);
  return 0;
}
